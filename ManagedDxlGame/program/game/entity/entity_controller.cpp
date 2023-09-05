#include "entity_controller.h"
#include "player/game_player.h"
#include "enemy/game_enemy.h"
#include <random>

//fazade patternを使用する
//singletonを使用する
game_player* player;
game_enemy* enemy;
constexpr int num_enemies = 5;

tnl::Vector3 getRandomPosition()
{
    std::random_device rd;
    std::mt19937 gen(rd()); // メルセンヌ・ツイスタ法を使用した乱数生成器を初期化
    std::uniform_real_distribution<float> posX(0.0f, DXE_WINDOW_WIDTH);
    std::uniform_real_distribution<float> posY(0.0f, DXE_WINDOW_HEIGHT * 0.6);

    float x = posX(gen); // 指定範囲内のランダムな x 座標
    float y = posY(gen); // 指定範囲内のランダムな y 座標

    return tnl::Vector3(x, y, 0);
}

void entity_controller::initialize()
{
    player = new game_player(100, 10);
    enemy = new game_enemy(10, 10);
    entityList.push_back(player);
    entityList.push_back(enemy); //ボス的な奴
    // エネミーを指定された数だけ生成し、ランダムな位置に配置
    for (int i = 0; i < num_enemies; ++i)
    {
        constexpr int enemy_health = 1; // エネミーの体力（適宜変更）
        constexpr int enemy_damage = 1; // エネミーのダメージ（適宜変更）
        game_enemy* enemy = new game_enemy(enemy_health, enemy_damage);
        enemy->setPosition(getRandomPosition()); // ランダムな位置に配置
        entityList.push_back(enemy);
    }
}

void entity_controller::gameStart()
{
    initialize();
    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->gameStart();
    }
}

void entity_controller::draw()
{
    //entityList.displayList();
    //それぞれを描画する
    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->draw();
    }
}

void entity_controller::update(float delta_time)
{
    for (int i = 0; i < entityList.size(); i++)
    {
        entityList[i]->gravity(delta_time);
        entityList[i]->update(delta_time);
    }
}
