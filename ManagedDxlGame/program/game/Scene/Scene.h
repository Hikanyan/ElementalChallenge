#pragma once
#include <string>

class Scene {
public:
    Scene(const std::string& name);
    void Load();
    void Unload();
    private:
    std::string name_;
};
