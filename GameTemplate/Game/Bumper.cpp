#include "stdafx.h"
#include "Bumper.h"
#include "Game.h"
#include "Player.h"
#include "Transform.h"
#include "Stage04.h"

Bumper::Bumper()
{
	m_transform = new Transform();
}

Bumper::~Bumper()
{
	delete m_transform;
}

bool Bumper::Start()
{
	m_modelRender.Init("Assets/modelData/bumper/bumper.tkm");
	//m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));

	m_stage04 = FindGO<Stage04>("stage04");

	m_transform->SetParent(m_stage04->m_transform);
	return true;
}

void Bumper::Update()
{
	//更新処理。
	m_transform->UpdateTransform();

	//絵描きさんの更新処理。
	UpdateModelRenderer();
}

void Bumper::UpdateModelRenderer() 
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Bumper::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
