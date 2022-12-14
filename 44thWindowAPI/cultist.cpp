#include "cultist.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	cultist::cultist()
		:mHP(7)
	{
		SetName(L"cultist");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"cultist", L"..\\Resources\\Image\\Monster\\cultist.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	cultist::cultist(Vector2 position)
		:mHP(7)
	{
		SetName(L"cultist");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"cultist", L"..\\Resources\\Image\\Monster\\cultist.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	cultist::~cultist()
	{
	}
	void cultist::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Sound* mbSound = Scene::mSound[9];
			mbSound->Play(false);
			Death();
			UIManager::Pop(eUIType::heart04);

			UIBase::mMons_target_int++;
			UIBase::Mons_Remaining -= 1;

			Sound* mbSound12 = Scene::mSound[12];
			mbSound12->Stop(false);

			Sound* mbSound2 = Scene::mSound[2];
			mbSound2->Play(true);
		}
	}
	void cultist::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void cultist::OnCollisionEnter(Collider* other)
	{
	}
	void cultist::OnCollisionStay(Collider* other)
	{
	}
	void cultist::OnCollisionExit(Collider* other)
	{
	}
}