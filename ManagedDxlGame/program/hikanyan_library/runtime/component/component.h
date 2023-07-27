#pragma once
#include "object/object.h"
#include <iostream>
#include <cstdint>

// CastHelperクラスのC++版
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
    void GetComponentFastPath(const std::type_info& type, uintptr_t oneFurtherThanResultValue)
    {
        // ここにGetComponentFastPathメソッドのC++版の実装を記述します。
        // typeやoneFurtherThanResultValueを使用して適切な処理を実装します。
        // 実際の動作に応じて、適切な処理を記述してください。
        std::cout << "GetComponentFastPath called." << std::endl;
    }

    // GetComponent関数を修正して、GetComponentFastPathメソッドを呼び出すようにします
    template <typename T>
    T GetComponent()
    {
        CastHelper<T> castHelper;
        GetComponentFastPath(typeid(T), reinterpret_cast<uintptr_t>(&castHelper.onePointerFurtherThanT));
        return castHelper.t;
    }
};
