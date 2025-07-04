#include "stdafx.h"
#include "Stage05.h"
#include "Player.h"
#include "Transform.h"
#include "CountDown.h"

Stage05::Stage05()
{
	m_transform = new Transform();
}

Stage05::~Stage05()
{
	delete m_transform;
}

bool Stage05::Start()
{
	m_modelRender.Init("Assets/Stage5/stage5.tkm");
	m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));
	m_countDown = FindGO<CountDown>("countDown");

	return true;
}

void Stage05::Update()
{
	if (m_countDown->GetShowGO()) {
		return;
	}
	//回転処理
	Rotation();
	//更新処理。
	m_transform->UpdateTransform();
	//モデルの更新処理。
	m_modelRender.Update();
}

void Stage05::Rotation()
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

	// 最終的に出来上がった行列から回転クォータニオンを作る
	m_transform->m_localRotation.SetRotation(mWorld);
	m_transform->m_localPosition.Set(mWorld._41, mWorld._42, mWorld._43);
	//
	m_object.GetBody()->SetPositionAndRotation(m_transform->m_localPosition, m_transform->m_localRotation);
	m_modelRender.SetRotation(m_transform->m_localRotation);
	m_modelRender.SetPosition(m_transform->m_localPosition);
	//モデルレンダーのアップデート
	m_modelRender.Update();
}

void Stage05::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}