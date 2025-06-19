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
	void Update();
	void UpdateModelRenderer();
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Game*		m_game		= nullptr;
	Score*		m_score		= nullptr;
	Timer*		m_timer		= nullptr;
	Stage01*	m_stage01	= nullptr;
	Stage02*	m_stage02	= nullptr;
	Stage03*	m_stage03	= nullptr;
	Stage04*	m_stage04	= nullptr;
	Stage05*	m_stage05	= nullptr;
	Mikan*		m_mikan		= nullptr;
	Player*		m_player	= nullptr;
	Transform*	m_transform	= nullptr;

	ModelRender		m_modelRender;
	Vector3			m_flyVelocity	= Vector3::Zero;
	Vector3			m_velocity		= Vector3::Zero;	//飛ばすときの速度ベクトル

	bool		m_isCollected		= false;			//アイテム取得済みかどうかのフラグ
	float		m_flyUpTimer		= 0.0f;				//飛ばす経過時間
	float		m_alpha				= 1.0f;				//透明度（1.0＝不透明、0.0＝完全透明）
};