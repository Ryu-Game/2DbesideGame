#include "DxLib.h"
#include "Player.h"
#include "Input.h"

//変数
int YDeath = 320;
int ImgSwitch = false;
int JumpMax;
bool Jumpflg;

/******************************
* 初期化処理
*******************************/
void Player_Initialize() {
	//プレイヤー座標
	mPlayer.MoveX = 80 + mPlayer.Size / 2;
	mPlayer.MoveY = 320;
	for (int num = 0; num < 4; num++) {
		mPlayer.PHitBox[num] = 0;
	}
	mPlayer.inversion = FALSE;

	JumpMax = mPlayer.MoveY + mPlayer.Size * 4;
	Jumpflg = false;

	//プレイヤー画像格納
	mPlayer.img = 0;
	LoadDivGraph("images/char/mario.png", 9, 9, 1, 32, 32, mPlayer.PlayerImage);
}

/******************************
* 終了処理
*******************************/
void Player_Finalize() {

}

/******************************
* 更新処理
*******************************/
void Player_Update() {
	Player_Move(iNowKey);
	Player_Jump(iNowKey);
	Player_HitBox();
	Player_DrawSetting(iNowKey);
	//仮地面
	if (mPlayer.MoveY > YDeath) {
		mPlayer.MoveY = YDeath;
	}

	if (mPlayer.MoveY < mPlayer.oldMoveY) {
		mPlayer.MoveY += 2;
	}
	else {
		Jumpflg = false;
	}

	JumpMax = mPlayer.Size * 4;
}

/******************************
* 描画処理
*******************************/
void Player_Draw() {
	DrawRotaGraph(mPlayer.MoveX, mPlayer.MoveY,1.0,0, mPlayer.PlayerImage[mPlayer.img], TRUE,mPlayer.inversion);

	//Debug処理
	Player_Debug();
}

/******************************
* 関数
*******************************/
void Player_Move(int iNowKey) {
	switch (iNowKey) {
	case PAD_INPUT_RIGHT:
		mPlayer.MoveX += 1;
		mPlayer.inversion = FALSE;
		break;
	case PAD_INPUT_LEFT:
		mPlayer.MoveX -= 1;
		mPlayer.inversion = TRUE;
		break;
	}
}

void Player_Jump(int iNowKey) {
	if (Jumpflg == false) {
		if ((iNowKey & PAD_INPUT_1) || (iNowKey & PAD_INPUT_UP)) {	//SPACE入力処理
			mPlayer.oldMoveY = mPlayer.MoveY;
			mPlayer.MoveY -= JumpMax;
			Jumpflg = true;
		}
	}
	
}

void Player_HitBox() {
	//プレイヤーHitBox
	int Center = mPlayer.Size / 2;
	for (int num = 0; num < 4; num++) {
		switch (num) {
		case 0:	//left
			mPlayer.PHitBox[num] = mPlayer.MoveX - 10;
			break;
		case 1:	//top
			mPlayer.PHitBox[num] = mPlayer.MoveY - Center;
			break;
		case 2:	//right
			mPlayer.PHitBox[num] = mPlayer.MoveX + 10;
			break;
		case 3:	//bottom
			mPlayer.PHitBox[num] = mPlayer.MoveY + Center;
			break;
		}
	}

}

void Player_DrawSetting(int iNowKey) {
	if (Jumpflg == false) {		//ジャンプ中じゃない
		if ((iNowKey & PAD_INPUT_RIGHT) || (iNowKey & PAD_INPUT_LEFT)) {
			//画像処理(1～3を繰り返す)
			if (ImgSwitch == false) {
				mPlayer.img++;
				if (mPlayer.img >= 4) {
					ImgSwitch = true;
					mPlayer.img = 3;
				}
			}
			else if (ImgSwitch == true) {
				mPlayer.img--;
				if (mPlayer.img <= 0) {
					ImgSwitch = false;
					mPlayer.img = 1;
				}
			}
		}
		else if (iNowKey == 0) {
			mPlayer.img = 0;
		}
	}
	else if(Jumpflg == true){		//ジャンプ中
		mPlayer.img = 5;
	}
}

/******************************
* Debug
*******************************/
void Player_Debug() {
	DrawBox(mPlayer.PHitBox[0], mPlayer.PHitBox[1], mPlayer.PHitBox[2], mPlayer.PHitBox[3], GetColor(0, 0, 0), true);
	DrawFormatString(200, 0, GetColor(255, 255, 255), "%d", mPlayer.PHitBox[1]);
	DrawFormatString(236, 0, GetColor(255, 255, 255), "%d", mPlayer.PHitBox[3]);
}