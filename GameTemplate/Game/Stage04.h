#pragma once
class Player;
class Transform;
class Stage04 : public IGameObject
{
public:
	Stage04();
	~Stage04();
	bool Start();
	void Update();
	void Rotation();
	void Render(RenderContext& rc);
	Transform* GetTransform()
	{
		return m_transform;
	}
	Matrix GetWorldMatrix() const
	{
		return m_modelRender.GetWorldMatrix(0);
	}
	Vector3	m_scale = Vector3::One;//‘å‚«‚³B
	//‰ñ“]‚ğİ’è‚·‚é
	Quaternion addRot;
	Quaternion addLot;
	Transform* m_transform;
private:
	ModelRender m_modelRender;
	PhysicsStaticObject m_Object;
	Player* m_player = nullptr;
};

