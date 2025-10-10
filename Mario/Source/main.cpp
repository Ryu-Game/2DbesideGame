#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

int main() {
	ChangeWindowMode(TRUE);				//�E�B���h�E���[�h�ύX
	DxLib_Init();						//Dx���C�u����������
	SetGraphMode(mgr.SCREEN_WIDTH, mgr.SCREEN_HEIGHT, 32);	//��ʃT�C�Y
	SetWindowSize(mgr.SCREEN_WIDTH, mgr.SCREEN_HEIGHT);		//Window�T�C�Y
	SetDrawScreen(DX_SCREEN_BACK);		//����ʐݒ�
	SceneMgr_Initialize();				//�����V�[��
	while (ProcessMessage() == 0) {
		ClearDrawScreen();				//��ʏ�����

		InputKey();						//���͏��
		
		SceneMgr_Update();				//�X�V
		SceneMgr_Draw();				//�`��
		
		ScreenFlip();					//��ʍX�V
	}
	SceneMgr_Finalize();				//�I�����

	DxLib_End();
	return 0;
}