#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"
#include "Chest.h"
#include "GameOver.h"
#include "GameClear.h"
#include "GameCamera.h"
#include "Stage.h"
#include "Player.h"

Game::Game()
{

}

Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_timer);
	DeleteGO(m_resultScore);
	DeleteGO(m_stage);
}

bool Game::Start()
{
	g_camera3D->SetPosition({ 0.0f, 100.0f, -600.0f });
	GameTransition();
	//“–‚½‚è”»’è
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	//d—Í‚ÌÝ’è
	PhysicsWorld::GetInstance()->SetGravity({ 0.0f,-2980.0f,0.0f });
	return true;
}

void Game::Update()
{

}

void Game::Render(RenderContext& rc)
{

}

void Game::GameTransition()
{
	switch (m_gameState)
	{
	case Game::enTitle:
		m_title = NewGO<Title>(0, "title");
		break;
	case Game::enStageSelect:
		m_gameState = enInGame;
		GameTransition();
		break;
	case Game::enInGame:
		m_resultScore = NewGO<Score>(0, "Score");
		m_timer = NewGO<Timer>(0, "timer");
		m_chest = NewGO<Chest>(0, "chest");
		m_player= NewGO<Player>(0, "player");
		m_stage = NewGO<Stage>(0, "stage");
		m_gamecamera = NewGO<GameCamera>(0,"gamecamera");
		break;
	case Game::enResult:
		DeleteGO(m_timer);
		DeleteGO(m_chest);
		m_gameClear = NewGO<GameClear>(0, "gameClear");
		break;
	case Game::enGameOver:
		DeleteGO(m_timer);
		DeleteGO(m_chest);
		m_gameOver = NewGO<GameOver>(0, "gameOver");
		break;
	default:
		break;
	}
}
