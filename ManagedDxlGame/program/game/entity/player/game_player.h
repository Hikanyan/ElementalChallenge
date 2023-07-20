#pragma once
#include "../entity.h"
class game_player : public entity {
private:
    
public:
    game_player(int health, int damage) : entity(health, damage) {}

    // 追加のメソッドや機能をここに追加できます
};