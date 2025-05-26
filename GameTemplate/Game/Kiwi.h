#pragma once

class Game;
class Player;
class Score;
class Timer;
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

	Game* m_game;												//ゲーム。
	ModelRender		m_modelRender;								//モデルレンダ―。
	Vector3			m_position;									//座標。
	Vector3			m_firstPosition;							//最初の座標。
	Vector3			m_scale = Vector3::One;
	Quaternion		m_rotation;

	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;

	Score* m_score;
	Timer* m_timer;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Kiwi*						m_kiwi;
	Player*						m_player;
};

