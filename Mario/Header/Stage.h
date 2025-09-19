#pragma once
#include <array>
extern class Stage {
	public:
		const int ChipSize = 32;	//チップサイズ
		static constexpr int ChipX = 16;		//横最大数
		static constexpr int ChipY = 13;		//縦最大数
		const int DrawY = -16;		//初期座標

		char numStage;				//ステージ数
		char oldStage;				//前ステージ数

		//マップチップ画像
		int MapImage[19];			
		int ClayPipeImage[4];
		int QuestionImage[5];
		int BlockImage[2];

		//マップチップ情報
		int MapChip[ChipY][ChipX];
		int MapBackChip[ChipY][ChipX];

		//std::array<std::array<int, ChipX>, ChipY> MapChip;
		//std::array<std::array<int, ChipX>, ChipY> MapBackChip;
}mStage;

void Stage_Initialize();	//初期化
void Stage_Finalize();		//終了処理
void Stage_Update();		//更新
void Stage_Draw();			//描画

void Stage_Stroge();		//画像格納処理
void Stage_File(char No, int MapChip[mStage.ChipY][mStage.ChipX]);			//マップチップ格納処理