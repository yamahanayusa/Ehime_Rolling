#pragma once

class Player;
class Transform;
class CountDown;

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

	Transform*		m_transform		= nullptr;

private:
	ModelRender			m_modelRender;
	PhysicsStaticObject m_object;

	//大きさ
	Vector3			m_scale = Vector3::One;

	//回転を設定する
	Quaternion		addRot	= Quaternion::Identity;
	Quaternion		addLot	= Quaternion::Identity;

	Player*			m_player	= nullptr;
	CountDown*		m_countDown = nullptr;
};