#include "chicken.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	chicken::chicken()
		:mHP(5)
	{
		SetName(L"chicken");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"chicken", L"..\\Resources\\Image\\Monster\\chicken.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	chicken::chicken(Vector2 position)
		:mHP(5)
	{
		SetName(L"chicken");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"chicken", L"..\\Resources\\Image\\Monster\\chicken.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	chicken::~chicken()
	{
	}
	void chicken::Tick()
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
	void chicken::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void chicken::OnCollisionEnter(Collider* other)
	{
	}
	void chicken::OnCollisionStay(Collider* other)
	{
	}
	void chicken::OnCollisionExit(Collider* other)
	{
	}
}
