#include "LogoButton2.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"
namespace ya {
	LogoButton2::LogoButton2(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton2::Click, this);
	}
	LogoButton2::~LogoButton2()
	{
	}
	void LogoButton2::OnInit()
	{
	}
	void LogoButton2::OnActive()
	{
	}
	void LogoButton2::OnInActive()
	{
	}
	void LogoButton2::OnTick()
	{
		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
		{
			mOnClick();
		}
	}
	void LogoButton2::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void LogoButton2::OnClear()
	{
	}
	void LogoButton2::Click()
	{
		Sound* mbSound = Scene::mSound[1];
		mbSound->Play(false);

		UIManager::Pop(eUIType::LogoButton1);
		UIManager::Pop(eUIType::LogoButton2);
		UIManager::Pop(eUIType::LogoButton3);
		UIManager::Pop(eUIType::LogoButton4);
		UIManager::Pop(eUIType::LogoButton5);
		UIManager::Pop(eUIType::LogoButton6);

		UIManager::Push(eUIType::TitleDefault);
		UIManager::Push(eUIType::Mc_Info);
	}
}