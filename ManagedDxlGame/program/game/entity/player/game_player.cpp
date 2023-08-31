#include "game_player.h"

void game_player::draw()
{
    DrawBoxEx(entityTransform.position, entityTransform.scale.x, entityTransform.scale.y, false);
}

void game_player::gameStart()
{
    CurrentState = MovementState::OnGround;
}

void game_player::update(float delta_time)
{
    //プレイヤーの座標+-scale/2にすることで、プレイヤーが画面外に出ないようにする
    if (entityTransform.position.x - (entityTransform.scale.x / 2) > 0 && tnl::Input::IsKeyDown(eKeys::KB_A))
        entityTransform.position.x -= move_speed;
    if (entityTransform.position.x + (entityTransform.scale.x / 2) < DXE_WINDOW_WIDTH &&
        tnl::Input::IsKeyDown(eKeys::KB_D))
        entityTransform.position.x += move_speed;
    // 画面の上端に達したら重力を無効にし、ジャンプをリセット
    if (entityTransform.position.y + (entityTransform.scale.y / 2) > DXE_WINDOW_HEIGHT)
    {
        entityTransform.position.y = DXE_WINDOW_HEIGHT - (entityTransform.scale.y / 2); // 画面内に制限
        CurrentState = MovementState::OnGround; // 地面にいる状態にリセット
    }
    else
    {
        // 画面の上端にいない場合は重力を再度有効にする
        gravity_volume = 9.8f;
    }
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE))jump();
}
