#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "Timer.h"
#include "Score.h"
#include "Chest.h"
#include "GameOver.h"

bool Game::Start()
{
	Newkansuu();
	return true;
}

Game::~Game()
{
	DeleteGO(m_timer);
	DeleteGO(m_resultScore);
}

void Game::Update()
{

}

void Game::Render(RenderContext& rc)
{

}

void Game::Newkansuu()
{
	switch (m_gameState)
	{
	case Game::enTitle:
		m_title = NewGO<Title>(0, "title");
		break;
	case Game::enStageSelect:
		m_gameState = enInGame;
		Newkansuu();
		break;
	case Game::enInGame:
		m_resultScore = NewGO<Score>(0, "Score");
		m_timer = NewGO<Timer>(0, "timer");
		m_chest = NewGO<Chest>(0, "chest");
		break;
	case Game::enResult:
		DeleteGO(m_timer);
		DeleteGO(m_chest);
		NewGO<Gameover>(0, "Gameover");
		break;
	default:
		break;
	}
}
