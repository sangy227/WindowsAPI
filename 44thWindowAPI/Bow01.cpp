#include "Bow01.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "yaPlayer.h"
#include "yaScene.h"

ya::Bow01::Bow01(eUIType type)
	: UIItem(type)
{
	mOnClick = std::bind(&Bow01::Click, this);
	mXarrIndex = 2;
	mYarrIndex = 1;
}

ya::Bow01::~Bow01()
{
}

void ya::Bow01::OnInit()
{
}

void ya::Bow01::OnActive()
{
}

void ya::Bow01::OnInActive()
{
}

void ya::Bow01::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 4.5f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 3.0f)
	{
		mbMouseOn = true;
	}
	else
	{
		mbMouseOn = false;
	}

	if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
	{
		mPrevClickPos = GetScreenPos();

		Vector2 mousePos = Input::GetMousePos();
		mPrevMousePos = mousePos;
		thisVariable = this;
		//UIItem::InventorieArr();
		
		if (Ani_Enable) {
			Player* miniPlayer = Scene::player;
			miniPlayer->Player_BowAttack();

			mmNumber_count--;
			if (mmNumber_count <= 0) {
				mmNumber_count = 0;
				Ani_Enable = false;
			}

			newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
			mEnergy->Number_chenge();
		}
	}

	if (KEY_PREESE(eKeyCode::LBTN) && mbMouseOn)
	{
		if (thisVariable == this)
			mOnClick();

	}

	if (KEY_UP(eKeyCode::LBTN) && mbMouseOn)
	{
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
			//�κ��丮 �ٱ����� ����ٸ� �ٽ� ���󺹱ͷ� ���ư��� ����
			/*pos = mPrevClickPos;
			pos -= mParent->GetPos();
			SetPos(pos);*/
			//mOverlap = 0;
		}
	}
}

void ya::Bow01::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 4.5f, mImage->GetHeight() * 3.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));

	HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	if (mRectEnable == true)
		Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		(int)mScreenPos.x + mImage->GetWidth() * 4.5f
		, (int)mScreenPos.y + mImage->GetHeight() * 3.0f);

	SelectObject(hdc, oldPen);
	DeleteObject(bluePen);
	SelectObject(hdc, oldBrush);
}

void ya::Bow01::OnClear()
{
}

void ya::Bow01::Click()
{
	Vector2 mousePos = Input::GetMousePos();

	// ���콺 �巡�� �̵�
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
