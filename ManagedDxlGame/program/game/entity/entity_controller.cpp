#include "entity_controller.h"
#include "player/game_player.h"
#include "enemy/enemy.h"

//fazade patternを使用する
//singletonを使用する
game_player* player;
game_enemy* enemy;
void entity_controller::initialize()
{
    player = new game_player(100, 10);
    enemy = new game_enemy(10, 10);
}

void entity_controller::gameStart()
{
    initialize();
}
void entity_controller::draw()
{
    
}
void entity_controller::update(float delta_time)
{
    
}

