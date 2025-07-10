#pragma once
#include <vector>
#include <memory> // std::unique_ptrを使用するため
// #include "GameObject.h" // IGameObjectの定義元を仮定

class Game; // Gameクラスの前方宣言

// 各ステージボタンの情報を保持する構造体
struct StageButtonInfo {
    const char* imagePath;
    float posX;
    float posY;
};

class StageSelect : public IGameObject
{
public:
    StageSelect();
    ~StageSelect();
    bool Start() override;
    void Update() override;
    void Render(RenderContext& rc) override;

private:
    SpriteRender m_backgroundSprite; // 背景用
    SpriteRender m_cursorSprite;     // カーソル用

    // ステージ画像用のSpriteRenderをunique_ptrのベクターで管理
    std::vector<std::unique_ptr<SpriteRender>> m_stageSprites; // ここをUnique_ptrに変更

    int m_currentSelection = 0; // 現在選択中のステージボタンのインデックス (0-based)

    static constexpr StageButtonInfo STAGE_BUTTON_INFOS[] = {
        {"Assets/StageSelect/one.dds",  -500.0f, 100.0f}, // Stage 1
        {"Assets/StageSelect/Two.dds",  0.0f,    100.0f}, // Stage 2
        {"Assets/StageSelect/Three.dds", 500.0f,  100.0f}, // Stage 3
        {"Assets/StageSelect/Four.dds", -300.0f, -200.0f}, // Stage 4
        {"Assets/StageSelect/Five.dds", 300.0f,  -200.0f}  // Stage 5
    };
    static constexpr int NUM_STAGES = sizeof(STAGE_BUTTON_INFOS) / sizeof(STAGE_BUTTON_INFOS[0]);
};