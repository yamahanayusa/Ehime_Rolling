#pragma once

class Player;
class Transform;
class CountDown;

class Stage02 : public IGameObject
{
public:
	Stage02();
	~Stage02();
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
	
	Transform* m_transform = nullptr;

private:
	ModelRender			m_modelRender;
	PhysicsStaticObject m_object;

	//ëÂÇ´Ç≥
	Vector3			m_scale		= Vector3::One;

	//âÒì]Çê›íËÇ∑ÇÈ
	Quaternion		addRot		= Quaternion::Identity;
	Quaternion		addLot		= Quaternion::Identity;
	
	Player*			m_player		= nullptr;
	CountDown*		m_countDown		= nullptr;
};

