#include "stdafx.h"
#include "Score.h"
#include "Game.h"

Score::Score()
{

}

Score::~Score()
{

}

void Score::Update()
{
	ResultScore();
}

//トータルスコア
void Score::ResultScore()
{
	wchar_t scorew[256];
	swprintf_s(scorew, 256, L"%d点", int(m_resultScore));
	m_ScoreFontRender.SetText(scorew);
	m_ScoreFontRender.SetPosition({ 500.0f, 500.0f, 0.0f });
	m_ScoreFontRender.SetScale(1.0);
	m_ScoreFontRender.SetColor(g_vec4Black);
}

void Score::Render(RenderContext& rc)
{
	//m_resultRender.Draw(rc);
	//spriteRender.Draw(rc);
	m_ScoreFontRender.Draw(rc);
}