#include "game_manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "../entity/entity.h"
#include "../entity/entity_controller.h"

// ゲームの状態を表す
enum class GameState {
    // ゲームの初期化
    Init,
    // ゲームのメインループ
    Main,
    // ゲームの終了
    End
};

enum class GameScene
{
    Title,
    InGame,
    Result
};

GameState current_g_game_state = GameState::Init;
GameScene game_scene = GameScene::Title;

void game_manager::gameStart() {
    // ゲームの初期化
    // ゲームの状態をInitにする
    current_g_game_state = GameState::Init;
    initGame();  // ゲームの初期化を行う
    current_g_game_state = GameState::Main;  // ゲームの初期化が終わったらゲームの状態をMainにする
}

void game_manager::gameMain(float delta_time) {
    // ゲームのメインループ
    switch (game_scene) {
    case GameScene::Title:
        sceneTitle(delta_time);
        break;
    case GameScene::InGame:
        scenePlay(delta_time);
        break;
    }
}

void game_manager::gameEnd() {
    // ゲームの終了処理
    //endGame();
    // ゲームの状態をInitにする
    current_g_game_state = GameState::Init;
}



void game_manager::initGame()
{
    //初期化
    //画像読み込み、サウンド読み込み、
}
void game_manager::sceneTitle(float delta_time)
{
    //タイトル背景
    //Enter押したら次の
}

void game_manager::scenePlay(float delta_time)
{
    // ゲームのメインループ処理
    entity_controller::getInstance()->update(delta_time);
    entity_controller::getInstance()->draw();
    // ゲームの終了条件をチェックする（例: プレイヤーが死亡した場合）
    if (isGameOverConditionMet()) {
        current_g_game_state = GameState::End;
    }
}


void game_manager::endGame()
{
    //ゲームを終了させてTitleに戻す
}
bool game_manager::isGameOverConditionMet() {
    // プレイヤーが死亡したかどうかのチェック
    // if (playerIsDead()) {
    //     return true;
    // }

    // 特定の目標が達成されたかどうかのチェック
    // if (isObjectiveAchieved()) {
    //     return true;
    // }

    return false; // 終了条件が満たされていない場合は false を返す
}
