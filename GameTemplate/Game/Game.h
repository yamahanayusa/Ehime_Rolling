#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Timer;
class Score;
class Flag;
class Mikan;
class TimeOver;
class GameOver;
class GameClear;
class GameCamera;
class Title;
class Stage;
class IceFloor;
class Transform;
class Jakoten;
class Bumper;
class SandFloor;
class Kiwi;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Stage1();
	void Stage3();
	void Stage4();
	void GameStateUpdate();
	void Render(RenderContext& rc);

	enum EnGameState{
		enTitle,
		enStageSelect,
		enInGame,
		enResult,
		enTimeOver,
		enGameOver
	};
	EnGameState m_gameState = enTitle;

private:
	LevelRender m_levelRender;

	Title*					m_title;
	Flag*					m_falg = nullptr;
	Timer*					m_timer;
	Jakoten*				m_jakoten;
	TimeOver*				m_timeOver;
	GameOver*				m_gameOver;
	GameClear*				m_gameClear;
	Score*					m_score;
	Kiwi*					m_kiwi = nullptr;
	Stage*					m_stage	= nullptr;
	Player*					m_player = nullptr;
	GameCamera*				m_gameCamera = nullptr;
	IceFloor*				m_iceFloor = nullptr;
	SandFloor*				m_sandFloor = nullptr;
	Transform*				m_transform = nullptr;
	SoundSource*			m_soundSource = nullptr;
	Mikan*					m_mikan[2];
	Bumper*					m_bumper[4];
	Vector3					m_pos;
	int						m_resultTime = 0;
};

