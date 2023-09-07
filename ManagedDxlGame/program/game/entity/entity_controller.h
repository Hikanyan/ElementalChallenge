#pragma once
#include "entity.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "../system/list.h"
#include "../system/singleton.h"
class entity_controller : public singleton<entity_controller>
{
private:
    void initialize();
public:
    void gameStart();
    void draw();
    void update(float delta_time);
    bool isIntersect(entity* entityA, entity* entityB)
    {
        // ここでentityAとentityBの当たり判定を行う
        //return entityA->isIntersect(entityB);
        return false;
    }
    void attack(entity* attacker, entity* target) {
        attacker->attack(target);
    }
    void receiveDamage(entity* target, int amount) {
        target->receiveDamage(amount);
    }
    //my_listでNodeをポインタで持つので、deleteする必要がない。
    void addEntity(entity* entity) {
        entityList.push_back(entity);
    }
    my_list<entity*> entityList;
};
