#include "yaAniMator.h"
#include "yaGameObject.h"
#include "yaImage.h"
#include "yaCamera.h"
#include "yaResources.h"

namespace ya {
	AniMator::AniMator()
		:Component(eComponentType::Aimator)
		,mPlayAnimation(nullptr)
		,mLoop(false)
	{
		//mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");

	}
	AniMator::~AniMator()
	{

	}
	void AniMator::Tick()
	{

	}
	void AniMator::Render(HDC hdc)
	{
		if (mPlayAnimation != nullptr)
		{
			mPlayAnimation->Render(hdc);
		}

	}
	Animation* AniMator::FindAnimation(const std::wstring& name)
	{
		std::map<const std::wstring&, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
		{
			return nullptr;
		}
		return iter->second;
	}
	void AniMator::CreateAnimation(const std::wstring& name, Image* image
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, float columnLength, UINT spriteLegth, float duration, bool bAffectedCamera = false)
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			MessageBox(nullptr, L"�ߺ� Ű �ִϸ��̼� ����", L"�ִϸ��̼� ���� ����!", MB_OK);
			return;
		}

		
		animation = new Animation();
		animation->Create(image, leftTop, size, offset, columnLength, spriteLegth, duration, bAffectedCamera);
		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}
	void AniMator::Play(std::wstring& name, bool bloop = false)
	{
	}
}