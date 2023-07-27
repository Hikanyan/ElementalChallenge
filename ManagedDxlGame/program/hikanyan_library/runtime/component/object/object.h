#pragma once
#include <string>
#include <vector>

class Component; // 前方宣言

class object {
public:
    object() {}
    virtual ~object() {}
    object(const std::string& name);
    void start();
    void update(float delta_time);
    void draw();

    void addComponent(Component* component);

    int getID() const { return id; }
    const std::string& getName() const { return name; }

    static object* instantiate(const std::string& name);
    static void destroy(object* object);
    
protected:
    int id;
    std::string name;
    std::vector<Component*> components;
    static int nextID;
};
