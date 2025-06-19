#pragma once
class Game;
class Player;
class Stage04;
class Transform;

class Bumper:public IGameObject
{
public:
	Bumper();
	~Bumper();
	bool Start();
	void Update();						//更新。
	void UpdateModelRenderer();			//絵描きさんの更新処理。
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

private:
	PhysicsStaticObject	m_object;
	ModelRender			m_modelRender;						//モデルレンダ―。
	Vector3				m_position		= Vector3::Zero;	//座標。
	Vector3				m_firstPosition = Vector3::Zero;	//最初の座標。

	Game*				m_game			= nullptr;
	Stage04*			m_stage04		= nullptr;
	Transform*			m_transform		= nullptr;
};

