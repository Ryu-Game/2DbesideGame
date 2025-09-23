#pragma once
#include <array>
extern class Stage {
	public:
		const int ChipSize = 32;			//�`�b�v�T�C�Y
		static constexpr int ChipX = 16;	//���ő吔
		static constexpr int ChipY = 13;	//�c�ő吔

		char numStage;						//�X�e�[�W��
		char oldStage;						//�O�X�e�[�W��

		//�}�b�v�`�b�v�摜
		int MapImage[30];

		//�}�b�v�`�b�v���
		int MapChip[ChipY][ChipX];
		int MapBackChip[ChipY][ChipX];
		int MapHitBox[ChipY][ChipX][4];
}mStage;

void Stage_Initialize();	//������
void Stage_Finalize();		//�I������
void Stage_Update();		//�X�V
void Stage_Draw();			//�`��

void Stage_Stroge();		//�摜�i�[����
void Stage_File(char No, int MapChip[mStage.ChipY][mStage.ChipX]);		//�}�b�v�`�b�v�i�[����
void Stage_HitBox();
void Stage_Debug();