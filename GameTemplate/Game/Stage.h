#pragma once

class Player;

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//レンダー
	void Render(RenderContext& rc);
	//回転処理
	void Rotation();
	Vector3	m_scale = Vector3::One;//大きさ。
	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;
private:
	ModelRender m_bgModelRendedr;
	Quaternion m_bgRotation;
	PhysicsStaticObject m_bgObject;
	Player* m_player = nullptr;
};
