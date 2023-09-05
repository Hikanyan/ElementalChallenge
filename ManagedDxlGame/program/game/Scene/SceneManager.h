#pragma once
#include "Scene.h"
#include "../system/list.h"
#include "../system/singleton.h"

class scene_manager : singleton<scene_manager>
{
public:
    void AddScene(Scene* scene);
    void LoadScene(const std::string& sceneName);
    void UnloadScene(const std::string& sceneName);
    // 他の必要なメンバーやメソッドを追加
private:
    my_list<Scene*> scenes_;
};
