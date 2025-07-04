#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"
#include "Flag.h"
#include "Mikan.h"
#include "TimeOver.h"
#include "GameOver.h"
#include "GameClear.h"
#include "GameCamera.h"
#include "Stage01.h"
#include "Stage02.h"
#include "Stage03.h"
#include "Stage04.h"
#include "Stage05.h"
#include "Player.h"
#include "IceFloor.h"
#include "Transform.h"
#include "Jakoten.h"
#include "SandFloor.h"
#include "Kiwi.h"
#include "CountDown.h"
#include "Describe.h"
#include "goal.h"

Game::Game()
{

}

Game::~Game()
{
	for (int mikan = 0;mikan < 30;mikan++) {
		DeleteGO(m_mikan[mikan]);
	}
	DeleteGO(m_flag);  
	DeleteGO(m_player);
	DeleteGO(m_gameCamera);
	DeleteGO(m_stage01);
	DeleteGO(m_stage02);
	DeleteGO(m_stage03);
	DeleteGO(m_stage04);
	DeleteGO(m_stage05);
	DeleteGO(m_iceFloor);
	DeleteGO(m_jakoten);
	DeleteGO(m_soundSource);
	DeleteGO(m_sandFloor);
	DeleteGO(m_kiwi);
	DeleteGO(m_countDown);
	DeleteGO(m_goal);
}

bool Game::Start()
{
	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	GameStateUpdate();
	switch (m_state)
	{
	case 1:
		Stage1();
		break;
	case 2:
		Stage2();
		break;
	case 3:
		Stage3();
		break;
	case 4:
		Stage4();
		break;
	case 5:
		Stage5();
		break;
	}

	//当たり判定
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	//重力の設定
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-1800.0f,0.0f });
	//BGM.
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/BGM.wav");
	m_soundSource = NewGO<SoundSource>(0);
	//ResistWaveFileBankで指定した番号。
	m_soundSource->Init(1);
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
}

void Game::Stage1()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage1Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage01 = NewGO<Stage01>(0, "stage01");
			m_stage01->GetTransform()->m_localPosition.Set(objData.position);
			m_stage01->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage01->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//フラッグ
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			m_flagPos = objData.position;
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
		//ゴール
		if (objData.EqualObjectName(L"goal") == true) {
			m_goal = NewGO<Goal>(1, "goal");
			m_goal->GetTransform()->m_localPosition.Set(objData.position);
			m_goal->GetTransform()->m_localRotation.Set(objData.rotation);
			m_goal->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
	});
}

void Game::Stage2()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage2Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage02 = NewGO<Stage02>(0, "stage02");
			m_stage02->GetTransform()->m_localPosition.Set(objData.position);
			m_stage02->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage02->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//フラッグ
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			m_flagPos = objData.position;
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
		//ゴール
		if (objData.EqualObjectName(L"goal") == true) {
			m_goal = NewGO<Goal>(1, "goal");
			m_goal->GetTransform()->m_localPosition.Set(objData.position);
			m_goal->GetTransform()->m_localRotation.Set(objData.rotation);
			m_goal->GetTransform()->m_localScale.Set(objData.scale);
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
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage03 = NewGO<Stage03>(0, "stage03");
			m_stage03->GetTransform()->m_localPosition.Set(objData.position);
			m_stage03->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage03->GetTransform()->m_localScale.Set(objData.scale);
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
		//フラッグ
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			m_flagPos = objData.position;
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
		//ゴール
		if (objData.EqualObjectName(L"goal") == true) {
			m_goal = NewGO<Goal>(1, "goal");
			m_goal->GetTransform()->m_localPosition.Set(objData.position);
			m_goal->GetTransform()->m_localRotation.Set(objData.rotation);
			m_goal->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
	});
}

void Game::Stage4()
{
	int mikan = 0;
	int bumper = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage4Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage04 = NewGO<Stage04>(0, "stage04");
			m_stage04->GetTransform()->m_localPosition.Set(objData.position);
			m_stage04->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage04->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//砂の床
		if (objData.EqualObjectName(L"sandfloor") == true) {
			m_sandFloor = NewGO<SandFloor>(1, "sandFloor");
			m_sandFloor->GetTransform()->m_localPosition.Set(objData.position);
			m_sandFloor->GetTransform()->m_localRotation.Set(objData.rotation);
			m_sandFloor->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//フラッグ
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			m_flagPos = objData.position;
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
		//キウイ
		if (objData.EqualObjectName(L"kiwi") == true) {
			m_kiwi = NewGO<Kiwi>(1, "kiwi");
			m_kiwi->GetTransform()->m_localPosition.Set(objData.position);
			m_kiwi->GetTransform()->m_localRotation.Set(objData.rotation);
			m_kiwi->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"goal") == true) {
			m_goal = NewGO<Goal>(1, "goal");
			m_goal->GetTransform()->m_localPosition.Set(objData.position);
			m_goal->GetTransform()->m_localRotation.Set(objData.rotation);
			m_goal->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
	});
}

void Game::Stage5()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage5Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage05 = NewGO<Stage05>(0, "stage05");
			m_stage05->GetTransform()->m_localPosition.Set(objData.position);
			m_stage05->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage05->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//フラッグ
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			m_flagPos = objData.position;
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
		//キウイ
		if (objData.EqualObjectName(L"kiwi") == true) {
			m_kiwi = NewGO<Kiwi>(1, "kiwi");
			m_kiwi->GetTransform()->m_localPosition.Set(objData.position);
			m_kiwi->GetTransform()->m_localRotation.Set(objData.rotation);
			m_kiwi->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//じゃこ天
		if (objData.EqualObjectName(L"jakoten") == true) {
			m_jakoten = NewGO<Jakoten>(1, "jakoten");
			m_jakoten->GetTransform()->m_localPosition.Set(objData.position);
			m_jakoten->GetTransform()->m_localRotation.Set(objData.rotation);
			m_jakoten->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"goal") == true) {
			m_goal = NewGO<Goal>(1, "goal");
			m_goal->GetTransform()->m_localPosition.Set(objData.position);
			m_goal->GetTransform()->m_localRotation.Set(objData.rotation);
			m_goal->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
	});
}

void Game::GameStateUpdate()
{
	m_countDown=NewGO<CountDown>(0,"countDown");
	m_score = NewGO<Score>(0, "score");
	m_timer = NewGO<Timer>(0, "timer");
	m_player = NewGO<Player>(0, "player");
	m_gameCamera = NewGO<GameCamera>(0, "gameCamera");
}
	
void Game::Render(RenderContext & rc)
{
	m_levelRender.Draw(rc);
}
