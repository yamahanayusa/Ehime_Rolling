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
	void Update();												//更新。
	void Move();												//移動。
	void Rotation();											//回転。
	void PlayAnimation();										//アニメーション。
	void Render(RenderContext& rc);								//描画。

	enum EnAnimationClip {										//アニメーションクリップ
		enAnimationClip_Close,									//chestが閉じているとき。
		enAnimationClip_Open,									//chestが空いているとき。
		enAnimationClip_Num,
	};

	Game*			m_game;										//ゲーム。
	Score*          m_score;
    Timer*			m_timer;
	Player*			m_player;									//プレイヤー。
   
	//回転を設定する
	Quaternion		addRot;
	Quaternion		addLot;

	AnimationClip	m_animationClips[enAnimationClip_Num];		//アニメーション。
	ModelRender		m_modelRender;								//モデルレンダ―。
	Vector3			m_position;									//座標。
	Vector3			m_firstPosition;							//最初の座標。

	int				m_chestState = 0;							//chestのステート。
    int				m_tortalScore = 0;
	bool			m_clearFlag = false;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
};

