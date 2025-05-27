#pragma once

class Stage;
class Transform;

class SandFloor : public IGameObject
{
public:
	SandFloor();
	~ SandFloor();
	bool Start();
	void Update();
	void UpdateModelRenderer();			//ŠG•`‚«‚³‚ñ‚ÌXVˆ—B
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Stage*					m_stage = nullptr;
	Transform*				m_transform = nullptr;

	PhysicsStaticObject		m_object;
	ModelRender				m_modelRender;
};

