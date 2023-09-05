#include <time.h>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "system/game_manager.h"
#include "system/singleton.h"

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart(){
	srand(time(0));
	game_manager::getInstance()->gameStart();
	
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {
	game_manager::getInstance()->gameMain(delta_time);
	
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {
	
}
