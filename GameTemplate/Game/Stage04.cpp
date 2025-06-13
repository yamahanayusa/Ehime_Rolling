#include "stdafx.h"
#include "Stage04.h"
#include "Player.h"
#include "Transform.h"

Stage04::Stage04()
{
	m_transform = new Transform(); // Transformの生成
}
Stage04::~Stage04()
{
	delete m_transform; // Transformの削除
}
bool Stage04::Start()
{
	m_modelRender.Init("Assets/Stage/stage4.tkm");
	m_Object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));

	return true;
}
void Stage04::Update()
{
	// 回転処理
	Rotation();
	// 更新処理
	m_transform->UpdateTransform();
	// モデルの更新処理
	m_modelRender.Update();
}
void Stage04::Rotation()
{
	// 背景をプレイヤー空間に移動させる行列を計算する
	Matrix mBias, mRot, mBiasInv, mFinal;

	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}

	Matrix mTrans, mWorld;
	mTrans.MakeTranslation(m_transform->m_localPosition);
	mRot.MakeRotationFromQuaternion(m_transform->m_localRotation);
	mWorld = mRot * mTrans;

	// 背景の回転
	//左右方向の傾き
	Vector3 forwardXZ = g_camera3D->GetForward();
	forwardXZ.y = 0.0f;
	forwardXZ.Normalize();
	addRot.SetRotation(forwardXZ, g_pad[0]->GetLStickXF() * -0.006f);
	Vector3 rightXZ = g_camera3D->GetRight();
	rightXZ.y = 0.0f;
	rightXZ.Normalize();
	addLot.SetRotation(rightXZ, g_pad[0]->GetLStickYF() * 0.006f);
	Quaternion qAdd;
	qAdd.Multiply(addRot, addLot);

	// プレイヤーの位置が原点に来るように背景を動かす
	Vector3 playerPos = m_player->m_ballPosition;
	mWorld._41 -= playerPos.x;
	mWorld._42 -= playerPos.y;
	mWorld._43 -= playerPos.z;

	// 追加で回転させる行列を作成
	mRot.MakeRotationFromQuaternion(qAdd);
	mWorld.Multiply(mWorld, mRot);
	// 背景の位置を戻す
	mWorld._41 += playerPos.x;
	mWorld._42 += playerPos.y;
	mWorld._43 += playerPos.z;

	// 最終的に出来上がった行列から回転クォータニオンを作る]
	m_transform->m_localRotation.SetRotation(mWorld);
	m_transform->m_localPosition.Set(mWorld._41, mWorld._42, mWorld._43);
	//
	m_Object.GetBody()->SetPositionAndRotation(m_transform->m_localPosition, m_transform->m_localRotation);
	m_modelRender.SetRotation(m_transform->m_localRotation);
	m_modelRender.SetPosition(m_transform->m_localPosition);
	//モデルレンダーのアップデート
	m_modelRender.Update();
}
void Stage04::Render(RenderContext& rc)
{
	//モデルの描画
	m_modelRender.Draw(rc);
}