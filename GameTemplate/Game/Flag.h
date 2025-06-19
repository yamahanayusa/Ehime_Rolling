#pragma once

class Game;
class Score;
class Timer;
class Player;
class Transform;
class Stage01;
class Stage02;
class Stage03;
class Stage04;
class Stage05;

class Flag :public IGameObject
{
public:
	Flag();
	~Flag();
	bool Start();
	void Update();								//更新。
	void UpdateModelRenderer();					//モデルレンダラーを更新。
	void Render(RenderContext& rc);				//描画。
	
	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	ModelRender					m_modelRender;
	PhysicsStaticObject			m_object;

	Transform*		m_transform		= nullptr;
	Game*			m_game			= nullptr;
	Score*			m_score			= nullptr;
	Timer*			m_timer			= nullptr;
	Player*			m_player		= nullptr;
	Stage01*		m_stage01		= nullptr;
	Stage02*		m_stage02		= nullptr;
	Stage03*		m_stage03		= nullptr;
	Stage04*		m_stage04		= nullptr;
	Stage05*		m_stage05		= nullptr;

	bool			m_clearFlag		= false;
};

