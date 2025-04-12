#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{

}

Stage::~Stage()
{

}

bool Stage::Start()
{

	m_bgModelRendedr.SetScale(7.0f, 7.0f, 7.0f);
	m_bgModelRendedr.Init("Assets/Stage01/stage 1.tkm");

	m_bgObject.CreateFromModel(m_bgModelRendedr.GetModel(), m_bgModelRendedr.GetWorldMatrix(0));

	return true;

}


void Stage::Update()
{
	//回転処理
	Rotation();

	//モデルの更新処理。
	m_bgModelRendedr.Update();
}

void Stage::Rotation()
{

	// 背景の回転
	//左右方向の傾き
	addRot.SetRotationZ(g_pad[0]->GetLStickXF() * 0.005f);
	m_bgRotation.Multiply(addRot);
	m_bgObject.GetBody()->SetPositionAndRotation(Vector3::Zero, m_bgRotation);

	//上下方向の傾き
	addLot.SetRotationX(g_pad[0]->GetLStickYF() * -0.005f);
	m_bgRotation.Multiply(addLot);
	//
	m_bgModelRendedr.SetRotation(m_bgRotation);
	//モデルレンダーのアップデート
	m_bgModelRendedr.Update();
}

void Stage::Render(RenderContext& rc)
{
	//モデルを描画する
	m_bgModelRendedr.Draw(rc);
}