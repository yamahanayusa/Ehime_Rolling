#include "stdafx.h"
#include "BaseStage.h" 
#include "Player.h"
#include "Transform.h"
#include "CountDown.h"

BaseStage::BaseStage(const char* modelFilePath)
    : m_modelFilePath(modelFilePath)
{
}

BaseStage::~BaseStage()
{
}

// Startメソッド: Transform* を引数で受け取る
bool BaseStage::Start(Transform* transform)
{
    // 引数で渡された transform を利用して PhysicsStaticObject を初期化
    m_modelRender.Init(m_modelFilePath);
    // transform が nullptr でないことを確認する（安全策）
    if (transform) {
        m_object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0)); // Transform から行列を取得してPhysicsStaticObjectを生成
    }
    else {
        // エラーハンドリング
        MessageBox(nullptr, L"Transform is null in BaseStage::Start!", L"Error", MB_OK | MB_ICONERROR);
        return false;
    }

    m_countDown = FindGO<CountDown>("countDown");

    return true;
}

// Updateメソッド: Transform* を引数で受け取る
void BaseStage::Update(Transform* transform)
{
    if (m_countDown->GetShowGO()) {
        return;
    }
    Rotation(transform); // Rotationにもtransformを渡す
    if (transform) {
        transform->UpdateTransform(); // 引数で渡された transform を更新
    }
    m_modelRender.Update();
}

// Rotationメソッド: Transform* を引数で受け取る
void BaseStage::Rotation(Transform* transform)
{
    if (!transform) return; // transform が nullptr なら処理を中断

    Matrix mBias, mRot, mBiasInv, mFinal;

    if (m_player == nullptr) {
        m_player = FindGO<Player>("player");
    }
    if (m_player == nullptr) {
        return;
    }

    Matrix mTrans, mWorld;
    mTrans.MakeTranslation(transform->m_localPosition); // 引数で渡された transform の位置を使用
    mRot.MakeRotationFromQuaternion(transform->m_localRotation); // 引数で渡された transform の回転を使用
    mWorld = mRot * mTrans;

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

    Vector3 playerPos = m_player->m_ballPosition;
    mWorld._41 -= playerPos.x;
    mWorld._42 -= playerPos.y;
    mWorld._43 -= playerPos.z;

    mRot.MakeRotationFromQuaternion(qAdd);
    mWorld.Multiply(mWorld, mRot);

    mWorld._41 += playerPos.x;
    mWorld._42 += playerPos.y;
    mWorld._43 += playerPos.z;

    // 引数で渡された transform のプロパティを更新
    transform->m_localRotation.SetRotation(mWorld);
    transform->m_localPosition.Set(mWorld._41, mWorld._42, mWorld._43);

    // PhysicsStaticObject と ModelRender の位置・回転も引数で渡された transform から設定
    m_object.GetBody()->SetPositionAndRotation(transform->m_localPosition, transform->m_localRotation);
    m_modelRender.SetRotation(transform->m_localRotation);
    m_modelRender.SetPosition(transform->m_localPosition);
    m_modelRender.Update();
}

// Renderメソッド: Transform* を引数で受け取る（WorldMatrix取得のため）
void BaseStage::Render(RenderContext& rc, Transform* transform)
{
    m_modelRender.Draw(rc);
}