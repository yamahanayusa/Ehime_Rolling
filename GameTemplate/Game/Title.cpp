#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Score.h"
#include "StageSelect.h"

Title::Title()
{
	//画像を読み込む
	m_spriteRender.Init("Assets/sprite/Title.dds", 1920.0f, 1080.0f);
}

Title::~Title()
{

}

bool Title::Start()
{
	return true;
}

void Title::Update()
{

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		m_stageSelect = NewGO<StageSelect>(0, "stageSelect");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	//画像を描画する。
	m_spriteRender.Draw(rc);
}
