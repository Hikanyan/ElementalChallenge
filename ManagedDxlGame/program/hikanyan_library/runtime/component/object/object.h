#pragma once
#include <string>
#include <vector>

/*
 *IDの作成・取得
 *名前の作成
 *インスタンス化
 *破棄
 */

class object {
public:
    object() : id(instantiateID()), name("DefaultName") {}
    virtual ~object() {}
    object(const std::string& name) : id(instantiateID()), name(name) {}

    virtual void draw();
    virtual void gameStart();
    virtual void update(float delta_time);

    int getID() const { return id; }
    const std::string& getName() const { return name; }

    static object* instantiate(const std::string& name);
    static void destroy(object* object);

protected:
    int instantiateID();  // メソッドの宣言
    int id;
    std::string name;
    static int nextID;
};

