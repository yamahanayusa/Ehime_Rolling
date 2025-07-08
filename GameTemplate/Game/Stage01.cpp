#include "stdafx.h"
#include "Stage01.h" 

Stage01::Stage01()
// BaseStage のコンストラクタを呼び出し、Stage1 のモデルパスを渡す
    : BaseStage("Assets/Stage1/stage1.tkm")
{
    // ここで Stage01 独自の m_transform を生成
    m_transform = new Transform();
}

Stage01::~Stage01()
{
    // ここで Stage01 独自の m_transform を削除
    delete m_transform;
}

// Start メソッドをオーバーライド: BaseStage の Start に自身の m_transform を渡す
bool Stage01::Start()
{
    return BaseStage::Start(m_transform); // BaseStage::Start に m_transform を渡す
}

// Update メソッドをオーバーライド: BaseStage の Update に自身の m_transform を渡す
void Stage01::Update()
{
    BaseStage::Update(m_transform); // BaseStage::Update に m_transform を渡す
}

// Rotation メソッドをオーバーライド: BaseStage の Rotation に自身の m_transform を渡す
void Stage01::Rotation(Transform* transform) // ここに Transform* transform を追加
{
    BaseStage::Rotation(transform); // BaseStage::Rotation に引数を渡す
}

// Render メソッドをオーバーライド: BaseStage の Render に自身の m_transform を渡す
void Stage01::Render(RenderContext& rc)
{
    BaseStage::Render(rc, m_transform); // BaseStage::Render に m_transform を渡す
}