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
	//閭梧勹
	m_ballRender.Init("Assets/modelData/light.tkm");
	m_ballPosition.Set(0.0f, 300.0f, 0.0f);
	m_ballRender.SetPosition(m_ballPosition);
	m_ballRender.SetScale(1.7f, 1.7f, 1.7f);

	//逅・ｽ薙・螟ｧ縺阪＆
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
	// 蜿門ｾ励＠縺滉ｽ咲ｽｮ縺ｨ蝗櫁ｻ｢繧貞渚譏縺輔○繧九・
	m_ballRender.SetPosition(rbPos);
	m_ballRender.SetRotation(rbRot);
	m_ballRender.Update();

	/*if (rbPos.y <= -3000.0f)
	{
		m_game->m_gameState = m_game->enGameOver;
		m_game->GameStateUpdate();
		//DeleteGO(m_game);
	}*/
}


//謠冗判蜃ｦ逅・・
void Player::Render(RenderContext& rc)
{
	m_ballRender.Draw(rc);
}