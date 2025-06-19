#pragma once

class Game;
class Player;
class Score;
class Timer;
class Stage04;
class Stage05;
class Transform;

class Kiwi:public IGameObject
{
public:
	Kiwi();
	~Kiwi();
	bool Start();
	void Update();
	void UpdateModelRenderer();
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Game*			m_game			= nullptr;
	Kiwi*			m_kiwi			= nullptr;
	Player*			m_player		= nullptr;
	Transform*		m_transform		= nullptr;
	Score*			m_score			= nullptr;
	Timer*			m_timer			= nullptr;
	Stage04*		m_stage04		= nullptr;
	Stage05*		m_stage05		= nullptr;

	ModelRender				m_modelRender;
	PhysicsStaticObject		m_object;

	Vector3			m_flyVelocity		= Vector3::Zero;
	Vector3			m_velocity			= Vector3::Zero;		//飛ばすときの速度ベクトル

	bool			m_isCollected		= false;				//アイテム取得済みかどうかのフラグ
	float			m_flyUpTimer		= 0.0f;					//飛ばす経過時間
	float			m_alpha				= 1.0f;					//透明度（1.0＝不透明、0.0＝完全透明）
};

