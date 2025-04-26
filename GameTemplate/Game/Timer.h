#pragma once
class Game;
class Timer :public IGameObject
{
public:
	Timer();
	~Timer();

	bool Start();
	void Update();
	void Render(RenderContext& rc);
	float GetTime() {
		return m_time;
	}
private:
	float m_time = 60.0f;
	FontRender m_fontRender;
	Game* m_game;
};

