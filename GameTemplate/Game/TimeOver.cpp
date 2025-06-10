#include "stdafx.h"
#include "TimeOver.h"
#include "Title.h"
#include "Game.h"
#include "StageSelect.h"

TimeOver::TimeOver()
{

}

TimeOver::~TimeOver()
{

}

bool TimeOver::Start()
{
	//ゲームオーバーの画像を読み込む
	spriteRender.Init("Assets/sprite/TimeOver.dds", 1920.0f, 1080.0f);
	m_game = FindGO<Game>("game");
	return true;
}

void TimeOver::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる
		NewGO<StageSelect>(0, "stageSelect");
		//自身を削除する
		DeleteGO(this);
		DeleteGO(m_game);
	}
}

//描画処理
void TimeOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}