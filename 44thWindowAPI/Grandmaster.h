
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Grandmaster : public GameObject
	{
	public:
		Grandmaster();
		Grandmaster(Vector2 position);
		~Grandmaster();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		Image* mImage;
		AniMator* mAnimator;
	};
}