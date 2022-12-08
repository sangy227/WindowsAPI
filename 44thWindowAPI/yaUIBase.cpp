#include "yaUIBase.h"
#include "yaResources.h"
#include "yaImage.h"
#include "yaAniMator.h"
#include "yaGameObject.h"

namespace ya {
	UIBase::UIBase(eUIType type)
		: mType(type)
		, mbFullScreen(false)
		, mbEnable(false)
		, mParent(nullptr)
		, mPos(Vector2::Zero)
		, mSize(Vector2::Zero)
		, mAniMator(nullptr)
		/*, mRectObject(nullptr)*/
	{
		//mRectObject = new GameObject();
	}
	UIBase::~UIBase()
	{
	}

	void UIBase::Initialize()
	{
		OnInit();

		for (UIBase* child : mChilds)
		{
			child->Initialize();
		}
	}
	void UIBase::Active()
	{
		mbEnable = true;
		OnActive();

		for (UIBase* child : mChilds)
		{
			//child->mbEnable = true;
			child->Active();
		}
	}
	void UIBase::InActive()
	{
		for (UIBase* child : mChilds)
		{
			child->InActive();
			child->mbEnable = false;
		}
		OnInActive();
		mbEnable = false;
	}
	void UIBase::Tick()
	{
		if (mbEnable == false)
			return;

		/*mRectObject->SetPos(GetPos());
		mRectObject->SetScale(GetSize());

		if (mAniMator)
			mAniMator->Tick();*/
		OnTick();

		if (mParent)
			mScreenPos = mParent->GetPos() + mPos;
		else
			mScreenPos = mPos;


		for (UIBase* child : mChilds)
		{
			if (child->mbEnable)
			{
				child->Tick();
			}
		}

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Tick();
		}
	}
	void UIBase::Render(HDC hdc)
	{
		if (mbEnable == false)
			return;

		/*if (mAniMator)
			mAniMator->Render(hdc);
		*/
		OnRender(hdc);
		for (UIBase* child : mChilds)
		{
			if (child->mbEnable)
			{
				child->Render(hdc);
			}
		}


		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}
	void UIBase::UIClear()
	{
		for (UIBase* child : mChilds)
		{
			//if (child->mbEnable)
			child->OnClear();
		}
		OnClear();
	}
	void UIBase::ImageLoad(const std::wstring& key,const std::wstring& path)
	{
		mImage = Resources::Load<Image>(key, path);

		SetSize(Vector2(mImage->GetWidth(), mImage->GetHeight()));
	}
	void UIBase::AddChild(UIBase* uiBase)
	{
		mChilds.push_back(uiBase);
		uiBase->mParent = this;
	}
	void UIBase::AddGameObject(GameObject* gameObj)
	{
		if (gameObj == nullptr)
			return;

		mGameObjects.push_back(gameObj);
	}
}