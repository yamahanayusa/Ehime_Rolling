#pragma once
class GameClear;
class Game;
class Timer;
class Chest;
class Score :public IGameObject
{
public:
	Score();
	~Score();

	bool Start();
	void Update();
	void ResultScore();
	void Render(RenderContext& rc);

	FontRender m_resultRender;
	SpriteRender spriteRender;
	FontRender m_ScoreFontRender;

	//ƒƒ“ƒo•Ï”
	int m_resultScore = 0;
	GameClear* m_gameClear;
	bool m_clearFlag = false;
	Timer* m_timer;
	int m_tortalScore = 0;
	Chest* m_chest;
	Score* m_score;
	const int m_timerStop = 0;
};

