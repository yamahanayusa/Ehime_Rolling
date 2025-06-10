#pragma once
class Player;
class Transform;
class Stage03 : public IGameObject
{
public:
	Stage03();
	~Stage03();
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
	Vector3	m_scale = Vector3::One;//�傫���B
	//��]��ݒ肷��
	Quaternion addRot;
	Quaternion addLot;
	Transform* m_transform;
private:
	ModelRender m_modelRender;
	PhysicsStaticObject m_Object;
	Player* m_player = nullptr;
};




