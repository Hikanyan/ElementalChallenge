#include "game_manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "../entity/entity.h"
#include "../entity/entity_controller.h"

int g_Graphics_title_menu_background;
int g_Graphics_title_menu_logo;
int snd_title_menu_bgm;
int snd_title_menu_se;
float g_title_menu_timer;
float g_title_menu_flashing_timer = 1;
bool g_title_menu_flashing_flag;
const std::string TITLE_MENU_STR = "Enterを押してください。";
const tnl::Vector3 TITLE_MENU_POS = { DXE_WINDOW_WIDTH / 2 - 130, DXE_WINDOW_HEIGHT - (DXE_WINDOW_HEIGHT / 5), 0 };
const tnl::Vector3 TITLE_MENU_LOGO_POS = { DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0 };

// ゲームの状態を表す
enum class GameState
{
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

void game_manager::gameStart()
{
    // ゲームの初期化
    // ゲームの状態をInitにする
    current_g_game_state = GameState::Init;
    initGame(); // ゲームの初期化を行う
    current_g_game_state = GameState::Main; // ゲームの初期化が終わったらゲームの状態をMainにする
}

void game_manager::gameMain(float delta_time)
{
    // ゲームのメインループ
    if (current_g_game_state == GameState::Init)return;
    switch (game_scene)
    {
    case GameScene::Title:
        sceneTitle(delta_time);
        break;
    case GameScene::InGame:
        scenePlay(delta_time);
        break;
    }
}

void game_manager::gameEnd()
{
    // ゲームの終了処理
    //endGame();
    // ゲームの状態をInitにする
    current_g_game_state = GameState::Init;
}


void game_manager::initGame()
{
    //初期化
    //画像読み込み、サウンド読み込み、
    g_Graphics_title_menu_logo = LoadGraph("graphics/ElementalChallenge_logos_transparent.png");
    g_Graphics_title_menu_background = LoadGraph("graphics/purple_pink.png");

    snd_title_menu_bgm = LoadSoundMem("sound/test_bgm.wav");
    snd_title_menu_se = LoadSoundMem("sound/test_se.wav");
    
    PlaySoundMem(snd_title_menu_bgm, DX_PLAYTYPE_LOOP);
    
}

void game_manager::sceneTitle(float delta_time)
{
    g_title_menu_timer += delta_time;
    if (g_title_menu_timer > g_title_menu_flashing_timer) {
        g_title_menu_flashing_flag = !g_title_menu_flashing_flag;
        g_title_menu_timer = 0;
    }
    
    //タイトル背景
    //Enter押したら次の
    DrawExtendGraphF(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, g_Graphics_title_menu_background, true);

    DrawRotaGraphF(TITLE_MENU_LOGO_POS.x, TITLE_MENU_LOGO_POS.y, 1, 0, g_Graphics_title_menu_logo, true);

    SetFontSize(100);
    if (g_title_menu_flashing_flag) {
        SetFontSize(25);
        DrawStringEx(TITLE_MENU_POS.x, TITLE_MENU_POS.y, -1, TITLE_MENU_STR.c_str());
    }
    
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        game_scene = GameScene::InGame;
        
        PlaySoundMem(snd_title_menu_se, DX_PLAYTYPE_BACK);
        StopSoundMem(snd_title_menu_bgm);
    }
}

void game_manager::scenePlay(float delta_time)
{
    // ゲームのメインループ処理
    entity_controller::getInstance()->update(delta_time);
    entity_controller::getInstance()->draw();
    // ゲームの終了条件をチェックする（例: プレイヤーが死亡した場合）
    if (isGameOverConditionMet())
    {
        current_g_game_state = GameState::End;
    }
}


void game_manager::endGame()
{
    //ゲームを終了させてTitleに戻す
}

bool game_manager::isGameOverConditionMet()
{
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
