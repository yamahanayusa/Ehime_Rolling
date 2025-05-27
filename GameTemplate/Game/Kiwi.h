#pragma once

class Game;
class Player;
class Score;
class Timer;
class Stage;
class Transform;

class Kiwi:public IGameObject
{
public:
	Kiwi();
	~Kiwi();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Rotation();
	void Move();

	Transform* GetTransform()
	{
		return m_transform;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="pos"></param>
	void SetPos(Vector3 pos)
	{
		m_position = pos;
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

	Game*						m_game;												//ゲーム。
	ModelRender					m_modelRender;								//モデルレンダ―。
	Vector3						m_position;									//座標。
	Vector3						m_firstPosition;							//最初の座標。
	Vector3						m_scale = Vector3::One;

	//回転を設定する
	Quaternion					m_rotation;
	Quaternion					addRot;
	Quaternion					addLot;

	Score*						m_score=nullptr;
	Timer*						m_timer=nullptr;
	Stage*						m_stage=nullptr;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Kiwi*						m_kiwi;
	Player*						m_player;
	Transform*					m_transform=nullptr;
	Vector3						m_flyVelocity = Vector3::Zero;
	Vector3						m_velocity;		//飛ばすときの速度ベクトル
	bool m_isCollected = false;					//アイテム取得済みかどうかのフラグ
	float m_flyUpTimer = 0.0f;					//飛ばす経過時間
	float m_alpha = 1.0f;						//透明度（1.0＝不透明、0.0＝完全透明）
};

