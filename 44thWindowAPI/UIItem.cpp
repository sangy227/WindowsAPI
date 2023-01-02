#include "UIItem.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "Common.h"
#include "newenergy.h"

namespace ya {
	std::vector<std::vector<UIItem*>> UIItem::mInventories;
	UINT UIItem::mOverlap;
	UIItem* UIItem::thisVariable;
	

	UIItem::UIItem(eUIType type)
		:UIBase(type)
		,mbinstail(false)
		//, count(0)
	{
		//mOnClick = std::bind(&UIItem::Click, this);
		//mPrevPos = GetScreenPos();
		mOverlap = 0;
		mInventories.resize(row);
		for (size_t i = 0; i < row; i++)
			mInventories[i].resize(coulmn);

		//count = newenergy::GetNumber_Count();
		

	}
	UIItem::~UIItem()
	{
	}
	void UIItem::OnInit()
	{
		
	}
	void UIItem::OnActive()
	{
	}
	void UIItem::OnInActive()
	{
	}
	void UIItem::OnTick()
	{
		
	}
	void UIItem::OnRender(HDC hdc)
	{
		
	}
	void UIItem::OnClear()
	{
	}
	void UIItem::Click()
	{

	}

	void UIItem::InventorieArr(Vector2 mPos, Vector2 mPrevClickPos)
	{

		Vector2 Index = this->CalculateIndex(this->GetPos() + mParent->GetPos());
		bool out = false;
		if (Index.x >= 11 && Index.y >= 5)
		{
			out = true;
			//mPos = mPrevClickPos;
			//mPos -= mParent->GetPos();
			//SetPos(mPos);
			return;
		}
		//��ü �迭�� �� ���鼭 �ִ��� Ȯ��
		//this�� ������ �κ��丮�ȿ��� �ڸ� �̵� �Ѱɷ� Ȯ�� ����
		for (UINT y = 0; y < 5; y++)
		{
			for (UINT x = 0; x < 11; x++)
			{
				/* �κ��丮 �ٱ��� ���ϱ� ������*/
				/* �κ��丮 �ٱ��� ���ϱ� ������*/
				/* �κ��丮 �ٱ��� ���ϱ� ������*/

				//�̰Ŵ� �ڸ��̵� �ѵ� , �����ִ��ڸ��� NULL�����
				if (mInventories[y][x] == this)
				{
					mInventories[y][x] = NULL;
				}
				
				//�̰Ŵ� �ڸ��̵� �Ѱ��� �̹� �ٸ��� ������ �ٽ� ���ư���
				// �̰ſ� �ȵɱ�
				//�迭�� �Ѿ�� ����ó�� ������
				if (!(mInventories[Index.y][Index.x] == NULL))
				{
					mPos = mPrevClickPos;
					mPos -= mParent->GetPos();
					SetPos(mPos);
				}
			}
		}
		//���ο� �ڸ��� �迭 this �� ����ֱ�

		
		if (Index.y + mYarrIndex <= 4 && Index.x + mXarrIndex <=10)
		{
			for (UINT y = 0; y < this->mYarrIndex; y++)
			{
				for (UINT x = 0; x < this->mXarrIndex; x++)
				{
					/*if (Index.x + x >= 11 && Index.y+y >= 5)
					{
						return;
					}*/
					mInventories[Index.y + y][Index.x + x] = this;
					this->mbinstail = true;

					//������ bool������ ���� �Ӵ� ���� �ع�����
				}
			}
		}

	}

	

	Vector2 UIItem::CalculateIndex(Vector2 pos)
	{
		float width = 399.0f;
		float hegiht = 51.0f;

		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 77.0f * (x)+width;
				indexPos.y = 77.0f * (y)+hegiht;

				if (indexPos.x < pos.x && indexPos.x + 77.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 77.0f > pos.y)
				{
					
					

					return Vector2(x, y);
				}
			}
		}

		//return Vector2(-1.0f, -1.0f);
		return mPrevClickPos;

	}

	Vector2 UIItem::CalculateIndexPos(Vector2 pos)
	{
		float width = 399.0f;
		float hegiht = 51.0f;

		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 77.0f * (x)+width;
				indexPos.y = 77.0f * (y)+hegiht;

				if (indexPos.x < pos.x && indexPos.x + 77.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 77.0f > pos.y)
				{
					return Vector2(indexPos);
				}
			}
		}



		//return Vector2(-1.0f, -1.0f);
		return mPrevClickPos;

	}
}