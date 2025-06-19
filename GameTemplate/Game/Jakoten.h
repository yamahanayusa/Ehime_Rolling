#pragma once

class Game;
class Player;
class Score;
class Timer;
class Mikan;
class Stage05;
class Transform;

class Jakoten :public IGameObject
{
public:
	Jakoten();
	~Jakoten();
	bool Start();
	void Update();						//更新。
	void Render(RenderContext& rc);		//描画。
	void Rotation();
	void UpdateModelRenderer();			//絵描きさんの更新処理。	

	Transform* GetTransform()
	{
		return m_transform;
	}

	void SetPos(Vector3 pos) 
	{
		m_position = pos;
	}

	//Vector3 GetPos()
	//{
	//	return m_position;
	//}

private:
	//ポインタ系。
	Player*			m_player		= nullptr;
	Score*			m_score			= nullptr;
	Timer*			m_timer			= nullptr;
	Stage05*		m_stage05		= nullptr;
	Transform*		m_transform		= nullptr;
	Game*			m_game			= nullptr;

	//モデル表示系。
	ModelRender			m_modelRender;
	Vector3				m_position		= Vector3::Zero;	//座標。
	Vector3				m_firstPosition = Vector3::Zero;	//最初の座標。
	Vector3				m_flyVelocity	= Vector3::Zero;
	Vector3				m_velocity		= Vector3::Zero;	//飛ばすときの速度ベクトル

	//バフ系。
	bool			m_isGet			= false;	//プレイヤーがじゃこ天を獲得したかどうか。
	bool			m_isCollected	= false;	//アイテム取得済みかどうかのフラグ
	float			m_flyUpTimer	= 0.0f;		//飛ばす経過時間
	float			m_alpha			= 1.0f;		//透明度（1.0＝不透明、0.0＝完全透明）
	float			m_buffTimer		= 0;		//バフの経過時間。
};

