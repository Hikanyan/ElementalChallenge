#pragma once
#include "entity.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "../system/list.h"
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
    void receiveDamage(entity* target, int amount) {
        target->receiveDamage(amount);
    }
    //my_listでNodeをポインタで持つので、deleteする必要がない。
    void addEntity(const entity& entity) {
        entityList.push_back(entity);
    }
    my_list<entity> entityList;
};
