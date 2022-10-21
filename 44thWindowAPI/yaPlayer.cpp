#include "yaPlayer.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaScene.h"

//���⵵ �߰�
namespace ya {
	Player::Player()
		: mSpeed(1.0f)
	{
		//���� ���� �⺻��
		SetPos({ 100.0f, 100.0f });
		SetScale({ 100.0f, 100.0f });
	}
	Player::~Player()
	{
	}
	void Player::Tick()
	{
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
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

	}
}