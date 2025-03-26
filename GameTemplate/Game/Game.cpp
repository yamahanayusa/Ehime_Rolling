#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"
#include "Player.h"
#include "Stage01.h"
#include "GameCamera.h"

bool Game::Start()
{



	m_player = NewGO<Player>(0, "player");
	//カメラのオブジェクトを作成する。
	m_gamecamera = NewGO<GameCamera>(0, "gamecamera");

	m_resultScore = NewGO<Score>(0, "Score");
	m_timer = NewGO<Timer>(0, "timer");
	m_stage01 = NewGO<Stage01>(0, "stage01");
	return true;
}

Game::~Game()
{

	DeleteGO(m_player);
	DeleteGO(m_gamecamera);

	DeleteGO(m_timer);
	DeleteGO(m_resultScore);
	DeleteGO(m_stage01);
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();
}

//void Game::Render(RenderContext& rc)
//{
//	m_modelRender.Draw(rc);
//}