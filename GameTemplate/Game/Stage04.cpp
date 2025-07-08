#include "stdafx.h"
#include "Stage04.h" 

Stage04::Stage04()
// BaseStage のコンストラクタを呼び出し、Stage4 のモデルパスを渡す
    : BaseStage("Assets/Stage4/stage4.tkm")
{
    // ここで Stage04 独自の m_transform を生成
    m_transform = new Transform();
}

Stage04::~Stage04()
{
    // ここで Stage04 独自の m_transform を削除
    delete m_transform;
}

// Start メソッドをオーバーライド: BaseStage の Start に自身の m_transform を渡す
bool Stage04::Start()
{
    return BaseStage::Start(m_transform); // BaseStage::Start に m_transform を渡す
}

// Update メソッドをオーバーライド: BaseStage の Update に自身の m_transform を渡す
void Stage04::Update()
{
    BaseStage::Update(m_transform); // BaseStage::Update に m_transform を渡す
}

// Rotation メソッドをオーバーライド: BaseStage の Rotation に自身の m_transform を渡す
void Stage04::Rotation(Transform* transform) // ここに Transform* transform を追加
{
    BaseStage::Rotation(transform); // BaseStage::Rotation に引数を渡す
}

// Render メソッドをオーバーライド: BaseStage の Render に自身の m_transform を渡す
void Stage04::Render(RenderContext& rc)
{
    BaseStage::Render(rc, m_transform); // BaseStage::Render に m_transform を渡す
}