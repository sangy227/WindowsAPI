

#pragma once

#include "UIItem.h"
namespace ya {
	class Sword;
	class Enter_Button : public UIItem
	{
	public:
		Enter_Button(eUIType type);
		~Enter_Button();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
		
	private:
		Event mOnClick;
		bool mbMouseOn;
		Sword* abcTarget;
	};
}
