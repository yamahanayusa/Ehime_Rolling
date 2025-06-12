#include "stdafx.h"
#include "sandFloor.h"
#include "stage.h"
#include "Transform.h"

SandFloor::SandFloor()
{
	m_transform = new Transform();
}

SandFloor::~SandFloor() 
{
	delete m_transform;
}

bool SandFloor::Start()
{
	m_modelRender.Init("Assets/modelData/sandFloor.tkm");
	m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));

	m_stage = FindGO<Stage>("stage");

	m_transform->SetParent(m_stage->m_transform);

	return true;
}

void SandFloor::Update()
{
	//更新処理。
	m_transform->UpdateTransform();

	//絵描きさんの更新処理。
	UpdateModelRenderer();
}

void SandFloor::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	m_object.SetPositionAndRotation(m_transform->m_position, m_transform->m_rotation);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}


void SandFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}