#include "stdafx.h"
#include "StageSelect.h"
#include "Game.h"

StageSelect::StageSelect()
{
    // 背景画像の初期化 (変更なし)
    m_backgroundSprite.Init("Assets/StageSelect/Select.dds", 1920.0f, 1080.0f);
    m_backgroundSprite.SetPosition({ 0.0f, 0.0f, 0.0f });
    m_backgroundSprite.SetScale({ 1.0f, 1.0f, 1.0f });
    m_backgroundSprite.Update();

    // カーソル画像の初期化 (変更なし)
    m_cursorSprite.Init("Assets/StageSelect/yellow.dds", 315.0f, 165.0f);
    m_cursorSprite.SetScale({ 1.5f, 1.5f, 1.0f });

    // 各ステージ画像の初期化をループで行う
    // m_stageSprites.resize(NUM_STAGES); // unique_ptrの場合はresizeではなくemplace_backやpush_back
    for (int i = 0; i < NUM_STAGES; ++i) {
        const StageButtonInfo& info = STAGE_BUTTON_INFOS[i];

        // 新しいSpriteRenderオブジェクトをヒープに作成し、unique_ptrで管理
        std::unique_ptr<SpriteRender> sprite = std::make_unique<SpriteRender>();
        sprite->Init(info.imagePath, 300.0f, 150.0f);
        sprite->SetPosition({ info.posX, info.posY, 0.0f });
        sprite->SetScale({ 1.5f, 1.5f, 1.0f });
        sprite->Update();

        m_stageSprites.push_back(std::move(sprite)); // unique_ptrはムーブセマンティクスで追加
    }

    // 初期選択ステージを設定 (0-based index)
    m_currentSelection = 0; // デフォルトで最初のステージ (ステージ1) を選択
    // カーソルを初期位置に設定
    m_cursorSprite.SetPosition({
        STAGE_BUTTON_INFOS[m_currentSelection].posX,
        STAGE_BUTTON_INFOS[m_currentSelection].posY,
        0.0f
        });
    m_cursorSprite.Update();
}

StageSelect::~StageSelect()
{
    // unique_ptrを使用しているため、明示的なdeleteは不要
    // m_stageSpritesの要素はunique_ptrが自動的に解放します
}

bool StageSelect::Start()
{
    return true;
}

void StageSelect::Update()
{
    bool selectionChanged = false;

    if (g_pad[0]->IsTrigger(enButtonRight))
    {
        m_currentSelection++;
        if (m_currentSelection >= NUM_STAGES) {
            m_currentSelection = 0; // 最初に戻る
        }
        selectionChanged = true;
    }

    if (g_pad[0]->IsTrigger(enButtonLeft))
    {
        m_currentSelection--;
        if (m_currentSelection < 0) {
            m_currentSelection = NUM_STAGES - 1; // 最後に戻る
        }
        selectionChanged = true;
    }

    if (selectionChanged) {
        const StageButtonInfo& currentInfo = STAGE_BUTTON_INFOS[m_currentSelection];
        m_cursorSprite.SetPosition({ currentInfo.posX, currentInfo.posY, 0.0f });
        m_cursorSprite.Update();
    }

    if (g_pad[0]->IsTrigger(enButtonA))
    {
        Game* newGame = NewGO<Game>(0, "game");

        if (newGame) {
            newGame->m_state = m_currentSelection + 1;
        }

        DeleteGO(this);
    }
}

void StageSelect::Render(RenderContext& rc)
{
    m_backgroundSprite.Draw(rc);
    m_cursorSprite.Draw(rc);

    // unique_ptrのポインタをデリファレンスしてDrawを呼び出す
    for (const auto& spritePtr : m_stageSprites) { // auto& でユニークポインタの参照を取得
        spritePtr->Draw(rc); // ->演算子でポインタ先のSpriteRenderオブジェクトにアクセス
    }
}