#pragma once
#include "entity.h"
#include "../dxlib_ext/dxlib_ext.h"

class entity_controller
{
private:
    void initialize();
public:

    
    void gameStart();
    void draw();
    void update(float delta_time);
    
    void attack(entity* attacker, entity* target) {
        attacker->attack(target);
    }
};
