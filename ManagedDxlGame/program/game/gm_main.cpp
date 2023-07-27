#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "system/game_manager.h"
#include "system/singleton.h"
#include "entity/entity_controller.h"

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	game_manager::getInstance()->gameStart();
	
}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
	game_manager::getInstance()->gameMain(delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
