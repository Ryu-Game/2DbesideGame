#pragma once
#include "Input.h"
#include "Stage.h"
static class Player {
public:
	int MoveX, MoveY;	//移動座標
	int oldMoveY;
	bool inversion;

	//HitBox
	int PHitBox[4];		//right, top, left, bottom
	const int Size = 32;
	const int Center = 16;
	bool StageHit;

	//画像
	int img;
	int PlayerImage[9];	//画像格納
private:
}mPlayer;
void Player_Initialize();	//初期化
void Player_Finalize();		//終了処理
void Player_Update();		//更新
void Player_Draw();			//描画

void Player_Move(int iNowKey);		//移動処理
void Player_Jump(int iNowKey);		//ジャンプ処理
void Player_DrawSetting(int iNowky);	//画像設定
bool Player_HitBoxJudge(int PlayerHitBox[4], int Hit[4]);		//ヒットボックス
void Player_StageHit(int PlayerHitBox[4]);
void Player_Debug();		//Debug処理