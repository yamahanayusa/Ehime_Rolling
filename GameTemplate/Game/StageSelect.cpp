#include "stdafx.h"
#include "StageSelect.h"
#include "Game.h" 

StageSelect::StageSelect()
{
    // 画像を読み込む
    m_spriteRender.Init("Assets/StageSelect/Select.dds", 1920.0f, 1080.0f); //
    m_spriteRender.SetPosition({ 0.0f, 0.0f, 0.0f }); //
    m_spriteRender.SetScale({ 1.0f, 1.0f, 1.0f }); //
    m_spriteRender.Update(); //

    m_spriteRender0.Init("Assets/StageSelect/black.dds", 315.0f, 165.0f); //
    // カーソルの初期位置を設定 (m_button=0, つまりステージ選択なし、または最初のステージ)
    // ここでは、デフォルトでステージ1の位置にカーソルを置くことにします。
    m_spriteRender0.SetPosition({ -500.0f, 100.0f, 0.0f }); // ステージ1の位置
    m_spriteRender0.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender0.Update(); //

    m_spriteRender1.Init("Assets/StageSelect/one.dds", 300.0f, 150.0f); //
    m_spriteRender1.SetPosition({ -500.0f, 100.0f, 0.0f }); //
    m_spriteRender1.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender1.Update(); //

    m_spriteRender2.Init("Assets/StageSelect/Two.dds", 300.0f, 150.0f); //
    m_spriteRender2.SetPosition({ 0.0f, 100.0f, 0.0f }); //
    m_spriteRender2.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender2.Update(); //

    m_spriteRender3.Init("Assets/StageSelect/Three.dds", 300.0f, 150.0f); //
    m_spriteRender3.SetPosition({ 500.0f, 100.0f, 0.0f }); //
    m_spriteRender3.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender3.Update(); //

    m_spriteRender4.Init("Assets/StageSelect/Four.dds", 300.0f, 150.0f); //
    m_spriteRender4.SetPosition({ -300.0f, -200.0f, 0.0f }); //
    m_spriteRender4.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender4.Update(); //

    m_spriteRender5.Init("Assets/StageSelect/Five.dds", 300.0f, 150.0f); //
    m_spriteRender5.SetPosition({ 300.0f, -200.0f, 0.0f }); //
    m_spriteRender5.SetScale({ 1.5f, 1.5f, 1.0f }); //
    m_spriteRender5.Update(); //

    // 初期選択ステージを1に設定
    m_button = 1; // ステージ1から開始
    m_selectedStage = 1; // 選択ステージも1に設定
}

StageSelect::~StageSelect()
{
    // StageSelectがGameオブジェクトを直接生成・所有しないため、
    // ここでDeleteGO(m_game)は呼び出しません。
}

bool StageSelect::Start()
{
    return true;
}

void StageSelect::Update()
{
    if (g_pad[0]->IsTrigger(enButtonRight))
    {
        m_button++;
        // 5つのステージ（1-5）なので、5の次は1に戻る
        if (m_button > 5) {
            m_button = 1; // ステージ1に戻る
        }

        // m_selectedStage に選択されたステージ番号を格納
        m_selectedStage = m_button;

        // カーソル (m_spriteRender0) の位置を更新
        switch (m_button)
        {
        case 1:
            m_spriteRender0.SetPosition({ -500.0f, 100.0f, 0.0f }); //
            break;
        case 2:
            m_spriteRender0.SetPosition({ 0.0f, 100.0f, 0.0f }); //
            break;
        case 3:
            m_spriteRender0.SetPosition({ 500.0f, 100.0f, 0.0f }); //
            break;
        case 4:
            m_spriteRender0.SetPosition({ -300.0f, -200.0f, 0.0f }); //
            break;
        case 5:
            m_spriteRender0.SetPosition({ 300.0f, -200.0f, 0.0f }); //
            break;
        default:
            // m_buttonは1-5の範囲に制御されているので、通常ここには来ない
            break;
        }
        m_spriteRender0.Update(); //
    }

    if (g_pad[0]->IsTrigger(enButtonLeft))
    {
        m_button--;
        // 5つのステージ（1-5）なので、5の次は1に戻る
        if (m_button < 1) {
            m_button = 5; // ステージ1に戻る
        }

        // m_selectedStage に選択されたステージ番号を格納
        m_selectedStage = m_button;

        // カーソル (m_spriteRender0) の位置を更新
        switch (m_button)
        {
        case 1:
            m_spriteRender0.SetPosition({ -500.0f, 100.0f, 0.0f }); //
            break;
        case 2:
            m_spriteRender0.SetPosition({ 0.0f, 100.0f, 0.0f }); //
            break;
        case 3:
            m_spriteRender0.SetPosition({ 500.0f, 100.0f, 0.0f }); //
            break;
        case 4:
            m_spriteRender0.SetPosition({ -300.0f, -200.0f, 0.0f }); //
            break;
        case 5:
            m_spriteRender0.SetPosition({ 300.0f, -200.0f, 0.0f }); //
            break;
        default:
            // m_buttonは1-5の範囲に制御されているので、通常ここには来ない
            break;
        }
        m_spriteRender0.Update(); //
    }

    if (g_pad[0]->IsTrigger(enButtonA)) //
    {
        // Aボタンが押されたら、選択されたステージでゲームを開始
        // ここで初めてGameオブジェクトを生成します。
        Game* newGame = NewGO<Game>(0, "game"); //

        // 生成されたGameオブジェクトに、選択されたステージ番号を渡します。
        if (newGame) { //
            newGame->m_state = m_selectedStage; // Gameクラスのm_stateに直接代入
        }

        // StageSelectオブジェクトは役割を終えたので削除します。
        DeleteGO(this); //
    }
}

void StageSelect::Render(RenderContext& rc)
{
    //画像を描画する。
    m_spriteRender.Draw(rc); //
    m_spriteRender0.Draw(rc); //
    m_spriteRender1.Draw(rc); //
    m_spriteRender2.Draw(rc); //
    m_spriteRender3.Draw(rc); //
    m_spriteRender4.Draw(rc); //
    m_spriteRender5.Draw(rc); //
}