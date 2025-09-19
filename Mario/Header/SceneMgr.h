//#pragma once
typedef enum
{
	eScene_Menu,	//���j���[���
	eScene_Game,	//�Q�[�����
	eScene_Config,	//�ݒ���
	eScene_None,	//����
} eScene;

static class SceneMgr {
public:
	//��ʃT�C�Y�̑傫��
	const int SCREEN_WIDTH = 512;		//Image(32 * 32) * 16
	const int SCREEN_HEIGHT = 384;		//Image(32 * 32) * 13(�㉺�����͂ݏo��)
}mgr;

void SceneMgr_Initialize();	//������
void SceneMgr_Finalize();	//�I������
void SceneMgr_Update();		//�X�V
void SceneMgr_Draw();		//�`��

// ���� nextScene�ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);