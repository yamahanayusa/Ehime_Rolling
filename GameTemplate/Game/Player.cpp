#include "stdafx.h"
#include "Player.h"
#include "Game.h"
//#include "GameCamera.h"
//2025/03/06更新

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	//プレイヤーの表示
	m_ballRender.Init("Assets/modelData/light.tkm");
	m_ballPosition.Set(0.0f, 300.0f, 0.0f);
	m_ballRender.SetPosition(Vector3(m_ballPosition));
	m_ballRender.SetScale(5.0f, 5.0f, 5.0f);
	return true;
}

void Player::Update()
{
	//移動処理
	//Move();

	//ジャンプ処理
	//PlayerJump();
	//回転処理
	Rotation();
	//モデルの更新
	m_ballRender.Update();


}

void Player::PlayerJump()
{
	if (m_charaCon.IsOnGround())
	{
		//Bボタン推したら
		if (g_pad[0]->IsTrigger(enButtonB))
		{
			//ジャンプする
			m_ballSpeed.y = 120.0f;
		}
	}
	//浮いていたら
	else
	{
		//重力
		//PhysicsWorld::GetInstance()->SetGravity({ 0, -980.0f, 0.0f });
		m_ballSpeed.y -= g;

	}
	Vector3 modelPosition = m_ballPosition;
	//ちょっとだけモデルの座標を挙げる。
	modelPosition.y += 2.5f;
	m_ballRender.SetPosition(modelPosition);

}

void Player::Rotation()
{
	if (fabsf(m_ballSpeed.x) < 0.001f
		&& fabsf(m_ballSpeed.z) < 0.001f) {
		//m_moveSpeed.xとm_moveSpeed.zの絶対値がともに0.001以下ということは
		//このフレームではキャラは移動していないので旋回する必要はない。
		return;
	}
	//atan2はtanθの値を角度(ラジアン単位)に変換してくれる関数。
	//m_moveSpeed.x / m_moveSpeed.zの結果はtanθになる。
	//atan2を使用して、角度を求めている。
	//これが回転角度になる。
	float angle = atan2(-m_ballSpeed.x, m_ballSpeed.z);
	//atanが返してくる角度はラジアン単位なので
	//SetRotationDegではなくSetRotationを使用する。
	m_ballRotation.SetRotationY(-angle);

	//回転を設定する。
	m_ballRender.SetRotation(m_ballRotation);

	//プレイヤーの正面ベクトルを計算する。
	m_forward = Vector3::AxisZ;
	m_ballRotation.Apply(m_forward);
}

//描画処理。
void Player::Render(RenderContext& rc)
{
	//描画する。

	m_ballRender.Draw(rc);
}