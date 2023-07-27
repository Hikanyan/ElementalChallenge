#include "game_player.h"

void game_player::draw() {
    DrawBoxEx(entityTransform.position, entityTransform.scale.x, entityTransform.scale.y, false);
}
void game_player::gameStart() {
    
}
void game_player::update(float delta_time) {
    //プレイヤーの座標+-scale/2にすることで、プレイヤーが画面外に出ないようにする
    if (entityTransform.position.x - (entityTransform.scale.x/2) > 0 && tnl::Input::IsKeyDown(eKeys::KB_A))
        entityTransform.position.x -= move_speed;
    if (entityTransform.position.x + (entityTransform.scale.x/2)< DXE_WINDOW_WIDTH && tnl::Input::IsKeyDown(eKeys::KB_D))
        entityTransform.position.x += move_speed;
}