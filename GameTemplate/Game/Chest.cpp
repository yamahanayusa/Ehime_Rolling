#include "stdafx.h"
#include "Chest.h"
#include "Chest.h"

Chest::Chest() 
{

}

Chest::~Chest()
{

}

bool Chest::Start() 
{
	//チェストのモデルを読み込む。
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