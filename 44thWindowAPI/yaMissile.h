#pragma once
#include "yaGameObject.h"

namespace ya {
	class Image;
	class Missile : public GameObject
	{
	public:
		Missile();
		~Missile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;
		
	private:
		float mSpeed;
		float mAliveTime;
		Image* mImage;

	public:
		Vector2 mDir;
		Vector2 mDestPos;

	};

}

