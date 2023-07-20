#pragma once
#include <iostream>


// シングルトンを実現するテンプレートクラス
template <typename T>
class Singleton {
public:
    static T& GetInstance() {
        static T instance; // C++11以降でスレッドセーフなシングルトン
        return instance;
    }

protected:
    Singleton() {} // プライベートコンストラクタを使って外部からのインスタンス生成を防ぐ
    Singleton(const Singleton&) = delete; // コピーを禁止
    Singleton& operator=(const Singleton&) = delete; // 代入演算子を禁止
};

