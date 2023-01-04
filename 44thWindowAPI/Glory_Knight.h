

#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Glory_Knight : public GameObject
	{
	public:
		Glory_Knight();
		Glory_Knight(Vector2 position);
		~Glory_Knight();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void SetHp(int hp) { mHP = hp; }
		int GetHp() { return mHP; }
	private:
		int mHP;
		Image* mImage;
		AniMator* mAnimator;
	};
}