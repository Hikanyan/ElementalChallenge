#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class entity
{
public:
    entity(int health, int damage) : health(health), damage(damage)
    {
    }

    // = 0は純粋仮想関数と呼ばれる。これを持つクラスは抽象クラスと呼ばれる。
    virtual void draw() = 0;
    virtual void gameStart() = 0;
    virtual void update(float delta_time) = 0;

    virtual void attack(entity* target)
    {
        target->receiveDamage(damage);
    }

    virtual void receiveDamage(int amount)
    {
        health -= amount;
    }

    int getHealth() const
    {
        return health;
    }

    class transform
    {
    public:
        tnl::Vector3 position{0, 0, 0};
        tnl::Vector3 rotation{0, 0, 0};
        tnl::Vector3 scale{1, 1, 1};
    };

protected:
    int health;
    int damage;
    int move_speed;

    transform entityTransform;
};
