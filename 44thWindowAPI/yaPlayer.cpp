#include "yaPlayer.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"


//���⵵ �߰�
namespace ya 
{
	Player::Player()
		: mSpeed(1.0f)
	{
		//���� ���� �⺻��
		SetPos({ 350.0f, 700.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");

		}

		AddComponent(new AniMator());
		AddComponent(new Collider());

	}
	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();


		//Ű���� �Է�
		Vector2 pos = GetPos();
		if (KEY_PREESE(eKeyCode::W))
		{
			pos.y -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::S))
		{
			pos.y += 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::A))
		{
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::D))
		{
			pos.x += 120.0f * Time::DeltaTime();
		}

		if (KEY_DOWN(eKeyCode::SPACE)) {
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetplayScene();
			playScene->AddGameObject(missile);

			Vector2 playerPos = GetPos();
			Vector2 playerScale = GetScale() / 2.0f;

			Vector2 missileScale = missile->GetScale();

			missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
		}
		//������ Pos�� �ٽ� ����
		SetPos(pos);

		


	}
	void Player::Render(HDC hdc)
	{
		//�Ʒ� �ּ� ��ü�� common���Ͽ� �߰���
		HBRUSH blueBrush = CreateSolidBrush(RGB(153,204,255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		//(HBRUSH)SelectObject(hdc, oldBrush);
		//DeleteObject(oldBrush);
		Brush brush(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		Pen pen(hdc, redPen);

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		//Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

		//�̹����� ����� �Ȱ��� �ε��Ҽ��ְ�
		
		//ũ�⺯���� �ȵȴ�.
		/*BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(),mImage->GetHeight(),
			mImage->GetDC(),0,0,SRCCOPY);*/

		
		//���� ����
		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		//�׸���
		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
		
	}
}