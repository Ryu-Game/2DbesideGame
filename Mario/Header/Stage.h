#pragma once
#include <array>
extern class Stage {
	public:
		const int ChipSize = 32;			//チップサイズ
		static constexpr int ChipX = 16;	//横最大数
		static constexpr int ChipY = 13;	//縦最大数

		char numStage;						//ステージ数
		char oldStage;						//前ステージ数

		//マップチップ画像
		int MapImage[30];

		//マップチップ情報
		int MapChip[ChipY][ChipX];
		int MapBackChip[ChipY][ChipX];
		int MapHitBox[ChipY][ChipX][4];
}mStage;

void Stage_Initialize();	//初期化
void Stage_Finalize();		//終了処理
void Stage_Update();		//更新
void Stage_Draw();			//描画

void Stage_Stroge();		//画像格納処理
void Stage_File(char No, int MapChip[mStage.ChipY][mStage.ChipX]);		//マップチップ格納処理
void Stage_HitBox();
void Stage_Debug();