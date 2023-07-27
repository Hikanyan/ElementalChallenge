#pragma once
#include "object/object.h"

template <typename T>
class component :object
{
public:
    // このコンストラクタは、コンポーネントを持つエンティティが生成されたときに呼ばれます
    component(T owner) : owner(owner) {}

    

protected:
    T owner; // このコンポーネントが所属するエンティティへのポインタ
};
