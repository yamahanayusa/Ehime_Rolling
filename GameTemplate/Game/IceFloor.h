#pragma once

class Player;

class IceFloor : public IGameObject
{
public:
	IceFloor();
	~IceFloor();
	bool Start();
	void Update();
	//回転処理
	void Rotation();
	//滑る処理
	void Slide();
	void Render(RenderContext& rc);

	/// <summary>
	/// 座標を設定する
	/// </summary>
	/// <param name="position">座標</param>
	void SetPosition(const Vector3& position)
	{
		m_position = position;
		m_modelRender.SetPosition(m_position);
	}
	/// <summary>
	/// 回転を設定する
	/// </summary>
	/// <param name="rotation">回転</param>
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
		m_modelRender.SetRotation(m_rotation);
	}
	/// <summary>
	/// 大きさを設定する
	/// </summary>
	/// <param name="scale">大きさ</param>
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
		m_modelRender.SetScale(m_scale);
	}

	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;

	ModelRender					m_modelRender;
	Vector3 m_position;
	Vector3 m_virtualposition = { 980.0f,0.0f,1200.0f };
	Vector3 m_icepos = m_virtualposition - m_position;
	Vector3					m_scale = Vector3::One;

private:
	Quaternion					m_rotation;
	PhysicsStaticObject			m_Object;
	Player* m_player = nullptr;
};

