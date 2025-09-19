#include "DxLib.h"
#include "Stage.h"
#include "Game.h"

Stage mStage;
/******************************
* ‰Šú‰»ˆ—
*******************************/
void Stage_Initialize() {
	//mStage.numStage = mGame.Stage;
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			mStage.MapChip[numY][numX] = 0;
		}
	}
	Stage_Stroge();
}

/******************************
* I—¹ˆ—
*******************************/
//void Stage_Finalize() {
//
//}

/******************************
* XVˆ—
*******************************/
void Stage_Update() {
	mStage.MapBackChip = { {
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{16,16,16,16,16, 16,16,16,16,16, 16,16,16,16,16, 16},
			{17,17,17,17,17, 17,17,17,17,17, 17,17,17,17,17, 17},
			{17,17,17,17,17, 17,17,17,17,17, 17,17,17,17,17, 17},
		}
	};
	mStage.MapChip = { {
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,7,5,9, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,6,4,8, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,15,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,10,14,11,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{10,14,12,13,11, 0,0,0,0,0, 0,1,2,2,2, 3},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
		}
	};
}

/******************************
* •`‰æˆ—
*******************************/
void Stage_Draw() {
	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			//”wŒi‰æ‘œ
			int no = mStage.MapBackChip[numY][numX];
			DrawGraph(numX * mStage.Chip, (numY * mStage.Chip) + mStage.DrawY, mStage.MapImage[no], FALSE);
			//•\‰æ‘œ
			no = mStage.MapChip[numY][numX];
			DrawGraph(numX * mStage.Chip, (numY * mStage.Chip) + mStage.DrawY, mStage.MapImage[no], TRUE);
		}
	}
}

/******************************
* ŠÖ”
*******************************/
void Stage_Stroge() {
	mStage.MapImage[0] = 0;			//‰æ‘œ–³

	//”wŒi‰æ‘œ
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
	mStage.MapImage[17] = LoadGraph("images/Block/floor.png");
	mStage.MapImage[18] = LoadGraph("images/Block/kai_block.png");

	//ƒuƒƒbƒN‰æ‘œ(MapChip19`20)
	mStage.BlockImage[0] = LoadGraph("images/Block/bloak_1.png");
	mStage.BlockImage[1] = LoadGraph("images/Block/block.png");

	//“yŠÇ‰æ‘œ(MapChip21`24)
	mStage.ClayPipeImage[0] = LoadGraph("images/Block/dokan_left_down.png");
	mStage.ClayPipeImage[1] = LoadGraph("images/Block/dokan_left_up.png");
	mStage.ClayPipeImage[2] = LoadGraph("images/Block/dokan_right_down.png");
	mStage.ClayPipeImage[3] = LoadGraph("images/Block/dokan_right_up.png");

	//‚Í‚Ä‚ÈƒuƒƒbƒN‰æ‘œ(MapChip25`29)
	LoadDivGraph("images/Block/hatena.png", 4, 4, 1, 32, 32, mStage.QuestionImage);
	mStage.QuestionImage[4] = LoadGraph("images/Block/kara_block.png");
}