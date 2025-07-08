#pragma once

#include "BaseStage.h" // BaseStage を継承するのでインクルード
#include "Transform.h" // Transform を独自に持つので、ここでインクルード

class Stage05 : public BaseStage
{
public:
    // コンストラクタで、基底クラスのコンストラクタにモデルパスを渡す
    Stage05();
    // デストラクタ: 独自の m_transform を削除
    ~Stage05();

    // 基底クラスのメソッドをオーバーライドし、独自の m_transform を渡す
    bool Start() override;
    void Update() override;
    void Rotation(Transform* transform) override;
    void Render(RenderContext& rc) override; // Render も Transform を渡す形にOverride

    // 独自の GetTransform() を実装
    Transform* GetTransform()
    {
        return m_transform;
    }

    Matrix GetWorldMatrix() const
    {
        // 独自の Transform からワールド行列を取得
        if (m_transform) {
            return m_modelRender.GetWorldMatrix(0);
        }
        return Matrix::Identity; // エラー時のデフォルト
    }
    Transform* m_transform = nullptr;
private: // 各ステージが独自の Transform を持つ

};