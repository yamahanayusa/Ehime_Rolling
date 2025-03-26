#include "stdafx.h"
#include "Timer.h"
#include "Game.h"
#include "Gameover.h"
#include "GameClear.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::Update()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"%d", int(m_timer));

	//表示するテキストを設定。
	m_fontRender.SetText(wcsbuf);
	//フォントの位置を設定。
	m_fontRender.SetPosition(Vector3(800.0f, 500.0f, 0.0f));
	//フォントの大きさを設定。
	m_fontRender.SetScale(1.7f);
	//フォントの色を設定。
	m_fontRender.SetColor({ 0.0f,0.0f,0.0f,1.0f });

	m_timer -= g_gameTime->GetFrameDeltaTime();

	if (m_timer <= 10.0f)
	{
		m_fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });
	}

	if (m_timer <= 9.0f)
	{
		NewGO<GameClear>(0, "GaneClear");
		DeleteGO(this);
		DeleteGO(m_game);
	}

	if (m_timer <= 0.0f)
	{
		m_game->m_gameState = m_game->enResult;
		m_game->Newkansuu();
	}
}

void Timer::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}