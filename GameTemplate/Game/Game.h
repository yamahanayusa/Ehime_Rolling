#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Timer;
class Score;
class Chest;
class GameOver;
class GameClear;
class GameCamera;
class Title;
class Stage;
class IceFloor;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void GameStateUpdate();

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
	Player* m_player = nullptr;
	GameCamera* m_gamecamera = nullptr;
	IceFloor* m_iceFloor = nullptr;
	Vector3 m_pos;
};

