#pragma once
#include "yaComponent.h"

namespace ya {
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void AddForce(Vector2 force);
		void SetMass(float mass) { mMass = mass; }
	private:
		//���� �������� �̿��� �̵��� �߰�
		float mMass;
		float mFriction;
		
		Vector2 mForce;
		Vector2 mVelocity;
		Vector2 mAccelation;

		//�߷��� �̿��� ����
		Vector2 mGravity;
		bool mbGround;
		Vector2 mLimitVelocity;
	};
}

