#pragma once

class Game;
class Player : public IGameObject
{
public:

	Player();
	~Player();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//レンダー
	void Render(RenderContext& rc);

	Vector3                 m_position;//座標。
	Vector3                 m_scale = Vector3::One;//スケール
	
	Vector3                 m_moveSpeed;//移動速度
	Vector3                 m_ballPosition;
	CharacterController     m_charaCon;//キャラコン
	// 剛体の位置と回転を取得する
	Vector3 rbPos;
	Quaternion rbRot;
	Game* m_game;

private:
	RigidBody m_rigidBody;	// 剛体
	ModelRender m_ballRender;
	SphereCollider m_sphereCollider; // ボールの形状
	RigidBodyInitData rbInitData;
};