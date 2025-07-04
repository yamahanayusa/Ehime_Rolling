#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"
#include "StageSelect.h"

GameOver::GameOver()
{

}

GameOver::~GameOver()
{
	DeleteGO(m_soundSource);
}

bool GameOver::Start()
{
	//ゲームオーバーの画像を読み込む
	m_spriteRender.Init("Assets/sprite/Gameover.dds", 1920.0f, 1080.0f);

	//BGM.
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/gameover.wav");
	m_soundSource = NewGO<SoundSource>(0);
	//ResistWaveFileBankで指定した番号。
	m_soundSource->Init(2);
	//BGMは曲をループさせる。
	m_soundSource->Play(true);
	return true;
}

void GameOver::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトをつくる
		NewGO<StageSelect>(0, "stageSelect");
		//自身を削除する
		DeleteGO(this);
	}
}

//描画処理
void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
