#pragma once

class Game;
class Stage01;
class Stage02;
class Stage03;
class Stage04;
class Stage05;
class Transform;

class Goal :public IGameObject
{
public:
	Goal();
	~Goal();
	bool Start();
	void Update();
	void UpdateModelRenderer();
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Stage01*	m_stage01	= nullptr;
	Stage02*	m_stage02	= nullptr;
	Stage03*	m_stage03	= nullptr;
	Stage04*	m_stage04	= nullptr;
	Stage05*	m_stage05	= nullptr;
	Goal*		m_goal		= nullptr;
	Game*		m_game		= nullptr;
	Transform*	m_transform = nullptr;

	ModelRender		m_modelRender;
};