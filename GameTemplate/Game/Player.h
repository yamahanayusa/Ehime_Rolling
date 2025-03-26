#pragma once

//クラス宣言
class Game;
class Collision;
//class GameCamera;


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

	//セットポジション
	void SetPosition(const Vector3& position)
	{
		m_ballPosition = position;
	}
	//座標を取得
	const Vector3& GetPosition() const
	{
		return m_ballPosition;
	}
	//回転を設定
	void SetRotation(const Quaternion& rotation)
	{
		m_ballRotation = rotation;
	}

	CharacterController& GetCharacterController()
	{
		return m_characterController;
	}
	void AddMoveSpeed(const Vector3& addMoveSpeed)
	{
		m_ballSpeed += addMoveSpeed;
	}
	const float             g = 9.8f;//重力
	CharacterController     m_charaCon;//キャラコン
	ModelRender m_ballRender;//ボールレンダー
	Vector3 m_ballPosition;//ボールのポジション
	RigidBody m_rigidBody;// 剛体
	SphereCollider m_sphereCollider;// ボールの形状
	Quaternion m_ballRotation;//ボールローテーション（回転)
	RigidBodyInitData rbInitData;
	Vector3                 m_ballSpeed;//スピード
	//Game* m_game;
	CharacterController	    m_characterController;
	Vector3					m_forward = Vector3::AxisZ;

private:
	//移動処理
	//void Move();
	//回転処理
	void Rotation();
	//ジャンプ処理
	void PlayerJump();

};

