#include "game_player.h"

float g_player_timer = 0;
float g_player_flashing_timer = 0.5;
bool g_player_flashing_flag;


int g_player_num_handle_down[4];
int g_player_num_handle_up[4];
int g_player_num_handle_left[4];
int g_player_num_handle_right[4];
int g_player_num_handle_num;

enum state
{
    down,
    up,
    left,
    right
};
state g_player_state = down;

void game_player::draw()
{
    DrawBoxEx(entityTransform.position, entityTransform.scale.x, entityTransform.scale.y, false);


    // ステートに基づいて描画を切り替え
    int sprite_index = -1; // 初期値は無効なインデックス
    switch (g_player_state)
    {
    case down:
        sprite_index = g_player_num_handle_down[g_player_num_handle_num];
        break;
    case up:
        sprite_index = g_player_num_handle_up[g_player_num_handle_num];
        break;
    case left:
        sprite_index = g_player_num_handle_left[g_player_num_handle_num];
        break;
    case right:
        sprite_index = g_player_num_handle_right[g_player_num_handle_num];
        break;
    default:
        // 未知のステート
        break;
    }

    if (sprite_index != -1)
    {
        DrawRotaGraphF(entityTransform.position.x, entityTransform.position.y, 1, 0, sprite_index, true);
    }
}


void game_player::gameStart()
{
    playerLoadDivGraph();

    CurrentState = MovementState::OnGround;
}

void game_player::update(float delta_time)
{
    g_player_timer += delta_time;
    if (g_player_timer > g_player_flashing_timer)
    {
        g_player_flashing_flag = !g_player_flashing_flag;
        g_player_timer = 0;
    }
    if (g_player_flashing_flag)
    {
        g_player_num_handle_num = 0;
    }
    else
    {
        g_player_num_handle_num = 1;
    }


    if (tnl::Input::IsKeyDown(eKeys::KB_W))
    {
        g_player_state = up;
    }
    //プレイヤーの座標+-scale/2にすることで、プレイヤーが画面外に出ないようにする
    if (entityTransform.position.x - (entityTransform.scale.x / 2) > 0 && tnl::Input::IsKeyDown(eKeys::KB_A))
    {
        g_player_state = left;
        entityTransform.position.x -= move_speed;
    }
    if (tnl::Input::IsKeyDown(eKeys::KB_S))
    {
        g_player_state = down;
    }
    if (entityTransform.position.x + (entityTransform.scale.x / 2) < DXE_WINDOW_WIDTH &&
        tnl::Input::IsKeyDown(eKeys::KB_D))
    {
        entityTransform.position.x += move_speed;
        g_player_state = right;
    }
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

void game_player::playerLoadDivGraph()
{
    LoadDivGraph("graphics/c1_anim_down.png", 4, 4, 1, 32, 48, g_player_num_handle_down);
    LoadDivGraph("graphics/c1_anim_up.png", 4, 4, 1, 32, 48, g_player_num_handle_up);
    LoadDivGraph("graphics/c1_anim_left.png", 4, 4, 1, 32, 48, g_player_num_handle_left);
    LoadDivGraph("graphics/c1_anim_right.png", 4, 4, 1, 32, 48, g_player_num_handle_right);
}
