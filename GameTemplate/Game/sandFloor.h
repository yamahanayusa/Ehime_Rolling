#pragma once

class Player;
class Stage04;
class Transform;

class SandFloor : public IGameObject
{
public:
	SandFloor();
	~ SandFloor();
	bool Start();
	void Update();
	void Slide();
	void UpdateModelRenderer();			//ŠG•`‚«‚³‚ñ‚ÌXVˆ—B
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Stage04*		m_stage04		= nullptr;
	Transform*		m_transform		= nullptr;
	Player*			m_player		= nullptr;

	Vector3 				m_position;
	PhysicsStaticObject		m_object;
	ModelRender				m_modelRender;
};

