#pragma once
#include <array>
extern class Stage {
	public:
		const int ChipSize = 32;	//�`�b�v�T�C�Y
		static constexpr int ChipX = 16;		//���ő吔
		static constexpr int ChipY = 13;		//�c�ő吔
		const int DrawY = -16;		//�������W

		char numStage;				//�X�e�[�W��
		char oldStage;				//�O�X�e�[�W��

		//�}�b�v�`�b�v�摜
		int MapImage[19];			
		int ClayPipeImage[4];
		int QuestionImage[5];
		int BlockImage[2];

		//�}�b�v�`�b�v���
		int MapChip[ChipY][ChipX];
		int MapBackChip[ChipY][ChipX];

		//std::array<std::array<int, ChipX>, ChipY> MapChip;
		//std::array<std::array<int, ChipX>, ChipY> MapBackChip;
}mStage;

void Stage_Initialize();	//������
void Stage_Finalize();		//�I������
void Stage_Update();		//�X�V
void Stage_Draw();			//�`��

void Stage_Stroge();		//�摜�i�[����
void Stage_File(char No, int MapChip[mStage.ChipY][mStage.ChipX]);			//�}�b�v�`�b�v�i�[����