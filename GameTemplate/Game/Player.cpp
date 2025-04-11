#include "stdafx.h"
#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{

	//背景
	m_ballRender.Init("Assets/modelData/light.tkm");
	m_ballPosition.Set(0.0f, 300.0f, 0.0f);
	m_ballRender.SetPosition(m_ballPosition);
	m_ballRender.SetScale(2.5f, 2.5f, 2.5f);

	//球体の大きさ
	m_sphereCollider.Create(25.0f);
	//RigidBodyInitData rbInitData;
	rbInitData.collider = &m_sphereCollider;
	rbInitData.mass = 10000000.0f;
	rbInitData.pos = m_ballPosition;
	rbInitData.rot = Quaternion::Identity;
	rbInitData.restitution = -100;

	m_rigidBody.Init(rbInitData);
	m_rigidBody.SetFriction(1);
	return true;
}

void Player::Update()
{


	m_rigidBody.GetPositionAndRotation(rbPos, rbRot);
	// 取得した位置と回転を反映させる。
	m_ballRender.SetPosition(rbPos);
	m_ballRender.SetRotation(rbRot);

	m_ballRender.Update();
	m_ballRender.SetPosition(rbPos);
}


//描画処理。
void Player::Render(RenderContext& rc)
{
	m_ballRender.Draw(rc);
}