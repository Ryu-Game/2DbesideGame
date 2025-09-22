#pragma once
#include "Input.h"
static class Player {
public:
	int MoveX, MoveY;	//移動座標
	int oldMoveY;
	bool inversion;

	//HitBox
	int PHitBox[4];		//right, top, left, bottom
	int Size = 32;

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
void Player_HitBox();		//ヒットボックス
void Player_Debug();		//Debug処理