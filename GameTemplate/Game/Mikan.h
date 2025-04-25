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

	enum EnAnimationClip {										//アニメーションクリップ
		enAnimationClip_Num,
	};
	Game* m_game;										//ゲーム。
	//Player* m_player;											//プレイヤー。

	ModelRender		m_modelRender;								//モデルレンダ―。
	Vector3			m_position;									//座標。
	Vector3			m_firstPosition;							//最初の座標。

	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;

	Score* m_score;
	Timer* m_timer;
	int m_tortalScore = 0;

private:
	Quaternion					m_Rotation;
	PhysicsStaticObject			m_Object;
	Mikan* m_mikan;
	Player* m_player;

};