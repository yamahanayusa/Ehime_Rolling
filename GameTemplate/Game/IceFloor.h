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

	//‰ñ“]‚ğİ’è‚·‚é
	Quaternion addRot;
	Quaternion addLot;

	ModelRender					m_modelRender;
	Vector3 m_position;
	Vector3 m_virtualposition = { 980.0f,0.0f,1200.0f };
	Vector3 m_icepos = m_virtualposition - m_position;
private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Player* m_player = nullptr;
};

