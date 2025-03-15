#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"


bool Game::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_resultScore = NewGO<Score>(0, "Score");
	m_timer = NewGO<Timer>(0, "timer");
	return true;
}

Game::~Game()
{
	
	DeleteGO(m_timer);
	DeleteGO(m_resultScore);
}

void Game::Update()
{
	// g_renderingEngine->DisableRaytracing();
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}