#include "game_player.h"


void game_player::draw() {
    DrawBoxEx(player.pos_, 100, 30, false);
}