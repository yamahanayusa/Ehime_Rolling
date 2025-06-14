#include "stdafx.h"
#include "CountDown.h"

CountDown::CountDown()
{ 

}

CountDown::~CountDown()
{

}

bool CountDown::Start() 
{
    return true;
}

void CountDown::Update() 
{
    //毎フレームの経過時間を加算。
    m_timer += g_gameTime->GetFrameDeltaTime();

    if (m_timer >= m_interval && m_currentCount > 0) {
        m_timer = 0.0f;      //タイマーリセット。
        m_fadeTimer = 0.0f;  //フェードリセット。
        m_currentCount--;    //カウントを1つ減らす。
    }

    //フェードタイマー進行。
    m_fadeTimer += g_gameTime->GetFrameDeltaTime();
    float alpha = (m_fadeTimer / m_fadeDuration);
    if (alpha > 1.0f) alpha = 1.0f;

    //表示テキスト設定。
    std::wstring m_text;
    //表示フラグ。
    bool m_showText = true;    
    if (m_currentCount > 0) {
        m_text = std::to_wstring(m_currentCount);
        //表示する座標を設定する。
        m_position = { -110.0f, 100, 0.0f };
    } 
    else {
        // GO!の時間を測る。
        if (m_showGO) {
            m_text = L"GO!";
            //表示する座標を設定する。
            m_position = { -200.0f, 100, 0.0f };
            m_goTimer += g_gameTime->GetFrameDeltaTime();
            if (m_goTimer >= m_goDuration) {
                m_showGO = false;
            }
        }
        else {
            m_showText = false; //GO!の表示時間が終わったら非表示。
        }
    }
    if (m_showText) {
        //文字を設定する。
        m_fontRender.SetText(m_text.c_str());
        //表示する座標を設定する。
        m_fontRender.SetPosition(m_position);
        //表示する大きさを設定する。
        m_fontRender.SetScale(7.0f);
        //黒色にアルファ適用。
        Vector4 color = g_vec4Black;
        color.w = alpha; //アルファ設定。
        m_fontRender.SetColor(color);//色の設定。
    }
    else {
        //非表示設定。
        m_fontRender.SetText(L"");
    }
}

void CountDown::Render(RenderContext& rc)
{
    m_fontRender.Draw(rc);
}
