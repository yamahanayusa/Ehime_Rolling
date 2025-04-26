#include "stdafx.h"
#include "Player.h"
#include "Game.h"

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
	m_ballRender.SetScale(1.7f, 1.7f, 1.7f);

	//球体の大きさ
	m_sphereCollider.Create(17.0f);
	//RigidBodyInitData rbInitData;
	rbInitData.collider = &m_sphereCollider;
	rbInitData.mass = 10.0f;
	rbInitData.pos = m_ballPosition;
	rbInitData.rot = Quaternion::Identity;
	rbInitData.restitution = -100;

	m_rigidBody.Init(rbInitData);
	m_rigidBody.SetFriction(1);

	m_charaCon.Init(0.1f, 0.1f, m_ballPosition);

	m_game = FindGO<Game>("game");
	return true;
}

void Player::Update()
{
	m_rigidBody.GetPositionAndRotation(rbPos, rbRot);
	// 取得した位置と回転を反映させる。
	m_ballRender.SetPosition(rbPos);
	m_ballRender.SetRotation(rbRot);
	m_ballRender.Update();
}


//描画処理。
void Player::Render(RenderContext& rc)
{
	m_ballRender.Draw(rc);
}