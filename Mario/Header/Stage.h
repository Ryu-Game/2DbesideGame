#pragma once
#include <array>
class Stage {
	public:
		//char numStage = 0;
		int MapImage[19];
		int ClayPipeImage[4];
		int QuestionImage[5];
		int BlockImage[2];
		static constexpr int Chip = 32;
		static constexpr int ChipX = 16;
		static constexpr int ChipY = 13;
		static constexpr int DrawY = -16;	//�������W

		std::array<std::array<int, ChipX>, ChipY> MapChip;
		std::array<std::array<int, ChipX>, ChipY> MapBackChip;
};

void Stage_Initialize();//������
//void Stage_Finalize();//�I������
void Stage_Update();//�X�V
void Stage_Draw();//�`��

void Stage_Stroge();

extern Stage mStage;