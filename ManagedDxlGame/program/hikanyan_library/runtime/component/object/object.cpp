#include "object.h"

// 静的メンバの初期化
int object::nextID = 1;

int object::instantiateID() {
    return nextID++;
}

object* object::instantiate(const std::string& name) {
    return new object(name);
}

void object::destroy(object* object) {
    delete object;
}