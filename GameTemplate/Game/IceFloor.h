#pragma once

class Player;

class IceFloor : public IGameObject
{
public:
	IceFloor();
	~IceFloor();
	bool Start();
	void Update();
	void Rotation();//‰ñ“]ˆ—B
	void Render(RenderContext& rc);

	//‰ñ“]‚ğİ’è‚·‚é
	Quaternion addRot;
	Quaternion addLot;

	ModelRender					m_modelRender;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Player* m_player = nullptr;
};

