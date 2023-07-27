#pragma once
#include "../entity.h"

class game_player : public entity
{
private:

public:
    // コンストラクタ
    game_player(int health, int damage) : entity(health, damage)
    {
        // transformの初期値を設定
        entityTransform.position = tnl::Vector3(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT * 0.8, 0);
        entityTransform.rotation = tnl::Vector3(0, 0, 0);
        entityTransform.scale = tnl::Vector3(5, 5, 1);

        move_speed = 5;
    }

    // 追加のメソッドや機能をここに追加できます
    void draw() override;
    void gameStart() override;
    void update(float delta_time) override;
};
