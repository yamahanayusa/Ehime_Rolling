#include "stdafx.h"
#include "Score.h"
#include "Game.h"
#include "GameClear.h"
#include "Timer.h"
#include "flag.h"

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

	//
	UpdateSdRender(g_gameTime->GetFrameDeltaTime());
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

void Score::SdRender(int sdScore)
{
	m_sdRenderScore = sdScore;
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"+%d ", int(m_sdRenderScore*m_buffMultipier));
	m_sdRender.SetText(wcsbuf);
	m_sdRender.SetPosition({ -50.0f, 0.0f, 0.0f });
	m_sdRender.SetScale(1.0);
	m_sdRender.SetColor(g_vec4Black);

	lerp(btVector3(-100.0f, -300.0f, 0.0f),btVector3(-100.0f,-100.0f,0.0f),btScalar(0.0f));
	m_sdRenderTimer = 2.0f;
	m_isSdRenderActive = true;
}


void Score::UpdateSdRender(float deltaTime)
{
	if (m_isSdRenderActive) {
		m_sdRenderTimer -= deltaTime;
		if (m_sdRenderTimer <= 0.0f) {
			ClearSdRender();
		}
	}
}

void Score::ClearSdRender()
{
	m_sdRender.SetText(L"");
	m_isSdRenderActive = false;
	m_sdRenderScore = 0; //
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
	m_sdRender.Draw(rc);
}