#include "game_player.h"

void game_player::draw() {
    DrawBoxEx(entityTransform.position, entityTransform.position.x, entityTransform.position.y, false);
}
void game_player::gameStart() {
    
}
void game_player::update(float delta_time) {

}