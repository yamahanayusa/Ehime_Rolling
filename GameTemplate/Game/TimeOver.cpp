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
	DeleteGO(m_soundSource);
}

bool TimeOver::Start()
{
	//ゲームオーバーの画像を読み込む
	spriteRender.Init("Assets/sprite/TimeOver.dds", 1920.0f, 1080.0f);
	m_game = FindGO<Game>("game");

	//BGM.
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/BGM.wav");
	m_soundSource = NewGO<SoundSource>(0);
	//ResistWaveFileBankで指定した番号。
	m_soundSource->Init(0);
	//BGMは曲をループさせる。
	m_soundSource->Play(true);
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