#include "stdafx.h"
#include "Timer.h"
#include "Game.h"

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
	m_game = FindGO<Game>("game");
	return true;
}

void Timer::Update()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d", int(m_time));

	//表示するテキストを設定。
	m_fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(800.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(1.7f);
	//フォントの色を設定。
	m_fontRender.SetColor({ 0.0f,0.0f,0.0f,1.0f });

	m_time -= g_gameTime->GetFrameDeltaTime();

	if (m_time <= 10.0f)
	{
		m_fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });
	}
}

void Timer::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}