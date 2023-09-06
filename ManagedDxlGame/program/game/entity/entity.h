#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class entity
{
public:
    virtual ~entity() = default;

    entity(int health, int damage) : health(health), damage(damage)
    {
    }

    // = 0は純粋仮想関数と呼ばれる。これを持つクラスは抽象クラスと呼ばれる。
    virtual void draw() = 0;
    virtual void gameStart() = 0;
    virtual void update(float delta_time) = 0;
    
    
    // 重力を処理
    void gravity(float delta_time)
    {
        velocity.y += gravity_volume * delta_time;
        entityTransform.position += velocity * delta_time * 60.0f;
    }
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
    tnl::Vector3 velocity;
    float gravity_volume;
};
