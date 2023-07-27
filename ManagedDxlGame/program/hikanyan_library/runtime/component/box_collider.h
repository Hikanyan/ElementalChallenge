#pragma once
#include "component.h"

template <typename T>
class box_collider : public component<T>
{
public:
    box_collider(T owner, float width, float height) : component(owner), width(width), height(height) {}
    
    // 衝突判定などの追加のメソッドをここに実装する

    private:
    float width;
    float height;
};
