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
	DeleteGO(m_chest);
	DeleteGO(m_player);
	DeleteGO(m_gamecamera);
	DeleteGO(m_stage);
	DeleteGO(m_iceFloor);
	DeleteGO(m_mikan);
	DeleteGO(m_timer);
	DeleteGO(m_score);
}

bool Game::Start()
{
	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	GameStateUpdate();
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
		m_stage = NewGO<Stage>(0, "stage");
		m_iceFloor = NewGO<IceFloor>(0, "iceFloor");
		m_gamecamera = NewGO<GameCamera>(0, "gamecamera");
		m_mikan = NewGO<Mikan>(0, "mikan");
		m_mikan->m_position = { 400.0f,0.0f,-400.0f };
		m_mikan->m_firstPosition = m_mikan->m_position;
		m_chest = NewGO<Chest>(0, "chest");
		m_chest->m_position = { -450.0f,-70.0f,-1570.0f };
		m_chest->m_firstPosition = m_chest->m_position;
	}
}
	
void Game::Render(RenderContext & rc)
{

}
