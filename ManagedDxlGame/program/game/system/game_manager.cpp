#include "game_manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "../entity/entity.h"
#include "../entity/entity_controller.h"

//Gameの状態管理を行う
// Sceneの遷移、Player、Enemy、Itemの生成、削除などを行う
//ファザードパターンを使用する
//Singletonを使用する

//ゲームの状態を表す
enum class GameState {
    //ゲームの初期化
    Init,
    //ゲームのメインループ
    Main,
    //ゲームの終了
    End
};

void game_manager::gameStart() {
    //ゲームの初期化
    //ゲームの状態をInitにする
    //ゲームの初期化を行う
    //ゲームの初期化が終わったらゲームの状態をMainにする
}
void game_manager::gameMain(float delta_time) {
    //ゲームのメインループ
    //ゲームの状態がMainの間はゲームのメインループを回す
    //ゲームのメインループが終わったらゲームの状態をEndにする
}
void game_manager::gameEnd() {
    //ゲームの終了
    //ゲームの状態がEndの間はゲームの終了処理を行う
    //ゲームの終了処理が終わったらゲームの状態をInitにする
}

