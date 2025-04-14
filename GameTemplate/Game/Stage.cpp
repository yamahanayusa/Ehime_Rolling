#include "stdafx.h"
#include "Stage.h"
#include "Player.h"

Stage::Stage()
{

}

Stage::~Stage()
{

}

bool Stage::Start()
{

	m_bgModelRendedr.SetScale(7.0f, 7.0f, 7.0f);
	m_bgModelRendedr.Init("Assets/stage01/stage01.tkm");

	m_bgObject.CreateFromModel(m_bgModelRendedr.GetModel(), m_bgModelRendedr.GetWorldMatrix(0));

	return true;

}


void Stage::Update()
{
	//回転処理
	Rotation();

	//モデルの更新処理。
	m_bgModelRendedr.Update();
}

void Stage::Rotation()
{
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
	addRot.SetRotationZ(g_pad[0]->GetLStickXF() * 0.006f);
	m_bgRotation.Multiply(addRot);
	m_bgObject.GetBody()->SetPositionAndRotation(Vector3::Zero, m_bgRotation);
	Vector3 forwardXZ = g_camera3D->GetForward();
	forwardXZ.y = 0.0f;
	forwardXZ.Normalize();
	addRot.SetRotation(forwardXZ, g_pad[0]->GetLStickXF() * -0.005f);
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

	m_bgRotation.Multiply(addRot);
	
	//上下方向の傾き
	addLot.SetRotationX(g_pad[0]->GetLStickYF() * -0.006f);
	Vector3 rightXZ = g_camera3D->GetRight();
	rightXZ.y = 0.0f;
	rightXZ.Normalize();
	addLot.SetRotation(rightXZ, g_pad[0]->GetLStickYF() * 0.005f);

	mRot.MakeRotationFromQuaternion(addLot);
	mFinal.Multiply(mBias, mRot);
	mFinal.Multiply(mFinal, mBiasInv);
	addLot.SetRotation(mFinal);

	m_bgRotation.Multiply(addLot);
	//
	m_bgObject.GetBody()->SetPositionAndRotation(Vector3::Zero, m_bgRotation);
	m_bgModelRendedr.SetRotation(m_bgRotation);
	//モデルレンダーのアップデート
	m_bgModelRendedr.Update();
}

void Stage::Render(RenderContext& rc)
{
	//モデルを描画する
	m_bgModelRendedr.Draw(rc);
}