#pragma once

// 前方宣言はそのまま
class Player;
class Transform; // Transform クラスの完全な定義は必要だが、ここではポインタで使用
class CountDown;

// IGameObject を継承し、すべてのステージの基底となるクラス
class BaseStage : public IGameObject
{
public:
    // コンストラクタ: ステージモデルのパスを受け取るように変更
    BaseStage(const char* modelFilePath);

    // デストラクタ
    virtual ~BaseStage();

    // 各メソッドに Transform* を引数として追加
    // これにより、派生クラスから渡された Transform を操作する
    virtual bool Start(Transform* transform); // Transform を Start 時にも使用する可能性を考慮
    virtual void Update(Transform* transform);
    virtual void Rotation(Transform* transform);
    virtual void Render(RenderContext& rc, Transform* transform); // Render 時も Transform が必要なので追加

protected:
    ModelRender         m_modelRender;
    PhysicsStaticObject m_object;

    Vector3             m_scale = Vector3::One;
    Quaternion          addRot = Quaternion::Identity;
    Quaternion          addLot = Quaternion::Identity;

    Player* m_player = nullptr;
    CountDown* m_countDown = nullptr;
    const char* m_modelFilePath;
};