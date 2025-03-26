#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Timer;
class Score;
class Chest;
class GameOver;
class Title;

class Game : public IGameObject
{
public:
	Game() {}
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Newkansuu();

	enum EnGameState{
		enTitle,
		enStageSelect,
		enInGame,
		enResult
	};
	EnGameState m_gameState = enTitle;

private:
	Title* m_title;
	Chest* m_chest;
	Timer* m_timer;
	Score* m_resultScore;
	Vector3 m_pos;
};

