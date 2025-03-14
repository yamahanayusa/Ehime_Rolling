#pragma once

class Player;
class Chest :public IGameObject
{
public:
	Chest();
	~Chest();
	bool Start();
	void Update();					//更新処理。
	void Render(RenderContext& rc);	//描画処理。
	void Move();					//移動処理。

	ModelRender m_modelRender;		//モデルレンダ―。
	Vector3 m_position;				//座標。
	Vector3 m_firstPosition;		//最初の座標。

	//Player* m_player;				//プレイヤー。
};

