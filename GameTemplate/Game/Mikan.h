#pragma once

class Game;
class Player;
class Score;
class Timer;
class Stage01;
class Stage02;
class Stage03;
class Stage04;
class Stage05;
class Transform;

class Mikan :public IGameObject
{
public:
	Mikan();
	~Mikan();
	bool Start();
	void Update();												//更新。
	void UpdateModelRenderer();									//絵描きさんの更新処理。。
	void Render(RenderContext& rc);		                        //描画。

	Transform* GetTransform()
	{
		return m_transform;
	}

ModelRender		m_modelRender;				//モデルレンダ―。

	Game*		m_game;						//ゲーム。
	Score*		m_score;
	Timer*		m_timer;
	Stage01* m_stage01 = nullptr;
	Stage02* m_stage02 = nullptr;
	Stage03* m_stage03 = nullptr;
	Stage04* m_stage04 = nullptr;
	Stage05* m_stage05 = nullptr;

	int			m_tortalScore = 0;
	int			m_mikanscore = 100;

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