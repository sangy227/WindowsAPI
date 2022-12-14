#include "Enemie_icon05.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "Map_Player_icon.h"
#include "yaGameObject.h"
#include "yaPlayer.h"
#include "yaScene.h"

ya::Enemie_icon05::Enemie_icon05(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Enemie_icon05::Click, this);
}

ya::Enemie_icon05::~Enemie_icon05()
{
}

void ya::Enemie_icon05::OnInit()
{
}

void ya::Enemie_icon05::OnActive()
{
}

void ya::Enemie_icon05::OnInActive()
{
}

void ya::Enemie_icon05::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 5.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 5.0f)
	{
		mbMouseOn = true;
	}
	else
	{
		mbMouseOn = false;
	}

	if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
	{
		mOnClick();
	}
}

void ya::Enemie_icon05::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Enemie_icon05::OnClear()
{
}

void ya::Enemie_icon05::Click()
{
	Map_Player_icon* playerUi = UIManager::GetUiInstant<Map_Player_icon>(eUIType::Map_Player_icon);


	Player* miniPlayer = Scene::player;
	miniPlayer->Player_Move();

	Vector2 enemie_icon = GetPos();
	playerUi->SetEnemiePos(enemie_icon.y);

	Map_Player_icon::map_ani_count = 1;

	mIconState = Player_Icon_Move::DOWN2;
	GameObject::mBgStatus = ya::GameObject::BgStatus::MOVE;
}
