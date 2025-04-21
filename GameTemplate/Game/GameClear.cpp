#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"
#include "Score.h"
#include "Chest.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

bool GameClear::Start()
{
	m_score = FindGO<Score>("Score");
	m_chest = FindGO<Chest>("chest");
	m_spriteRender.Init("Assets/sprite/GameClear.dds", 1920.0f, 1080.0f);
	//m_game = FindGO<Game>("game");
	return true;
}

//更新処理
void GameClear::Update()
{
	TortalScore();
	m_spriteRender.Update();
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
	}
}

void GameClear::TortalScore()
{
	wchar_t scorew[256];
	swprintf_s(scorew, 256, L"%d点", int(m_chest->m_tortalScore));
	m_fontRender.SetText(scorew);
	m_fontRender.SetPosition({ 200.0f, 100.0f, 0.0f });
	m_fontRender.SetScale(5.0);
	m_fontRender.SetColor(g_vec4Black);
}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}
