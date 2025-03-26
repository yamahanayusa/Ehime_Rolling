#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include <cmath>

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	//アニメーションをロードする


	//モデルレンダーを初期化
	m_modelRender.Init("", m_animationClips, enAnimationClip_Num);

	m_modelRender.SetPosition(m_position);
	m_modelRender.SetScale(m_scale);

	m_charaCon.Init(
		2.0f,			//半径。
		10.0f,			//高さ。
		m_position		//座標。
	);
	m_game = FindGO<Game>("game");
	return true;
}

void Player::Update()
{
	//移動処理
	Move();

	//ジャンプ処理
	PlayerJump();
	m_modelRender.Update();
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

void Player::Move()
{

}

void Player::PlayerJump()
{
	//もし地面に付いていたら
	if (m_charaCon.IsOnGround())
	{
		//Bボタン推したら
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			//ジャンプする
			m_moveSpeed.y = 120.0f;
		}
	}
	//浮いているとき
	else
	{
		m_moveSpeed.y -= 10;
	}
}

