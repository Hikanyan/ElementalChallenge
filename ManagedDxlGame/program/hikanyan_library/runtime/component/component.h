#pragma once
#include "object/object.h"
#include  "object/game_object.h"
#include <cstdint>


template <typename T>
class CastHelper
{
public:
    T t;
    uintptr_t onePointerFurtherThanT;
};

class component : public object
{
public:
    //TODO
    void GetComponentFastPath(const std::type_info& type, uintptr_t oneFurtherThanResultValue) {

    }

    template <typename T>
    T GetComponent() {
        CastHelper<T> castHelper;
        GetComponentFastPath(typeid(T), reinterpret_cast<uintptr_t>(&castHelper.onePointerFurtherThanT));
        return castHelper.t;
    }
};
