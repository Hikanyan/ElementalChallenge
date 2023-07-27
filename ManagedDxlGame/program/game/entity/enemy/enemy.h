#pragma once
#include "../entity.h"

class game_enemy : public entity {
private:
    
public:
    game_enemy(int health, int damage) : entity(health, damage)
    {
        // transformの初期値を設定
        entityTransform.position = tnl::Vector3(0, 0, 0);
        entityTransform.rotation = tnl::Vector3(0, 0, 0);
        entityTransform.scale = tnl::Vector3(1, 1, 1);

        move_speed = 5;
    }

    // 追加のメソッドや機能をここに追加できます
    virtual void draw() override{}  ;
    virtual void gameStart()  override{};
    virtual void update(float delta_time) override {};

};
