#pragma once
#include "singleton.h"

class game_manager : public singleton<game_manager>
{
private:
    
public:
    void gameStart();
    void gameMain( float delta_time );
    void gameEnd();
};
