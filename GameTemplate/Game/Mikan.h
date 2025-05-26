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

	ModelRender					m_modelRender;								//モデルレンダ―。

	Game*					m_game;										//ゲーム。
	Score*					m_score;
	Timer*					m_timer;
	Stage*					m_stage;

	int						m_tortalScore = 0;
	int						m_mikanscore = 100;

private:
	Mikan*					m_mikan;
	Player*					m_player;
	Transform*			m_transform = nullptr;
	Vector3					m_flyVelocity = Vector3::Zero; /*{ 0.0f,0.0f,0.0f };*/
	Vector3					m_velocity;		//飛ばすときの速度ベクトル
	bool m_isCollected = false;				//アイテム取得済みかどうかのフラグ
	float m_flyUpTimer = 0.0f;				//飛ばす経過時間
	float m_alpha = 1.0f;					//透明度（1.0＝不透明、0.0＝完全透明）
};