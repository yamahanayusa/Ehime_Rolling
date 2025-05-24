#include "stdafx.h"
#include "sandFloor.h"
#include "stage.h"
#include "transform.h"

sandFloor::sandFloor()
{
	m_transform = new Transform();
}

sandFloor::~sandFloor() 
{
	delete m_transform;
}

bool sandFloor::Start()
{
	m_modelRender.Init("Assets/modelData/sandfloor.tkm");
	m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));


	m_stage = FindGO<Stage>("stage");

	m_transform->SetParent(m_stage->m_transform);

	return true;
}

void sandFloor::Update()
{
	//XVˆ—B
	m_transform->Update();

	m_modelRender.Update();

	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
}

void sandFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}