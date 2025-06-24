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
class Stage01;
class Stage02;
class Stage03;
class Stage04;
class Stage05;
class IceFloor;
class Transform;
class Jakoten;
class SandFloor;
class Kiwi;
class CountDown;
class Describe;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Stage1();
	void Stage2();
	void Stage3();
	void Stage4();
	void Stage5();
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

	int			m_state;
	Vector3     m_flagPos = Vector3::Zero;

private:
	LevelRender		m_levelRender;

	Title*			m_title			= nullptr;
	Flag*			m_flag			= nullptr;
	Timer*			m_timer			= nullptr;
	Jakoten*		m_jakoten		= nullptr;
	TimeOver*		m_timeOver		= nullptr;
	GameOver*		m_gameOver		= nullptr;
	GameClear*		m_gameClear		= nullptr;
	Score*			m_score			= nullptr;
	Kiwi*			m_kiwi			= nullptr;
	Stage01*		m_stage01		= nullptr;
	Stage02*		m_stage02		= nullptr;
	Stage03*		m_stage03		= nullptr;
	Stage04*		m_stage04		= nullptr;
	Stage05*		m_stage05		= nullptr;
	Player*			m_player		= nullptr;
	GameCamera*		m_gameCamera	= nullptr;
	IceFloor*		m_iceFloor		= nullptr;
	SandFloor*		m_sandFloor		= nullptr;
	Transform*		m_transform		= nullptr;
	SoundSource*	m_soundSource	= nullptr;
	CountDown*		m_countDown		= nullptr;
	Mikan*			m_mikan[30];

	int				m_resultTime = 0;
};

