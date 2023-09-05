#include "game_enemy.h"
#include "../Player/game_player.h"

// エネミーの追跡距離と攻撃距離を設定
const float chaseDistance = 200.0f;
const float attackDistance = 30.0f;

// エネミーの速度を設定
const float enemySpeed = 3.0f;
void game_enemy::draw() {
    DrawBoxEx(entityTransform.position, entityTransform.scale.x, entityTransform.scale.y, false);
}
void  game_enemy::gameStart()
{
    
}
void game_enemy::update(float delta_time) {
    // // プレイヤーの位置を取得
    // tnl::Vector3 playerPosition = game_player->getPosition();
    //
    // // プレイヤーとの距離を計算
    // float distanceToPlayer = tnl::Vector3::distance(entityTransform.position, playerPosition);
    //
    // // プレイヤーが一定の距離以内にいる場合
    // if (distanceToPlayer < chaseDistance) {
    //     // プレイヤーに向かって移動
    //     tnl::Vector3 direction = tnl::Vector3::normalize(playerPosition - entityTransform.position);
    //     entityTransform.position += direction * enemySpeed * delta_time;
    //
    //     // プレイヤーが攻撃可能な範囲にいる場合
    //     if (distanceToPlayer < attackDistance) {
    //         // プレイヤーを攻撃するアクションを実行
    //         player->takeDamage(attackDamage); // プレイヤーにダメージを与えるなどの処理を実行
    //     }
    // }

    
}
