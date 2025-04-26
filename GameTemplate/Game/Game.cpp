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

Game::Game()
{

}

Game::~Game()
{
	for (int mikan = 0;mikan < 4;mikan++) {
		DeleteGO(m_mikan[mikan]);
	}
	DeleteGO(m_chest);
	DeleteGO(m_gamecamera);
	DeleteGO(m_stage);
	DeleteGO(m_iceFloor);
	DeleteGO(m_player);
	DeleteGO(m_timer);
	DeleteGO(m_score);
}

bool Game::Start()
{
	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	GameStateUpdate();
	Stage3();
	//当たり判定
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	//重力の設定
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-2000.0f,0.0f });
	FindGO<Player>("player");

	return true;
}

void Game::Update()
{
	if (m_timer->m_timer <= 0)
	{
		NewGO<TimeOver>(0, "timeOver");
		DeleteGO(this);
	}
	if (m_player->rbPos.y <= -3000.0f)
	{
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
	}
}

void Game::Stage3()
{
	int mikan = 0;
	//レベルの構築
	m_levelRender.Init("Assets/level3D/stage3Level.tkl", [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"stage") == true) {
			m_stage = NewGO<Stage>(0, "stage");
			m_stage->SetPosition(objData.position);
			m_stage->SetRotation(objData.rotation);
			m_stage->SetScale(objData.scale);
			return true;
		}
		//氷の床
		if (objData.EqualObjectName(L"iceFloor") == true) {
			m_iceFloor = NewGO<IceFloor>(0, "iceFloor");
			m_iceFloor->SetPosition(objData.position);
			m_iceFloor->SetRotation(objData.rotation);
			m_iceFloor->SetScale(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"chest") == true) {
			m_chest = NewGO<Chest>(0, "chest");
			m_chest->SetPosition(objData.position);
			m_chest->SetRotation(objData.rotation);
			m_chest->SetScale(objData.scale);
			return true;
		}
		//アイテム(みかん)
		if (objData.EqualObjectName(L"mikan") == true) {
			m_mikan[mikan] = NewGO<Mikan>(0, "mikan");
			m_mikan[mikan]->SetPosition(objData.position);
			m_mikan[mikan]->SetRotation(objData.rotation);
			m_mikan[mikan]->SetScale(objData.scale);
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
		m_gamecamera = NewGO<GameCamera>(0, "gameCamera");
	}
}
	
void Game::Render(RenderContext & rc)
{
	m_levelRender.Draw(rc);
}
