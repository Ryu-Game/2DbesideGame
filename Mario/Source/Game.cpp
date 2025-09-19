#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"

Game mGame;
/******************************
* ����������
*******************************/
void Game_Initialize() {
	mGame.numStage = 1;		//�Q�[���X�e�[�W��������
	Stage_Initialize();		//�X�e�[�W������
	Player_Initialize();	//�v���C���[������
}

/******************************
* �I������
*******************************/
void Game_Finalize() {
	Stage_Finalize();	//�X�e�[�W�I��
	Player_Finalize();	//�v���C���[�I������
}

/******************************
* �X�V����
*******************************/
void Game_Update() {
	//Esc�L�[�ŋ����I��
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
		SceneMgr_ChangeScene(eScene_Menu);
	}

	Stage_Update();		//�X�e�[�W�X�V
	Player_Update();	//�v���C���[�X�V
}

/******************************
* �`�揈��
*******************************/
void Game_Draw() {
	Stage_Draw();		//�X�e�[�W�`��
	Player_Draw();		//�v���C���[�`��
}