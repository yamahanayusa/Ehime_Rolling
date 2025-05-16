#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{

}

Transform::~Transform()
{

}

bool Transform::Start()
{
	return true;
}

void Transform::Update()
{
	//親がいるなら。
	if (m_parent != nullptr) 
	{
		// 親のワールド行列を取得。
		Matrix mStageParentMat, parentTransMat, parentScalMat, parentRotMat, parentWorldMat;
		parentTransMat.MakeTranslation(m_parent->m_position);
		parentScalMat.MakeScaling(m_parent->m_scale);
		parentRotMat.MakeRotationFromQuaternion(m_parent->m_rotation);
		mStageParentMat.Multiply(parentScalMat, parentRotMat);
		parentWorldMat.Multiply(mStageParentMat, parentTransMat);
		////自分のローカル座標* 親のワールド行列。
		//mStageParentMat.Multiply(mStageParentMat, mTrans);
		////自分のローカルスケール*親のスケール。
		//mStageParentMat.Multiply(mStageParentMat, mScale);
		////自分のローカル回転*親の回転。
		//mStageParentMat.Multiply(mStageParentMat, mRot);

		//平行移動行列を作成。
		// 親のワールド行列に自身の平行移動行列を足して、ワールド座標を取得するため。
		Matrix mTrans;
		mTrans.MakeTranslation(m_localPosition);
		// 座標更新
		Matrix pos;
		pos.Multiply(mTrans, mStageParentMat);
		m_position.Set(pos.m[3][0], pos.m[3][1], pos.m[3][2]);

		// 拡縮
		m_scale = m_localScale;
		m_scale.x *= m_parent->m_scale.x;
		m_scale.y *= m_parent->m_scale.y;
		m_scale.z *= m_parent->m_scale.z;

		// 回転
		m_rotation = m_localRotation;
		m_rotation.Add(m_parent->m_rotation);
	}

	else
	{
		m_position = m_localPosition;
		m_scale = m_localScale;
		m_rotation = m_localRotation;
	}
}
