#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class entity {
public:
    entity(int health, int damage) : health(health), damage(damage) {}
    virtual void draw();
    virtual void gameStart();
    virtual void update(float delta_time);
    
    virtual void attack(entity* target) {
        target->receiveDamage(damage);
    }

    virtual void receiveDamage(int amount) {
        health -= amount;
    }

    int getHealth() const {
        return health;
    }

protected:
    int health;
    int damage;
    int move_speed = 5;
    
    static constexpr int SIZE_WIDTH = 5;
    static constexpr int SIZE_HEIGHT = 5;

    class transform
    {
        tnl::Vector3 position{ 0, 0, 0 };
        tnl::Vector3 rotation{ 0, 0, 0 };
        tnl::Vector3 scale{ 1, 1, 1 };
    };

};
