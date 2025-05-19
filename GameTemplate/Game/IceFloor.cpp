#include "stdafx.h"
#include "IceFloor.h"
#include "Player.h"
#include "Stage.h"
#include "Transform.h"

IceFloor::IceFloor()
{
	m_transform = new Transform();
}

IceFloor::~IceFloor()
{
	delete m_transform;
}

bool IceFloor::Start()
{
	m_modelRender.Init("Assets/modelData/icefloor.tkm");
	m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));

	m_stage = FindGO<Stage>("stage");

	m_transform->SetParent(m_stage->m_transform);

	return true;
}

void IceFloor::Update()
{
	//滑る処理。
	Slide();

	//更新処理。
	m_transform->Update();

	m_modelRender.Update();

	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
}

void IceFloor::Slide()
{
  	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}
	//プレイヤーと氷の道の距離感を求める
	Vector3 distance = m_player->rbPos - m_icepos;
	if (distance.Length() < 150.0f)
	{
		m_player->rbInitData.mass = 0.0f;
		m_player->rbInitData.restitution = 1000;
		m_player->m_rigidBody.SetFriction(0);
	}
}

void IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
