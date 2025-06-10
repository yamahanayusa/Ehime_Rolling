#pragma once

class Game;
class Score;
class Timer;
class Player;
class Transform;
class Stage01;
class Stage03;
class Stage04;

class Flag :public IGameObject
{
public:
	Flag();
	~Flag();
	bool Start();
	void Update();								//更新。
	void UpdateModelRenderer();					//モデルレンダラーを更新。
	void Render(RenderContext& rc);				//描画。
	
	Transform* GetTransform()
	{
		return m_transform;
	}

	Game*						m_game = nullptr;						//ゲーム。
	Score*						m_score = nullptr;						//スコア。
    Timer*						m_timer = nullptr;						//タイマー。
	Player*						m_player = nullptr;						//プレイヤー。
    Stage01* m_stage01 = nullptr;
	Stage03* m_stage03 = nullptr;						//ステージ。
	Stage04* m_stage04 = nullptr;					//ステージ。

	ModelRender					m_modelRender;								//モデルレンダ―。
    int							m_tortalScore = 0;
	bool						m_clearFlag = false;

private:
	Transform*					m_transform = nullptr;					//トランスフォーム

	PhysicsStaticObject			m_Object;
};

