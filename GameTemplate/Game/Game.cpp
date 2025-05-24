#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"
#include "Chest.h"
#include "Mikan.h"
#include "TimeOver.h"
#include "GameOver.h"
#include "GameClear.h"
#include "GameCamera.h"
#include "Stage.h"
#include "Player.h"
#include "IceFloor.h"
#include "Transform.h"
#include "Jakoten.h"
#include "Bumper.h"
#include "sandFloor.h"
#include "Kiwi.h"

Game::Game()
{

}

Game::~Game()
{
	for (int mikan = 0;mikan < 2;mikan++) {
		DeleteGO(m_mikan[mikan]);
	}
	DeleteGO(m_chest);  
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(m_stage);
	DeleteGO(m_iceFloor);
	//DeleteGO(m_mikan);
	DeleteGO(m_jakoten);
	DeleteGO(m_soundSource);
	DeleteGO(m_bumper);
	DeleteGO(m_sandFloor);
	DeleteGO(m_kiwi);
	/*DeleteGO(m_timer);
	DeleteGO(m_score);*/
}

bool Game::Start()
{
	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	GameStateUpdate();
	Stage1();
	//Stage3();
	//当たり判定
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	//重力の設定
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-2000.0f,0.0f });
	//BGM.
	//g_soundEngine->ResistWaveFileBank(0, "Assets/sound/BGM.wav");
	m_soundSource = NewGO<SoundSource>(0);
	//ResistWaveFileBankで指定した番号。
	m_soundSource->Init(0);
	//BGMは曲をループさせる。
	m_soundSource->Play(true);
	FindGO<Player>("player");

	return true;
}

void Game::Update()
{
	if (m_timer->GetTime() <= 0)
	{
		NewGO<TimeOver>(0, "timeOver");
		DeleteGO(m_timer);
		DeleteGO(m_score);
		DeleteGO(this);
	}
	if (m_player->rbPos.y <= -3000.0f)
	{
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(m_timer);
		DeleteGO(m_score);
		DeleteGO(this);
	}

	////Aボタンが押されたら。
	//if (g_pad[0]->IsTrigger(enButtonA))
	//{
	//	//BGMが再生中なら。
	//	if (m_soundSource->IsPlaying())
	//	{
	//		//停止させる。
	//		m_soundSource->Stop();
	//	}
	//	//停止中なら。
	//	else
	//	{
	//		m_soundSource->Play(true);
	//	}
	//}
}

void Game::Stage1()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage1Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"stage1") == true) {
			m_stage = NewGO<Stage>(0, "stage");
			m_stage->GetTransform()->m_localPosition.Set(objData.position);
			m_stage->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"flag") == true) {
			m_chest = NewGO<Chest>(1, "chest");
			m_chest->GetTransform()->m_localPosition.Set(objData.position);
			m_chest->GetTransform()->m_localRotation.Set(objData.rotation);
			m_chest->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//アイテム(みかん)
		if (objData.EqualObjectName(L"mikan") == true) {
			m_mikan[mikan] = NewGO<Mikan>(1, "mikan");
			m_mikan[mikan]->GetTransform()->m_localPosition.Set(objData.position);
			m_mikan[mikan]->GetTransform()->m_localRotation.Set(objData.rotation);
			m_mikan[mikan]->GetTransform()->m_localScale.Set(objData.scale);
			mikan++;
			return true;
		}
		});
}


void Game::Stage3()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage3Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"stage") == true) {
			m_stage = NewGO<Stage>(0, "stage");
			m_stage->GetTransform()->m_localPosition.Set(objData.position);
			m_stage->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//氷の床
		if (objData.EqualObjectName(L"icefloor") == true) {
			m_iceFloor = NewGO<IceFloor>(1, "iceFloor");
			m_iceFloor->GetTransform()->m_localPosition.Set(objData.position);
			m_iceFloor->GetTransform()->m_localRotation.Set(objData.rotation);
			m_iceFloor->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"flag") == true) {
			m_chest = NewGO<Chest>(1, "chest");
			m_chest->GetTransform()->m_localPosition.Set(objData.position);
			m_chest->GetTransform()->m_localRotation.Set(objData.rotation);
			m_chest->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//アイテム(みかん)
		if (objData.EqualObjectName(L"mikan") == true) {
			m_mikan[mikan] = NewGO<Mikan>(1, "mikan");
			m_mikan[mikan]->GetTransform()->m_localPosition.Set(objData.position);
			m_mikan[mikan]->GetTransform()->m_localRotation.Set(objData.rotation);
			m_mikan[mikan]->GetTransform()->m_localScale.Set(objData.scale);
			mikan++;
			return true;
		}
	});
}

void Game::GameStateUpdate()
{
	m_gameState = enInGame;

	if (enStageSelect)
	{
		
	}

	if (enInGame)
	{
		m_score = NewGO<Score>(0, "score");
		m_timer = NewGO<Timer>(0, "timer");
		m_player = NewGO<Player>(0, "player");
		//m_soundSource = NewGO<SoundSource>(0,"soundSource");

	/*	m_stage = NewGO<Stage>(0, "stage");
		m_iceFloor = NewGO<IceFloor>(0, "iceFloor");*/
		/*m_gamecamera = NewGO<GameCamera>(0, "gameCamera");*/

	/*	m_mikan = NewGO<Mikan>(0, "mikan");*/
		/*m_mikan->m_position = { 400.0f,0.0f,-400.0f };
		m_mikan->m_firstPosition = m_mikan->m_position;*/

		//m_chest = NewGO<Chest>(0, "chest");
		//m_chest->m_position = { 400.0f,0.0f,-500.0f };
		////m_chest->m_firstPosition = m_chest->m_position;
		////m_chest->m_position = { -450.0f,-70.0f,-1570.0f };
		////m_chest->m_firstPosition = m_chest->m_position;

		//じゃこ天。
		//m_jakoten = NewGO<Jakoten>(0, "Jakoten");
		//m_jakoten->SetPos({ 400.0f, 0.0f, -300.0f });
    
		m_gameCamera = NewGO<GameCamera>(0, "gameCamera");

		//m_bumper = NewGO<Bumper>(0, "bumper");
		//m_bumper->SetPos({ 0.0f,0.0f,0.0f });

		/*m_kiwi = NewGO<Kiwi>(0, "Kiwi");
		m_kiwi->SetPos({ 600.0f,0.0f,-300.0f });*/
	}
}
	
void Game::Render(RenderContext & rc)
{
	m_levelRender.Draw(rc);
}
