#include "stdafx.h"
#include "Timer.h"
#include "Game.h"
#include "CountDown.h"

Timer::Timer()
{

}

Timer::~Timer()
{

}

bool Timer::Start()
{
	m_timerCount = 60;
	m_time = m_timerCount;

	m_spriteRender.Init("Assets/sprite/Timer.dds",250.0f,200.0f);
	m_game = FindGO<Game>("game");
	m_countDown = FindGO<CountDown>("countDown");

	m_spriteRender.SetPosition({ 0.0f, 460.0f, 0.0f });
	m_spriteRender.Update();

	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d", int(m_time));

	//表示するテキストを設定。
	m_fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(-50.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(1.7f);
	//フォントの色を設定。
	m_fontRender.SetColor({ 0.0f,0.0f,0.0f,1.0f });
	
	return true;
}

void Timer::Update()
{
	if (m_countDown->GetShowGO()) {
		return;
	}

	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d", int(m_time));

	//表示するテキストを設定。
	m_fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(-50.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(1.7f);
	//フォントの色を設定。
	m_fontRender.SetColor({ 0.0f,0.0f,0.0f,1.0f });

	m_time -= g_gameTime->GetFrameDeltaTime();

	if (m_time <= 10.0f)
	{
		m_fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });
	}

	if (m_time <= 0.0f)
	{
		m_game->m_gameState = m_game->enTimeOver;
		//m_game->GameStateUpdate();
	}
}

void Timer::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
	
}