#include "stdafx.h"
#include "IceFloor.h"
#include "Player.h"

IceFloor::IceFloor()
{

}

IceFloor::~IceFloor()
{

}

bool IceFloor::Start()
{
	m_modelRender.SetScale(7.0f, 7.0f, 7.0f);
	m_modelRender.Init("Assets/modelData/icefloor.tkm");
	m_Object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));


	return true;
}

void IceFloor::Update()
{
	//‰ñ“]ˆ—
	Rotation();

	m_modelRender.Update();
}

void IceFloor::Rotation()
{
	Matrix mBias, mRot, mBiasInv, mFinal;
	// ”wŒi‚ğƒvƒŒƒCƒ„[‹óŠÔ‚ÉˆÚ“®‚³‚¹‚és—ñ‚ğŒvZ‚·‚é
	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}

	// ”wŒi‚Ì‰ñ“]
	//¶‰E•ûŒü‚ÌŒX‚«
	Vector3 forwardXZ = g_camera3D->GetForward();
	forwardXZ.y = 0.0f;
	forwardXZ.Normalize();
	addRot.SetRotation(forwardXZ, g_pad[0]->GetLStickXF() * -0.005f);
	// ƒvƒŒƒCƒ„[‚ÌˆÊ’u‚ªŒ´“_‚É—ˆ‚é‚æ‚¤‚É”wŒi‚ğ“®‚©‚·s—ñ‚ğì¬‚·‚é
	mBias.MakeTranslation(m_player->m_ballPosition * -1.0f);
	mBiasInv = mBias;
	// “®‚©‚µ‚½”wŒi‚ğ‚à‚Æ‚É–ß‚·s—ñ‚ğì¬
	mBiasInv.Inverse();
	// ’Ç‰Á‚Å‰ñ“]‚³‚¹‚és—ñ‚ğì¬
	mRot.MakeRotationFromQuaternion(addRot);
	// ˆÚ“®‚³‚¹‚½”wŒi‚ğ‰ñ“]‚³‚¹‚é
	mFinal.Multiply(mBias, mRot);
	// ”wŒi‚ÌˆÊ’u‚ğ–ß‚·
	mFinal.Multiply(mFinal, mBiasInv);

	// ÅI“I‚Éo—ˆã‚ª‚Á‚½s—ñ‚©‚ç‰ñ“]ƒNƒH[ƒ^ƒjƒIƒ“‚ğì‚é
	addRot.SetRotation(mFinal);

	m_Rotation.Multiply(addRot);

	//ã‰º•ûŒü‚ÌŒX‚«
	Vector3 rightXZ = g_camera3D->GetRight();
	rightXZ.y = 0.0f;
	rightXZ.Normalize();
	addLot.SetRotation(rightXZ, g_pad[0]->GetLStickYF() * 0.005f);

	mRot.MakeRotationFromQuaternion(addLot);
	mFinal.Multiply(mBias, mRot);
	mFinal.Multiply(mFinal, mBiasInv);
	addLot.SetRotation(mFinal);

	m_Rotation.Multiply(addLot);
	//
	m_Object.GetBody()->SetPositionAndRotation(Vector3::Zero, m_Rotation);
	m_modelRender.SetRotation(m_Rotation);
	m_modelRender.Update();
}

void IceFloor::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
