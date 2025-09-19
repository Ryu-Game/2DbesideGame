#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //�摜�n���h���i�[�p�ϐ�

/******************************
* ����������
*******************************/
void Menu_Initialize() {
	//mImageHandle = LoadGraph(TEXT("images/Screen/Scene_Menu.png")); //�摜�̃��[�h
}

/******************************
* �I������
*******************************/
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}

/******************************
* �X�V����
*******************************/
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		DxLib_End();
	}
}

/******************************
* �`�揈��
*******************************/
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 360, TEXT("���j���[��ʂł��B"), GetColor(136, 136, 255));
	DrawString(20, 380, TEXT("G�L�[�������ƃQ�[����ʂɐi�݂܂��B"), GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("C�L�[�������� �ݒ��ʂɐi�݂܂��B"), GetColor(136, 136, 255));
	DrawString(20, 420, TEXT("ESC�L�[�������� �I�����܂��B"), GetColor(136, 136, 255));
}