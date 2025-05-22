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
	m_spriteRender.Init("Assets/sprite/Score.dds", 250.0f,100.0f);
	return true;
}

void Score::Update()
{
	m_spriteRender.SetPosition({ 800.0f, 480.0f, 0.0f });
	m_spriteRender.Update();

	ResultScoreCalc();

	TimeScoreCalc();

	//トータルスコアの計算
	m_tortalScore = m_itemGetScore + m_timeScore;

	ResultScoreDisp();
}

void Score::ResultScoreDisp()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d 点", int(m_itemGetScore));
	m_scoreFontRender.SetText(wcsbuf);
	m_scoreFontRender.SetPosition({ 750.0f, 500.0f, 0.0f });
	m_scoreFontRender.SetScale(1.0);
	m_scoreFontRender.SetColor(g_vec4Black);
}

void Score::ResultScoreCalc()
{
	//じゃこ天を取ったときのバフタイマー
	if (m_buffMultipier != 1.0f) {
		m_buffSecond -= g_gameTime->GetFrameDeltaTime();
		if (m_buffSecond <= 0.0f)	//バフタイマー0になったら元に戻す
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
	m_spriteRender.Draw(rc);
	m_scoreFontRender.Draw(rc);
	
}