#pragma once
class Game;
class Player;
class Bumper:public IGameObject
{
public:
	Bumper();
	~Bumper();
	bool Start();
	void Update();	//更新。
	void Render(RenderContext& rc);
	void Move();															//移動。
	void Rotation();
	void SetPos(Vector3 pos)
	{
		m_position = pos;
	}

	Vector3 GetPos()
	{
		return m_position;
	}
private:
	PhysicsStaticObject			m_Object;
	//モデル表示系。
	ModelRender		m_modelRender;						//モデルレンダ―。
	Vector3			m_position = Vector3::Zero;			//座標。
	Vector3			m_firstPosition = Vector3::Zero;	//最初の座標。

	Game*			m_game;
};

