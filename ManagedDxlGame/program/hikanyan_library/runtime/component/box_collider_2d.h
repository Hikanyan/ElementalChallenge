#pragma once
#include "component.h"

template <typename T>
class box_collider_2d : public component
{
public:
    box_collider_2d(T owner, float width, float height) : component(owner), width(width), height(height) {}

    // 衝突判定のためのメソッド
    bool checkCollision(const box_collider_2d<T>& other) const {
        return (owner.x < other.owner.x + other.width &&
                owner.x + width > other.owner.x &&
                owner.y < other.owner.y + other.height &&
                owner.y + height > other.owner.y);
    }

private:
    float width;
    float height;
    T owner; // 仮の owner の型として T を使用
};
