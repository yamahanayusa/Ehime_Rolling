#include "stdafx.h"
#include "StageManager.h"
#include "Kiwi.h"
#include "Stage.h"
#include "Mikan.h"
#include "Flag.h"
#include "Bumper.h"
#include "Jakoten.h"
#include "IceFloor.h"
#include "SandFloor.h"
#include "Transform.h"

StageManager::StageManager()
{

}

StageManager::~StageManager()
{

}

bool StageManager::Start()
{

	return true;
}

void StageManager::Update()
{

}

void StageManager::Init(const char* falePath) {
	//レベルの構築
	m_levelRender.Init(falePath, [&](LevelObjectData& objData) {
		//ステージ
		if (objData.EqualObjectName(L"ground") == true) {
			m_stage = NewGO<Stage>(0, "stage");
			m_stage->GetTransform()->m_localPosition.Set(objData.position);
			m_stage->GetTransform()->m_localRotation.Set(objData.rotation);
			m_stage->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//ゴール
		if (objData.EqualObjectName(L"flag") == true) {
			m_flag = NewGO<Flag>(1, "flag");
			m_flag->GetTransform()->m_localPosition.Set(objData.position);
			m_flag->GetTransform()->m_localRotation.Set(objData.rotation);
			m_flag->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//氷の床
		if (objData.EqualObjectName(L"icefloor") == true) {
			m_iceFloor = NewGO<IceFloor>(1, "iceFloor");
			m_iceFloor->GetTransform()->m_localPosition.Set(objData.position);
			m_iceFloor->GetTransform()->m_localRotation.Set(objData.rotation);
			m_iceFloor->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//砂の床
		if (objData.EqualObjectName(L"sandfloor") == true) {
			m_sandFloor = NewGO<SandFloor>(1, "sandFloor");
			m_sandFloor->GetTransform()->m_localPosition.Set(objData.position);
			m_sandFloor->GetTransform()->m_localRotation.Set(objData.rotation);
			m_sandFloor->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//じゃこ天
		if (objData.EqualObjectName(L"jakoten") == true) {
			m_jakoten = NewGO<Jakoten>(1, "jakoten");
			m_jakoten->GetTransform()->m_localPosition.Set(objData.position);
			m_jakoten->GetTransform()->m_localRotation.Set(objData.rotation);
			m_jakoten->GetTransform()->m_localScale.Set(objData.scale);
			return true;
		}
		//アイテム(みかん)
		if (objData.EqualObjectName(L"mikan") == true) {
			auto mikan = NewGO<Mikan>(1, "mikan");
			mikan->GetTransform()->m_localPosition.Set(objData.position);
			mikan->GetTransform()->m_localRotation.Set(objData.rotation);
			mikan->GetTransform()->m_localScale.Set(objData.scale);
			m_mikan.push_back(mikan);
			return true;
		}
		//キウイ
		if (objData.EqualObjectName(L"kiwi") == true) {
			auto kiwi = NewGO<Kiwi>(1, "kiwi");
			kiwi->GetTransform()->m_localPosition.Set(objData.position);
			kiwi->GetTransform()->m_localRotation.Set(objData.rotation);
			kiwi->GetTransform()->m_localScale.Set(objData.scale);
			m_kiwi.push_back(kiwi);
			return true;
		}
		//バンパー
		if (objData.EqualObjectName(L"bumper") == true) {
			auto bumper = NewGO<Bumper>(1, "bumper");
			bumper->GetTransform()->m_localPosition.Set(objData.position);
			bumper->GetTransform()->m_localRotation.Set(objData.rotation);
			bumper->GetTransform()->m_localScale.Set(objData.scale);
			m_bumper.push_back(bumper);
			return true;
		}
	});
}

