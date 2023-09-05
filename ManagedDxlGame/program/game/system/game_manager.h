#pragma once
#include "singleton.h"

class game_manager : public singleton<game_manager>
{
private:
    void sceneTitle(float delta_time);
    void scenePlay(float delta_time);
    void initGame();
    void endGame();
public:
    void gameStart();
    void gameMain( float delta_time );
    void gameEnd();
    bool isGameOverConditionMet();
};
