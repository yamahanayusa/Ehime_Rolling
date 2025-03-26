#pragma once
class Game;
class GameClear;
class Timer :public IGameObject
{
public:
	Timer();
	~Timer();

	void Update();
	void Render(RenderContext& rc);

	float m_timer = 15.0f;
	FontRender m_fontRender;
	Game* m_game;
};

