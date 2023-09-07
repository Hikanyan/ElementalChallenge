#pragma once
#include "list.h"
#include "../dxlib_ext/dxlib_ext.h"

class user_interface
{
    int score = 0;
    float time = 0.0f;
    std::string help = "ADキーで左右に移動。スペースキーでジャンプ";
    std::string gameover = "GAME OVER";
    std::string gameover_help_show = "Rでリスタート";
    tnl::Vector3 help_show_pos = {100, 600, 0};
    tnl::Vector3 score_show_pos = {100, 650, 0};
    tnl::Vector3 gameover_show_pos = {DXE_WINDOW_WIDTH / 2 - 250, DXE_WINDOW_HEIGHT / 2, 0};
    tnl::Vector3 gameover_help_show_pos = {DXE_WINDOW_WIDTH / 2 - 250, DXE_WINDOW_HEIGHT / 2 + 100, 0};
    int fontsize = 50;

public:
    void timer();
    void addScore(int point);
    
    void draw();
    void reset();
};

extern user_interface user_interface;
