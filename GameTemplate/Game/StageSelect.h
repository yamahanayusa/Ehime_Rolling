#pragma once
//#include "GameObject.h" // GameObjectを継承していると仮定

class Game; // Gameクラスの前方宣言

class StageSelect : public IGameObject
{
public:
    StageSelect(); //
    ~StageSelect(); //
    bool Start() override; //
    void Update() override; //
    void Render(RenderContext& rc) override; //

private:
    SpriteRender m_spriteRender; //
    SpriteRender m_spriteRender0; // カーソル用の黒い四角
    SpriteRender m_spriteRender1; // ステージ1画像
    SpriteRender m_spriteRender2; // ステージ2画像
    SpriteRender m_spriteRender3; // ステージ3画像
    SpriteRender m_spriteRender4; // ステージ4画像
    SpriteRender m_spriteRender5; // ステージ5画像

    int m_button = 0; // 現在選択中のステージボタンのインデックス (0-5)
    int m_selectedStage = 0; // 実際にGameオブジェクトに渡すステージ番号
};