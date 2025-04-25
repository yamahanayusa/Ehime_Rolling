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
	m_bgModelRendedr.Init("Assets/stage/stage3.tkm");

	m_bgObject.CreateFromModel(m_bgModelRendedr.GetModel(), m_bgModelRendedr.GetWorldMatrix(0));

	return true;

}


void Stage::Update()
{
	//蝗櫁ｻ｢蜃ｦ逅・
	Rotation();

	//繝｢繝・Ν縺ｮ譖ｴ譁ｰ蜃ｦ逅・・
	m_bgModelRendedr.Update();
}

void Stage::Rotation()
{
	Matrix mBias, mRot, mBiasInv, mFinal;
	// 閭梧勹繧偵・繝ｬ繧､繝､繝ｼ遨ｺ髢薙↓遘ｻ蜍輔＆縺帙ｋ陦悟・繧定ｨ育ｮ励☆繧・
	if (m_player == nullptr) {
		m_player = FindGO<Player>("player");
	}
	if (m_player == nullptr) {
		return;
	}

	// 閭梧勹縺ｮ蝗櫁ｻ｢
	//蟾ｦ蜿ｳ譁ｹ蜷代・蛯ｾ縺・
	Vector3 forwardXZ = g_camera3D->GetForward();
	forwardXZ.y = 0.0f;
	forwardXZ.Normalize();
	addRot.SetRotation(forwardXZ, g_pad[0]->GetLStickXF() * -0.006f);
	// 繝励Ξ繧､繝､繝ｼ縺ｮ菴咲ｽｮ縺悟次轤ｹ縺ｫ譚･繧九ｈ縺・↓閭梧勹繧貞虚縺九☆陦悟・繧剃ｽ懈・縺吶ｋ
	mBias.MakeTranslation(m_player->m_ballPosition * -1.0f);
	mBiasInv = mBias;
	// 蜍輔°縺励◆閭梧勹繧偵ｂ縺ｨ縺ｫ謌ｻ縺呵｡悟・繧剃ｽ懈・
	mBiasInv.Inverse();
	// 霑ｽ蜉縺ｧ蝗櫁ｻ｢縺輔○繧玖｡悟・繧剃ｽ懈・
	mRot.MakeRotationFromQuaternion(addRot);
	// 遘ｻ蜍輔＆縺帙◆閭梧勹繧貞屓霆｢縺輔○繧・
	mFinal.Multiply(mBias, mRot);
	// 閭梧勹縺ｮ菴咲ｽｮ繧呈綾縺・
	mFinal.Multiply(mFinal, mBiasInv);

	// 譛邨ら噪縺ｫ蜃ｺ譚･荳翫′縺｣縺溯｡悟・縺九ｉ蝗櫁ｻ｢繧ｯ繧ｩ繝ｼ繧ｿ繝九が繝ｳ繧剃ｽ懊ｋ
	addRot.SetRotation(mFinal);

	m_bgRotation.Multiply(addRot);

	//荳贋ｸ区婿蜷代・蛯ｾ縺・
	Vector3 rightXZ = g_camera3D->GetRight();
	rightXZ.y = 0.0f;
	rightXZ.Normalize();
	addLot.SetRotation(rightXZ, g_pad[0]->GetLStickYF() * 0.006f);

	mRot.MakeRotationFromQuaternion(addLot);
	mFinal.Multiply(mBias, mRot);
	mFinal.Multiply(mFinal, mBiasInv);
	addLot.SetRotation(mFinal);

	m_bgRotation.Multiply(addLot);
	//
	m_bgObject.GetBody()->SetPositionAndRotation(Vector3::Zero, m_bgRotation);
	m_bgModelRendedr.SetRotation(m_bgRotation);
	//繝｢繝・Ν繝ｬ繝ｳ繝繝ｼ縺ｮ繧｢繝・・繝・・繝・
	m_bgModelRendedr.Update();
}

void Stage::Render(RenderContext& rc)
{
	//繝｢繝・Ν繧呈緒逕ｻ縺吶ｋ
	m_bgModelRendedr.Draw(rc);
}