#pragma once
#include "Common.h"
namespace ya {
	class Image;
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);

		static Vector2 CalculatePos(Vector2 pos) 
		{ 
			//pos.x - mDistance.x;
			return pos - mDistance; // pos;
		}
		static void SetTarget(GameObject* target) { mTarget = target; }

		static void SetCameraEffect(eCameraEffect effect) { mEffect = effect; }
	private:
		Camera()=default;
		~Camera()=default;

	private:
		static Vector2 mResolution; // ȭ�� �ػ�
		static Vector2 mLookPosition;
		static Vector2 mDistance; // �ػ� �߽���ǥ�� ���� ī�޶��� ����
		static GameObject* mTarget;


		static eCameraEffect mEffect;
		static Image* mCutton; // ������ �̹���
		static float mAlphaTime;

		static float mCuttonAlpha;
		static float mEndTime;
	};
}

