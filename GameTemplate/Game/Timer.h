#pragma once
class Game;
class CountDown;
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
	float m_timerCount = 0;
	float m_time = 0;
  
	SpriteRender m_spriteRender;
	FontRender m_fontRender;
	Game* m_game;
	CountDown* m_countDown;
};

