#pragma once
class Game;
class Player;
class Score;
class Timer;
class Mikan;
class Jakoten :public IGameObject
{
public:
	Jakoten();
	~Jakoten();
	bool Start();
	void Update();						//更新。
	void Render(RenderContext& rc);		//描画。
	void Rotation();
	void Move();						//移動。	
	void SetPos(Vector3 pos) 
	{
		m_position = pos;
	}

	Vector3 GetPos()
	{
		return m_position;
	}

private:
	//ポインタ系。
	Player*		m_player = nullptr;
	Score*		m_score = nullptr;
	Timer*		m_timer = nullptr;

	//モデル表示系。
	ModelRender		m_modelRender;						//モデルレンダ―。
	Vector3			m_position = Vector3::Zero;			//座標。
	Vector3			m_firstPosition = Vector3::Zero;	//最初の座標。

	//バフ系。
	float	m_buffTimer = 0;	//バフの経過時間。
	bool	m_isGet = false;	//プレイヤーがじゃこ天を獲得したかどうか。
};

