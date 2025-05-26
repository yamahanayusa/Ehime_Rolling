#pragma once

class Player;
class Stage;
class Transform;

class IceFloor : public IGameObject
{
public:
	IceFloor();
	~IceFloor();
	bool Start();
	void Update();
	//滑る処理。
	void Slide();
	//絵描きさんの更新処理。
	void UpdateModelRenderer();
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	
	Stage*					m_stage = nullptr;
	Player*					m_player = nullptr;
	Transform*				m_transform = nullptr;

	PhysicsStaticObject		m_object;
	ModelRender				m_modelRender;

	Vector3					m_position;
	Vector3					m_virtualPosition = { 980.0f,0.0f,1200.0f };
	Vector3					m_icepos = m_virtualPosition - m_position;
};