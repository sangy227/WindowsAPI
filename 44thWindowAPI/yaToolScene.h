#pragma once
#include "yaScene.h"
#include "yaTilePalette.h"


namespace ya {
	class Image;
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

		Image* GetAtalasImage() { return mTilePalette->GetAtlasImage(); }

		//추가

	private:
		TilePalette* mTilePalette;
		//여기 추가
	};
}


