#include "yaBackPack.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya {
	BackPack::BackPack()
		: mSpeed(1.0f)
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"BackPack", L"..\\Resources\\Image\\Object\\map_bg.bmp");
		}

		SetPos({ 400 , 180 });
		SetScale({ 3.0f, 3.0f });
		alpha = 200;
	}

	BackPack::~BackPack()
	{
	}

	void BackPack::Tick()
	{
		GameObject::Tick();
		//alpha -= 10 * Time::DeltaTime();
	}

	void BackPack::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		/*BitBlt(hdc , pos.x, pos.y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetDC(), 0, 0, SRCCOPY);*/

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x*2.4f;
		rect.y = mImage->GetHeight() * scale.y*1.4f;

		finalPos = Camera::CalculatePos(finalPos);



		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = alpha; // 0 - 225

		/*AlphaBlend(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, func);*/

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
		

		GameObject::Render(hdc);
	}
	void BackPack::OnCollisionEnter(Collider* other)
	{

	}

	void BackPack::OnCollisionStay(Collider* other)
	{
	}
	void BackPack::OnCollisionExit(Collider* other)
	{
	}
}
