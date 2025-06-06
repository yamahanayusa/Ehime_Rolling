#include "stdafx.h"
#include "sandFloor.h"
#include "stage04.h"
#include"Player.h"
#include "transform.h"

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

	m_stage04 = FindGO<Stage04>("stage04");

	m_transform->SetParent(m_stage04->m_transform);

	return true;
}

void SandFloor::Update()
{
	Slide();
	//更新処理。
	m_transform->Update();

	//絵描きさんの更新処理。
	UpdateModelRenderer();
}

void SandFloor::Slide()
{
	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}
	//プレイヤーと砂の床の距離感を求める
	Vector3 distance = m_player->rbPos - m_position;
	if (distance.Length() < 150.0f)
	{
		m_player->rbInitData.mass = 10000000.0f;
		m_player->rbInitData.restitution = -1000000;
		m_player->m_rigidBody.SetFriction(100000000);
	}
}

void SandFloor::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->GetPosition());
	m_modelRender.SetRotation(m_transform->GetRotation());
	m_modelRender.SetScale(m_transform->GetScale());
	m_object.SetPositionAndRotation(m_transform->m_position, m_transform->m_rotation);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}


void SandFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}