#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

bool GameClear::Start()
{

	spriteRender.Init("Assets/sprite/GameClear.dds", 1920.0f, 1080.0f);
	m_game = FindGO<Game>("game");
	return true;
}

//更新処理
void GameClear::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる
		NewGO<Title>(0, "title");
		//自身を削除する
		DeleteGO(this);
		DeleteGO(m_game);
	}
}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
