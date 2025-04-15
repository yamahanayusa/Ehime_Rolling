#include "stdafx.h"
#include "Score.h"
#include "Game.h"
#include "GameClear.h"
#include "Timer.h"
#include "Chest.h"

Score::Score()
{

}

Score::~Score()
{

}



bool Score::Start()
{
	m_score = FindGO<Score>("score");
	m_chest = FindGO<Chest>("chest");
	return true;
}

void Score::Update()
{
	ResultScore();
}

//トータルスコア
void Score::ResultScore()
{
	wchar_t scorew[256];
	swprintf_s(scorew, 256, L"%d点", int(m_tortalScore));
	m_ScoreFontRender.SetText(scorew);
	m_ScoreFontRender.SetPosition({ 500.0f, 500.0f, 0.0f });
	m_ScoreFontRender.SetScale(1.0);
	m_ScoreFontRender.SetColor(g_vec4Black);
	m_tortalScore = m_score->m_resultScore + m_timerStop;
}

void Score::Render(RenderContext& rc)
{
	//FontRender m_resultRender;
	//SpriteRender spriteRender;
	m_ScoreFontRender.Draw(rc);
}