#include "Mon2_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"

ya::Mon2_HPbar::Mon2_HPbar(eUIType type)
	:UIBase(type)
{

}

ya::Mon2_HPbar::~Mon2_HPbar()
{
}

void ya::Mon2_HPbar::OnInit()
{
}

void ya::Mon2_HPbar::OnActive()
{
}

void ya::Mon2_HPbar::OnInActive()
{
}

void ya::Mon2_HPbar::OnTick()
{
}

void ya::Mon2_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	Monster* mMonster = dynamic_cast<Monster*>(mTarget);
	int hp = mMonster->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon2_HPbar::OnClear()
{
}
