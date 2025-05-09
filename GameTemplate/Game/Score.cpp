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

	//ƒAƒCƒeƒ€Žæ“¾Žž‚ÌƒXƒRƒA‚ÆŽc‚èŽžŠÔ‚ÌƒXƒRƒA‚Ì‡ŽZB
	m_tortalScore = m_itemGetScore + m_timeScore;

	ResultScoreDisp();
}

void Score::ResultScoreDisp()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d“_", int(m_itemGetScore));
	m_scoreFontRender.SetText(wcsbuf);
	m_scoreFontRender.SetPosition({ 500.0f, 500.0f, 0.0f });
	m_scoreFontRender.SetScale(1.0);
	m_scoreFontRender.SetColor(g_vec4Black);
}

void Score::ResultScoreCalc()
{
	//ƒoƒt‚ÌŒø‰ÊŽžŠÔ‚ÌŒo‰ßB
	if (m_buffMultipier != 1.0f) {
		m_buffSecond -= g_gameTime->GetFrameDeltaTime();
		if (m_buffSecond <= 0.0f)	//ƒoƒtŒo‰ßŽžŠÔ‚ªŽc‚è0•b‚É‚È‚Á‚½‚çB
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