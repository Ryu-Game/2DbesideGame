#include "DxLib.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Stage.h"
#include "Game.h"

Stage mStage;
/******************************
* 初期化処理
*******************************/
void Stage_Initialize() {
	//マップチップ初期化処理
	mStage.oldStage = 0;
	mStage.numStage = mGame.numStage;
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			mStage.MapBackChip[numY][numX] = 0;
			mStage.MapChip[numY][numX] = 0;
		}
	}
	Stage_Stroge();
}

/******************************
* 終了処理
*******************************/
void Stage_Finalize() {

}

/******************************
* 更新処理
*******************************/
void Stage_Update() {
	//ステージ更新
	if (mStage.oldStage != mStage.numStage) {	
		Stage_File(mStage.oldStage, mStage.MapBackChip);
		Stage_File(mStage.numStage, mStage.MapChip);
		mStage.oldStage = mStage.numStage;
	}
}

/******************************
* 描画処理
*******************************/
void Stage_Draw() {
	const int DrawY = -16;
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			//背景画像
			int no = mStage.MapBackChip[numY][numX];
			DrawGraph(numX * mStage.ChipSize, (numY * mStage.ChipSize) + DrawY, mStage.MapImage[no], FALSE);
			//表画像
			no = mStage.MapChip[numY][numX];
			DrawGraph(numX * mStage.ChipSize, (numY * mStage.ChipSize) + DrawY, mStage.MapImage[no], TRUE);
		}
	}

	Stage_Debug();
}

/******************************
* 関数
*******************************/
//画像格納処理
void Stage_Stroge() {
	LoadDivGraph("images/Block/hatena.png", 4, 4, 1, mStage.ChipSize, mStage.ChipSize, mStage.MapImage);
	for (int num = 0; num < 4; num++) {
		mStage.MapImage[num + 24] = mStage.MapImage[num];
	}
	//画像無
	mStage.MapImage[0] = 0;			

	//背景画像
	mStage.MapImage[1] = LoadGraph("images/Background/ha0.png");
	mStage.MapImage[2] = LoadGraph("images/Background/ha1.png");
	mStage.MapImage[3] = LoadGraph("images/Background/ha2.png");
	mStage.MapImage[4] = LoadGraph("images/Background/kumo_centerdown.png");
	mStage.MapImage[5] = LoadGraph("images/Background/kumo_centerup.png");
	mStage.MapImage[6] = LoadGraph("images/Background/kumo_leftdown.png");
	mStage.MapImage[7] = LoadGraph("images/Background/kumo_leftup.png");
	mStage.MapImage[8] = LoadGraph("images/Background/kumo_rightdown.png");
	mStage.MapImage[9] = LoadGraph("images/Background/kumo_rightup.png");
	mStage.MapImage[10] = LoadGraph("images/Background/mountain_left.png");
	mStage.MapImage[11] = LoadGraph("images/Background/mountain_right.png");
	mStage.MapImage[12] = LoadGraph("images/Background/mountain_surface.png");
	mStage.MapImage[13] = LoadGraph("images/Background/mountain_surface1.png");
	mStage.MapImage[14] = LoadGraph("images/Background/mountain_surface2.png");
	mStage.MapImage[15] = LoadGraph("images/Background/mountain_up.png");
	mStage.MapImage[16] = LoadGraph("images/Background/sora.png");

	//ブロック画像
	mStage.MapImage[17] = LoadGraph("images/Block/bloak_1.png");
	mStage.MapImage[18] = LoadGraph("images/Block/block.png");

	//土管画像
	mStage.MapImage[19] = LoadGraph("images/Block/dokan_left_down.png");
	mStage.MapImage[20] = LoadGraph("images/Block/dokan_left_up.png");
	mStage.MapImage[21] = LoadGraph("images/Block/dokan_right_down.png");
	mStage.MapImage[22] = LoadGraph("images/Block/dokan_right_up.png");

	//地面画像
	mStage.MapImage[23] = LoadGraph("images/Block/floor.png");

	//はてなブロック画像(24～27は呼び出し時に格納)
	mStage.MapImage[28] = LoadGraph("images/Block/kara_block.png");

	//ゴール地面画像
	mStage.MapImage[29] = LoadGraph("images/Block/kai_block.png");
}

//マップチップ情報格納処理
void Stage_File(char No, int MapChip[mStage.ChipY][mStage.ChipX]) {
	std::string filename;
	
	//ファイル名格納処理
	if (No == 0) {
		filename = "Stage/青背景.txt";
	}
	else {
		filename = "Stage/" + std::to_string(No) + ".txt";
	}

	//ファイル情報格納処理
	std::ifstream ifs(filename);
	if (!ifs) {		//ファイルエラー処理
		std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
		return;
	}
	else {			//読み込み処理
		std::string line;
		for (int numY = 0; numY < mStage.ChipY; numY++) {
			if (!std::getline(ifs, line)) {	//エラー処理
				std::cerr << "行数が不足(y = " << numY << ")" << std::endl;
				return;
			}

			std::stringstream ss(line);
			std::string token;
			int numX = 0;
			
			while (std::getline(ss, token, ',')) {	//カンマで分割
				if (token.empty()) continue;		//空要素をスキップ

				int value = std::stoi(token);		//文字列を整数変換
				if (numX < mStage.ChipX) {
					MapChip[numY][numX] = value;
				}
				numX++;
			}

			if (numX < mStage.ChipX) {	//エラー処理
				std::cerr << "列数が不足しています (y=" << numY << ", 読み込んだ数=" << numX << ")" << std::endl;
				return;
			}
		}
	}
}

//ヒットボックス
void Stage_HitBox() {
	int numHitbox = 0;
	int PosiY = -16;
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			numHitbox = mStage.MapBackChip[numY][numX];
			if (numHitbox >= 18) {
				mStage.MapHitBox[numY][numX][0] = numX * mStage.ChipSize;
				mStage.MapHitBox[numY][numX][1] = (numY * mStage.ChipSize) + PosiY;
				mStage.MapHitBox[numY][numX][2] = mStage.MapHitBox[numY][numX][0] + mStage.ChipSize;
				mStage.MapHitBox[numY][numX][3] = mStage.MapHitBox[numY][numX][1] + mStage.ChipSize;
			}
		}
	}
}

void Stage_Debug() {
	int no = 0;
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			no = mStage.MapChip[numY][numX];
			//if (no >= 18) {
				DrawBox(mStage.MapHitBox[numY][numX][0], mStage.MapHitBox[numY][numX][1], mStage.MapHitBox[numY][numX][2], mStage.MapHitBox[numY][numX][3], GetColor(0, 0, 0), false);
			//}
		}
	}
}