#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"

GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

bool GameOver::Start()
{
	//繧ｲ繝ｼ繝繧ｪ繝ｼ繝舌・縺ｮ逕ｻ蜒上ｒ隱ｭ縺ｿ霎ｼ繧
	m_spriteRender.Init("Assets/sprite/Gameover.dds", 1920.0f, 1080.0f);
	//m_game = FindGO<Game>("game");
	return true;
}

void GameOver::Update()
{
	//A繝懊ち繝ｳ縺梧款縺輔ｌ縺溘ｉ
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//繧ｿ繧､繝医Ν縺ｮ繧ｪ繝悶ず繧ｧ繧ｯ繝医ｒ縺､縺上ｋ
		NewGO<Title>(0, "title");
		//閾ｪ霄ｫ繧貞炎髯､縺吶ｋ
		DeleteGO(this);
	}
}

//謠冗判蜃ｦ逅・
void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
