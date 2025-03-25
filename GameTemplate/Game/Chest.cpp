#include "stdafx.h"
#include "Chest.h"

Chest::Chest()
{

}

Chest::~Chest()
{

}

bool Chest::Start()
{
	//モデルの表示。
	m_modelRender.Init("Assets/modelData/Chest.tkm");

	return true;
}

void Chest::Update()
{
	//移動処理。
	Move();

	//絵描きさんの更新処理。
	m_modelRender.Update();

	//プレイヤーからコインに向かうベクトルを計算。
	//Vector3 diff = m_player->m_position - m_position;

	//ベクトルの長さが120.0fより小さかったら。
	//if (diff.Length() <= 120.0f)
	//{
	//	m_player->m_coinCount += 1;

	//	//自身を削除する。
	//	DeleteGO(this);
	//}
}

void Chest::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);
}

void Chest::Render(RenderContext& rc)
{
	//coinを描画する。
	m_modelRender.Draw(rc);
}
