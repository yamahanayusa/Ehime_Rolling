#pragma once

//class Player;

class Stage01 : public IGameObject
{
public:
	Stage01() {};
	~Stage01();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//レンダー
	void Render(RenderContext& rc);
	ModelRender m_modelRender;
	PhysicsStaticObject m_physicsStaticObject;
	Quaternion					m_rotation;//回転
	Vector3  m_scale = { 10.0f,10.0f,10.0f };//スケール
	Vector3  m_position = { 0.0f, -100.0f, 0.0f };//ポジション
};

