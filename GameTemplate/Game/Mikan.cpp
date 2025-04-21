#include "stdafx.h"
#include "Mikan.h"
#include "stdafx.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"

Mikan::Mikan()
{

}

Mikan::~Mikan()
{

}

bool Mikan::Start()
{



	//モデルの表示。	


	m_modelRender.SetScale(1.0f, 1.0f, 1.0f);
	m_modelRender.Init("Assets/modelData/mikan.tkm");
	m_Object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));

	m_game = FindGO<Game>("game");
	m_score = FindGO<Score>("score");
	return true;
}



void Mikan::Update()
{
	m_player = FindGO<Player>("Player");
	//移動処理。
	Move();

	Rotation();

	//絵描きさんの更新処理。
	m_modelRender.Update();
	//プレイヤーがみかんに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_position;
	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f)
	{
		m_score->m_resultScore += 100;
		DeleteGO(this);
	}


}

void Mikan::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);

}

void Mikan::Rotation() {
	Matrix mBias, mRot, mBiasInv, mFinal;
	// 背景をプレイヤー空間に移動させる行列を計算する
	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}

	// 背景の回転
	//左右方向の傾き
	Vector3 forwardXZ = g_camera3D->GetForward();
	forwardXZ.y = 0.0f;
	forwardXZ.Normalize();
	addRot.SetRotation(forwardXZ, g_pad[0]->GetLStickXF() * -0.006f);
	// プレイヤーの位置が原点に来るように背景を動かす行列を作成する
	mBias.MakeTranslation(m_player->m_ballPosition * -1.0f);
	mBiasInv = mBias;
	// 動かした背景をもとに戻す行列を作成
	mBiasInv.Inverse();
	// 追加で回転させる行列を作成
	mRot.MakeRotationFromQuaternion(addRot);
	// 移動させた背景を回転させる
	mFinal.Multiply(mBias, mRot);
	// 背景の位置を戻す
	mFinal.Multiply(mFinal, mBiasInv);

	// 最終的に出来上がった行列から回転クォータニオンを作る
	addRot.SetRotation(mFinal);

	m_Rotation.Multiply(addRot);

	//上下方向の傾き
	Vector3 rightXZ = g_camera3D->GetRight();
	rightXZ.y = 0.0f;
	rightXZ.Normalize();
	addLot.SetRotation(rightXZ, g_pad[0]->GetLStickYF() * 0.006f);

	mRot.MakeRotationFromQuaternion(addLot);
	mFinal.Multiply(mBias, mRot);
	mFinal.Multiply(mFinal, mBiasInv);
	addLot.SetRotation(mFinal);

	m_Rotation.Multiply(addLot);
	m_Object.GetBody()->SetPositionAndRotation(m_position, m_Rotation);
	m_modelRender.SetRotation(m_Rotation);
	m_modelRender.Update();
}

void Mikan::Render(RenderContext& rc)
{
	//coinを描画する。
	m_modelRender.Draw(rc);
}
