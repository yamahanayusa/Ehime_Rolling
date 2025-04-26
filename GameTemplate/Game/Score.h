#pragma once
class GameClear;
class Game;
class Timer;
class Chest;
class Mikan;
class Score :public IGameObject
{
public:
	Score();
	~Score();

	bool Start();
	void Update();
	void ResultScore();
	void Render(RenderContext& rc);

    GameClear* m_gameClear;
	Timer* m_timer;
	Chest* m_chest;
	Score* m_score;
	Mikan* m_mikan;
	FontRender m_resultRender;
	SpriteRender spriteRender;
	FontRender m_ScoreFontRender;

	//ƒƒ“ƒo•Ï”
	int m_resultScore = 0;
	int m_tortalScore = 0;
	bool m_clearFlag = false;
	const int m_resultTime = 0;
};

