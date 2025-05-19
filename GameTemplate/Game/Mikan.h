#pragma once

class Game;
class Player;
class Score;
class Timer;
class Stage;
class Transform;

class Mikan :public IGameObject
{
public:
	Mikan();
	~Mikan();
	bool Start();
	void Update();												//更新。
	void Move();												//移動。
	void Render(RenderContext& rc);		                        //描画。

	Transform* GetTransform()
	{
		return m_transform;
	}

	ModelRender				m_modelRender;				//モデルレンダ―。

	Game*					m_game;						//ゲーム。
	Score*					m_score;
	Timer*					m_timer;
	Stage*					m_stage;

	int						m_tortalScore = 0;

private:
	Mikan*					m_mikan;
	Player*					m_player;
	Transform*				m_transform;
};