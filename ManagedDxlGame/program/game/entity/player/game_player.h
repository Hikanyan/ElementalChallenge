#pragma once
#include "../entity.h"

class game_player : public entity
{
public:
    // コンストラクタ
    game_player(int health, int damage) : entity(health, damage)
    {
        // transformの初期値を設定
        entityTransform.position = tnl::Vector3(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT * 0.8, 0);
        entityTransform.rotation = tnl::Vector3(0, 0, 0);
        entityTransform.scale = tnl::Vector3(50, 100, 1);
        gravity_volume = 9.8f;
        move_speed = 5;
    }
    

    // 追加のメソッドや機能をここに追加できます
    void draw() override;
    void gameStart() override;
    void update(float delta_time) override;
    void jump()
    {
        if (CurrentState == MovementState::OnGround)
        {
            velocity.y = -8.0f;
            CurrentState = MovementState::Jumping;
        }
    }
private:
    static void playerLoadDivGraph();
    enum class MovementState
    {
        OnGround,
        Jumping
    };
    MovementState CurrentState;
};
