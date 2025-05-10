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
	m_timer = FindGO<Timer>("timer");
	return true;
}

void Score::Update()
{
	ResultScoreCalc();

	TimeScoreCalc();

	//?A?C?e????“??????X?R?A???c?????????X?R?A???‡?Z?B
	m_tortalScore = m_itemGetScore + m_timeScore;

	ResultScoreDisp();
}

void Score::ResultScoreDisp()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d 点", int(m_itemGetScore));
	m_scoreFontRender.SetText(wcsbuf);
	m_scoreFontRender.SetPosition({ 500.0f, 500.0f, 0.0f });
	m_scoreFontRender.SetScale(1.0);
	m_scoreFontRender.SetColor(g_vec4Black);
}

void Score::ResultScoreCalc()
{
	//?o?t????‰????????o‰??B
	if (m_buffMultipier != 1.0f) {
		m_buffSecond -= g_gameTime->GetFrameDeltaTime();
		if (m_buffSecond <= 0.0f)	//?o?t?o‰????????c??0?b???????????B
		{
			m_buffMultipier = 1.0f;
		}
	}	
}

void Score::TimeScoreCalc()
{

	m_timeScore = m_timer->GetTime();
}

void Score::Render(RenderContext& rc)
{
	m_scoreFontRender.Draw(rc);
}