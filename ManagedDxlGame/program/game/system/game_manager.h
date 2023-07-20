#pragma once
#include "singleton.h"

class game_manager : public Singleton<game_manager>
{
private:
    
public:
    void gameStart();
    void gameMain( float delta_time );
    void gameEnd();
};
