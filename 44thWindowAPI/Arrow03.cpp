#include "Arrow03.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaCamera.h"
ya::Arrow03::Arrow03(eUIType type)
	: UIItem(type)
{
	mOnClick = std::bind(&Arrow03::Click, this);
	mXarrIndex = 2;
	mYarrIndex = 1;
}

ya::Arrow03::~Arrow03()
{
}

void ya::Arrow03::OnInit()
{
}

void ya::Arrow03::OnActive()
{
}

void ya::Arrow03::OnInActive()
{
}

void ya::Arrow03::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 4.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 3.5f)
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

void ya::Arrow03::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 4.0f, mImage->GetHeight() * 3.5f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));

	HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		(int)mScreenPos.x + mImage->GetWidth() * 4.0f
		, (int)mScreenPos.y + mImage->GetHeight() * 3.5f);

	SelectObject(hdc, oldPen);
	DeleteObject(bluePen);
	SelectObject(hdc, oldBrush);
}

void ya::Arrow03::OnClear()
{
}

void ya::Arrow03::Click()
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
