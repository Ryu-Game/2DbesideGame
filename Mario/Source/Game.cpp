#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Stage.h"
Game mGame;

/******************************
* ����������
*******************************/
void Game_Initialize() {
	mGame.numStage = 1;
	Stage_Initialize();
}

/******************************
* �I������
*******************************/
void Game_Finalize() {
	Stage_Finalize();
}

/******************************
* �X�V����
*******************************/
void Game_Update() {
	//�Q�[������
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);
	}
}

/******************************
* �`�揈��
*******************************/
void Game_Draw() {
	Stage_Update();
	Stage_Draw();
}