#include "stdafx.h"
#include "Chest.h"
#include "Game.h"

Chest::Chest()
{

}

Chest::~Chest()
{

}

bool Chest::Start()
{
	//アニメーションクリップをロード。
	m_animationClips[enAnimationClip_Open].Load("Assets/animData/ChestOpen.tka");
	m_animationClips[enAnimationClip_Open].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Close].Load("Assets/animData/ChestClose.tka");
	m_animationClips[enAnimationClip_Close].SetLoopFlag(true);

	m_game = FindGO<Game>("game");

	//モデルの表示。
	m_modelRender.Init("Assets/modelData/Chest.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	m_modelRender.SetScale(3.0f, 3.0f, 3.0f);
	return true;
}

void Chest::Update()
{
	//移動処理。
	Move();

	PlayAnimation();

	//絵描きさんの更新処理。
	m_modelRender.Update();

	//プレイヤーからコインに向かうベクトルを計算。
	//Vector3 diff = m_player->m_position - m_position;

	//ベクトルの長さが120.0fより小さかったら。
	//if (diff.Length() <= 120.0f)
	//{
	//	m_player->m_chestCount += 1;
	//}
}

void Chest::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);

	if (g_pad[0]->IsTrigger(enButtonB))
	{
		m_chestState = 1;
	}
}

void Chest::PlayAnimation()
{
	switch (m_chestState) {
	case 0:
		m_modelRender.PlayAnimation(enAnimationClip_Close);
		break;
	case 1:
		m_modelRender.PlayAnimation(enAnimationClip_Open);
		//アニメーションが再生し終わったらリザルトを出す
		if (m_modelRender.IsPlayingAnimation() == false) {
			m_game->m_gameState = m_game->enResult;
			m_game->GameStateUpdate();
		}
		break;
	}
		
}

void Chest::Render(RenderContext& rc)
{
	//coinを描画する。
	m_modelRender.Draw(rc);
}
