#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
	//‰æ‘œ‚ğ“Ç‚İ‚Ş
	m_spriteRender.Init("Assets/sprite/Title.dds", 1920.0f, 1080.0f);
}

Title::~Title()
{

}

bool Title::Start()
{
	m_game = FindGO<Game>("game");

	return true;
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		m_game->m_gameState = m_game->enStageSelect;
		m_game->Newkansuu();
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	//‰æ‘œ‚ğ•`‰æ‚·‚éB
	m_spriteRender.Draw(rc);
}
