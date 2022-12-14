#pragma once

#define KEY_PREESE(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP	


	enum class eSceneType
	{
		Logo,
		Title,
		PlayOne,
		PlayTwo,
		PlayThree,
		PlayFour,
		End,
		Tool,
		Max,
	};

	enum class ePenColor
	{
		Red,
		Green,
		Blue,
		End,

	};

	enum class eBrushColor
	{
		Transparent,//癱貲
		Black,
		Gray,//167,0,67
		White,
		End,

	};

	enum class eComponentType
	{
		Rigidbody,
		Collider,
		Animator,
		Sound,
		End,
		
	};

#define _COLLIDER_LAYER 16
	enum class eColliderLayer
	{
		Default,

		//gameobject
		BackGround,
		Tile,
		Player,
		Player_Projecttile,
		Monster,
		monster_ProjectTile,
		Ground,

		//ui
		BackPack,
		UI = _COLLIDER_LAYER-1,
		End = _COLLIDER_LAYER,

	};

	union ColliderID
	{
		
		struct 
		{
			UINT32 left;
			UINT32 right;
		};
		UINT64 ID;
	};
	typedef ColliderID TileID;

	enum class eCameraEffect
	{
		FadeIn,
		FadeOut,
		None,
	};

	enum class eUIType
	{
		LogoButton1,
		LogoButton2,
		LogoButton3,
		LogoButton4,
		LogoButton5,
		LogoButton6,

		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

		McIcon,
		ToteIcon,
		Cr8Icon,
		SetchelIcon,

		Mc_Info,
		Tote_Info,
		Cr8_Info,
		Setchel_Info,

		TitleDefault,
		TitleSelectBg,
		TitleSelectBg2,
		TitleSelectBg3,
		TitleSelectBg4,

		TitleSelectBg5,
		TitleSelectBg6,

		TitleSelectBg7,

		TitleSelectBg8,

		TitleSelectButton1,
		TitleSelectButton2,

		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

		TopLayerDefault,
		Book_Icon,
		Stats_Icon,
		Save_Icon,
		Option_Icon,
		Map_Icon,
		Back_Icon,

		Inventory2,
		Map_bg,
		Map_Gate,
		Enemie_icon01,
		Enemie_icon02,
		Enemie_icon03,
		Enemie_icon04,
		Enemie_icon05,
		Enemie_icon06,
		Enemie_icon07,
		Enemie_icon08,
		Enemie_icon09,
		Enemie_icon10,
		Enemie_icon_Boss,
		Ending_icon,
		Map_Player_icon,
		Enter_Button,

		TestButton,
		TestSword,

		Weapon01,
		Weapon02,
		Weapon03,
		Weapon04,
		Weapon05,

		Shield01,
		Shield02,
		Shield03,
		Shield04,
		Shield05,

		Jewelry01,
		Jewelry02,
		Jewelry03,

		Dagger01,
		Dagger02,
		Dagger03,
		Dagger04,
		Dagger05,

		Armor01,
		Armor02,
		Armor03,
		Armor04,
		Armor05,
		Armor06,

		Bow01,
		Bow02,
		Bow03,

		Arrow01,
		Arrow02,
		Arrow03,

		Potion01,
		Potion02,
		Potion03,
		Potion04,
		Potion05,
		Potion06,
		Potion07,
		Potion08,
		Potion09,
		Potion10,
		Potion11,
		Potion12,


		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

		heart01,
		heart02,
		heart03,
		heart04,
		block01,
		block02,
		block03,
		block04,


		Ending_Cheese,
		

		newenergy,
		target,
		HPbar,

		Mon1_HPbar,
		Mon2_HPbar,
		Mon3_HPbar,
		Mon4_HPbar,
		Mon5_HPbar,
		Mon6_HPbar,
		Mon7_HPbar,
		Mon8_HPbar,
		Mon9_HPbar,
		Mon10_HPbar,
		Mon11_HPbar,
		Mon12_HPbar,
		Mon13_HPbar,
		Mon14_HPbar,
		Mon15_HPbar,
		Mon_BOSS_HPbar,

		Number_0,
		Number_1,
		Number_2,
		Number_3,
		Number_4,
		Number_5,
		Number_6,
		Number_7,
		Number_8,
		Number_9,

		HP,
		MP,
		SHOP,
		INVENTORY,
		OPTION,

		END,
	};


#define TILE_SIZE 32
#define TILE_SCALE 2

#define TILE_LINE_X 8
#define TILE_LINE_Y 3