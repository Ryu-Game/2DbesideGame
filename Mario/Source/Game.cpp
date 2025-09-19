#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Stage.h"
Game mGame;

/******************************
* ����������
*******************************/
void Game_Initialize() {
	//mGame.Stage = 0;
	Stage_Initialize();
}

/******************************
* �I������
*******************************/
/*void Game_Finalize() {
	Stage_Finalize();
}*/

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
	DrawString(20, 380, "�Q�[����ʂł��B", GetColor(136, 136, 255));
	DrawString(20, 420, "Esc�L�[�������� ���j���[��ʂɖ߂�܂��B", GetColor(136, 136, 255));
}