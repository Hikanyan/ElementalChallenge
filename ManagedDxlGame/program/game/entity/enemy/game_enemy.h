#pragma once
#include "../entity.h"

class game_enemy : public entity
{
private:

public:
    game_enemy(int health, int damage) : entity(health, damage)
    {
        // transformの初期値を設定
        entityTransform.position = tnl::Vector3(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT * 0.2, 0);
        entityTransform.rotation = tnl::Vector3(0, 0, 0);
        entityTransform.scale = tnl::Vector3(100, 100, 1);
        gravity_volume = 9.8f;
        move_speed = 5;
    }
    // 位置を設定するメソッド
    void setPosition(const tnl::Vector3& position)
    {
        entityTransform.position = position;
    }
    void draw() override;
    void gameStart() override;
    void update(float delta_time) override;
};
