#include "Armor03.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"
ya::Armor03::Armor03(eUIType type)
	: UIItem(type)
{
	mOnClick = std::bind(&Armor03::Click, this);
	mXarrIndex = 2;
	mYarrIndex = 2;
}

ya::Armor03::~Armor03()
{
}

void ya::Armor03::OnInit()
{
}

void ya::Armor03::OnActive()
{
}

void ya::Armor03::OnInActive()
{
}

void ya::Armor03::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 5.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 5.0f)
	{
		mbMouseOn = true;
	}
	else
	{
		mbMouseOn = false;
	}

	if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
	{
		Sound* mbSound = Scene::mSound[3];
		if (Ani_Enable == false)
			mbSound->Play(false);

		mPrevClickPos = GetScreenPos();

		Vector2 mousePos = Input::GetMousePos();
		mPrevMousePos = mousePos;

		thisVariable = this;
		//UIItem::InventorieArr();

	}

	if (KEY_PREESE(eKeyCode::LBTN) && mbMouseOn)
	{
		if (thisVariable == this)
			mOnClick();

	}

	if (KEY_UP(eKeyCode::LBTN) && mbMouseOn)
	{
		Sound* mbSound = Scene::mSound[3];
		if (Ani_Enable == false)
			mbSound->Play(false);

		thisVariable = NULL;
		Vector2 pos = GetScreenPos();

		UIItem::InventorieArr(pos, mPrevClickPos);

		if (399.0f < pos.x && 1257.0f > pos.x
			&& 51.0f < pos.y && 441.0f > pos.y)
		{
			pos = CalculateIndexPos(pos);
			pos -= mParent->GetPos();
			SetPos(pos);

			//mOverlap = 0;
		}
		else
		{
			//인벤토리 바깥으로 벗어난다면 다시 원상복귀로 돌아가는 문법
			/*pos = mPrevClickPos;
			pos -= mParent->GetPos();
			SetPos(pos);*/
			//mOverlap = 0;
		}
	}
}

void ya::Armor03::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));

	HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	if (mRectEnable == true)
		Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		(int)mScreenPos.x + mImage->GetWidth() * 5.0f
		, (int)mScreenPos.y + mImage->GetHeight() * 5.0f);

	SelectObject(hdc, oldPen);
	DeleteObject(bluePen);
	SelectObject(hdc, oldBrush);
}

void ya::Armor03::OnClear()
{
}

void ya::Armor03::Click()
{
	Vector2 mousePos = Input::GetMousePos();

	// 마우스 드래그 이동
	if (mPrevMousePos.x != 0.0f && mPrevMousePos.y != 0.0f)
	{
		Vector2 pos = GetPos();

		//Vector2 idx = CalculateIndex(pos);

		Vector2 distance = mousePos - mPrevMousePos;
		pos.x += distance.x;
		pos.y += distance.y;


		//pos = CalculateIndexPos(pos);
		SetPos(pos);
	}

	mPrevMousePos = mousePos;
}
