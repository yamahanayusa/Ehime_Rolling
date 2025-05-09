#pragma once

//class Player;
class Game;
class Score;
class Timer;
class Player;
class Chest :public IGameObject
{
public:
	Chest();
	~Chest();
	bool Start();
	void Update();															//更新。
	void Move();															//移動。
	void Rotation();														//回転。
	//void PlayAnimation();													//アニメーション。
	void Render(RenderContext& rc);											//描画。
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

	enum EnAnimationClip {													//アニメーションクリップ
		enAnimationClip_Close,												//chestが閉じているとき。
		enAnimationClip_Open,												//chestが空いているとき。
		enAnimationClip_Num,
	};

	Game*						m_game;										//ゲーム。
	Score*						m_score;									//スコア。
    Timer*						m_timer;									//タイマー。
	Player*						m_player;									//プレイヤー。

	//回転を設定する。
	Quaternion					addRot;
	Quaternion					addLot;

	AnimationClip				m_animationClips[enAnimationClip_Num];		//アニメーション。
	ModelRender					m_modelRender;								//モデルレンダ―。
	Vector3						m_position;									//座標。
	Vector3						m_firstPosition;							//最初の座標。

	int							m_chestState = 0;							//chestのステート。
    int							m_tortalScore = 0;
	bool						m_clearFlag = false;

private:
	PhysicsStaticObject			m_Object;
	Vector3						m_scale = Vector3::One;
	Quaternion					m_rotation;
};

