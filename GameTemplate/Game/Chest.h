#pragma once

class Game;
class Score;
class Timer;
class Player;
class Transform;
class Stage;

class Chest :public IGameObject
{
public:
	Chest();
	~Chest();
	bool Start();
	void Update();								//更新
	void Move();								//移動
	//void PlayAnimation();						//アニメーション
	void Render(RenderContext& rc);				//描画
	
	Transform* GetTransform()
	{
		return m_transform;
	}

	Game*						m_game = nullptr;						//ゲーム
	Score*						m_score = nullptr;						//スコア
    Timer*						m_timer = nullptr;						//タイマー
	Player*						m_player = nullptr;						//プレイヤー
	Stage*						m_stage = nullptr;						//ステージ

	ModelRender					m_modelRender;							//モデルレンダ―

	int							m_chestState = 0;						//chestのステート
    int							m_tortalScore = 0;
	bool						m_clearFlag = false;

private:
	Transform*					m_transform = nullptr;					//トランスフォーム

	PhysicsStaticObject			m_Object;
};

