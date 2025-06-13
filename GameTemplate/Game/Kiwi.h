#pragma once

class Game;
class Player;
class Score;
class Timer;
class Stage04;
class Stage05;
class Transform;

class Kiwi:public IGameObject
{
public:
	Kiwi();
	~Kiwi();
	bool Start();
	void Update();
	void UpdateModelRenderer();									//絵描きさんの更新処理。
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

	

	Game*						m_game;											//ゲーム。
	ModelRender					m_modelRender;								//モデルレンダ―。

	Score*						m_score=nullptr;
	Timer*						m_timer=nullptr;
	Stage04*						m_stage04=nullptr;
	Stage05* m_stage05 = nullptr;

private:
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

