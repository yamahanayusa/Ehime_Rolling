#pragma once

//class Player;
class Game;
class Player;
class Score;
class Timer;
class Mikan :public IGameObject
{
public:
	Mikan();
	~Mikan();
	bool Start();
	void Update();												//更新。
	void Render(RenderContext& rc);		                        //描画。
	void Rotation();
	void Move();												//移動。
	
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

	enum EnAnimationClip {										//アニメーションクリップ
		enAnimationClip_Num,
	};
	Game* m_game;										//ゲーム。
	//Player* m_player;											//プレイヤー。

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
	int m_tortalScore = 0;
	int m_mikanscore = 100;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Mikan* m_mikan;
	Player* m_player;

};