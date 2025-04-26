#pragma once

class Player;

class IceFloor : public IGameObject
{
public:
	IceFloor();
	~IceFloor();
	bool Start();
	void Update();
	//‰ñ“]ˆ—
	void Rotation();
	//ŠŠ‚éˆ—
	void Slide();
	void Render(RenderContext& rc);

	/// <summary>
	/// À•W‚ğİ’è‚·‚é
	/// </summary>
	/// <param name="position">À•W</param>
	void SetPosition(const Vector3& position)
	{
		m_position = position;
		m_modelRender.SetPosition(m_position);
	}
	/// <summary>
	/// ‰ñ“]‚ğİ’è‚·‚é
	/// </summary>
	/// <param name="rotation">‰ñ“]</param>
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
		m_modelRender.SetRotation(m_rotation);
	}
	/// <summary>
	/// ‘å‚«‚³‚ğİ’è‚·‚é
	/// </summary>
	/// <param name="scale">‘å‚«‚³</param>
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
		m_modelRender.SetScale(m_scale);
	}

	//‰ñ“]‚ğİ’è‚·‚é
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

