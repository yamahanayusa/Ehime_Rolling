#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Timer;
class Score;
class Chest;
class GameOver;
class GameClear;
class Title;
class Stage;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void GameTransition();

	enum EnGameState{
		enTitle,
		enStageSelect,
		enInGame,
		enResult,
		enGameOver
	};
	EnGameState m_gameState = enTitle;

private:
	Title* m_title;
	Chest* m_chest;
	Timer* m_timer;
	GameOver* m_gameOver;
	GameClear* m_gameClear;
	Score* m_resultScore;
	Stage* m_stage = nullptr;
	Vector3 m_pos;
};

