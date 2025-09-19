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
		static constexpr int DrawY = -16;	//初期座標

		std::array<std::array<int, ChipX>, ChipY> MapChip;
		std::array<std::array<int, ChipX>, ChipY> MapBackChip;
};

void Stage_Initialize();//初期化
//void Stage_Finalize();//終了処理
void Stage_Update();//更新
void Stage_Draw();//描画

void Stage_Stroge();

extern Stage mStage;