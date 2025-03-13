#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
	//‰æ‘œ‚ğ“Ç‚İ‚Ş
	spriteRender.Init("Assets/sprite/Gamestart.dds", 1920.0f, 1080.0f);
}

Title::~Title()
{

}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			NewGO<Game>(0, "game");
			DeleteGO(this);
			DeleteGO(m_game);
		}
	}
}

void Title::Render(RenderContext& rc)
{
	//‰æ‘œ‚ğ•`‰æ‚·‚éB
	spriteRender.Draw(rc);
}
