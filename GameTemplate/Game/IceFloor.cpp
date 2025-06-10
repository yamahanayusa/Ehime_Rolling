#include "stdafx.h"
#include "IceFloor.h"
#include "Player.h"
#include "Stage03.h"
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

	m_stage03 = FindGO<Stage03>("stage03");

	m_transform->SetParent(m_stage03->m_transform);

	return true;
}

void IceFloor::Update()
{
	//滑る処理。
	Slide();

	//絵描きさんの更新処理。
	UpdateModelRenderer();

	//更新処理。
	m_transform->Update();

	//絵描きさんの更新処理。
	UpdateModelRenderer();
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

void IceFloor::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->GetPosition());
	m_modelRender.SetRotation(m_transform->GetRotation());
	m_modelRender.SetScale(m_transform->GetScale());
	m_object.SetPositionAndRotation(m_transform->m_position, m_transform->m_rotation);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
