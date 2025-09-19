#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//��ʃT�C�Y�̑傫��
	const int SCREEN_WIDTH = 512;		//Image(32 * 32) * 16
	const int SCREEN_HEIGHT = 384;		//Image(32 * 32) * 13(�㉺�����͂ݏo��)

	ChangeWindowMode(TRUE);				//�E�B���h�E���[�h�ύX
	DxLib_Init();						//Dx���C�u����������
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//��ʃT�C�Y
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//Window�T�C�Y
	SetDrawScreen(DX_SCREEN_BACK);		//����ʐݒ�
	SceneMgr_Initialize();				//�����V�[��
	while (ProcessMessage() == 0) {
		ClearDrawScreen();				//��ʏ�����

		InputKey();					//���͏��
		
		SceneMgr_Update();				//�X�V
		SceneMgr_Draw();				//�`��
		
		ScreenFlip();					//��ʍX�V
	}
	SceneMgr_Finalize();				//�I�����

	DxLib_End();
	return 0;
}