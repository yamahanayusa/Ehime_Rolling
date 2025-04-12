#include "stdafx.h"
#include "IceFloor.h"

IceFloor::IceFloor()
{

}

IceFloor::~IceFloor()
{

}

bool IceFloor::Start()
{
	m_modelRender.SetScale(7.0f, 7.0f, 7.0f);
	m_modelRender.Init("Assets/modelData/icefloor.tkm");
	m_Object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));


	return true;
}

void IceFloor::Update()
{
	//回転処理
	Rotation();

	m_modelRender.Update();
}

void IceFloor::Rotation()
{
	// 背景の回転
	//左右方向の傾き
	addRot.SetRotationZ(g_pad[0]->GetLStickXF() * 0.005f);
	m_Rotation.Multiply(addRot);
	m_Object.GetBody()->SetPositionAndRotation(Vector3::Zero, m_Rotation);

	//上下方向の傾き
	addLot.SetRotationX(g_pad[0]->GetLStickYF() * -0.005f);
	m_Rotation.Multiply(addLot);
	//
	m_modelRender.SetRotation(m_Rotation);
	//モデルレンダーのアップデート
	m_modelRender.Update();
}

void IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
