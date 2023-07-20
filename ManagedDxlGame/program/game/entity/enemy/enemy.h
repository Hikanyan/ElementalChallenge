#pragma once
#include "../entity.h"

class game_enemy : public entity {
private:
    
public:
    game_enemy(int health, int damage) : entity(health, damage) {}

    // 追加のメソッドや機能をここに追加できます
};
