#include "stdafx.h"
#include "Stage01.h"


Stage01::~Stage01()
{

}

bool Stage01::Start()
{

	m_modelRender.Init("Assets/Stage01/stage.tkm");
	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale(m_scale);
	m_modelRender.SetRotation(m_rotation);
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	
	return true;

}
void Stage01::Update()
{
	//回転処理
	//Rotation();

	//モデルの更新処理。
	m_modelRender.Update();
}

void Stage01::Render(RenderContext& rc)
{
	//モデルを描画する
	m_modelRender.Draw(rc);
}