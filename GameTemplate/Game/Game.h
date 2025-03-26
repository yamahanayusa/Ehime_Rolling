#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class Timer;
class Score;
class Stage01;
class GameCamera;

class Game : public IGameObject
{
public:
	Game() {}
	~Game();
	bool Start();
	void Update();
	//void Render(RenderContext& rc);

private:
	GameCamera* m_gamecamera;
	Player* m_player;
	Stage01* m_stage01;
	Timer* m_timer;
	Score* m_resultScore;
	ModelRender m_modelRender;
	Vector3 m_pos;
};

