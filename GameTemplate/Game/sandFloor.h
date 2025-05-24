#pragma once

class Stage;
class Transform;

class sandFloor : public IGameObject
{
public:
	sandFloor();
	~ sandFloor();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void SetPos(Vector3 pos)
	{
		m_position = pos;
	}

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	Stage*					m_stage = nullptr;
	Transform*				m_transform = nullptr;

	Vector3  m_position;

	PhysicsStaticObject		m_object;
	ModelRender				m_modelRender;
};

