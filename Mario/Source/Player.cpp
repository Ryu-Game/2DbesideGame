#include "DxLib.h"
#include "Player.h"
#include "Input.h"
#include "SceneMgr.h"

//�ϐ�
int YDeath = 320;
int ImgSwitch = false;
int JumpMax;
bool Jumpflg;

/******************************
* ����������
*******************************/
void Player_Initialize() {
	//�v���C���[���W
	mPlayer.MoveX = 80 + mPlayer.Size / 2;
	mPlayer.MoveY = 320;
	mPlayer.oldMoveY = mPlayer.MoveY;
	for (int num = 0; num < 4; num++) {
		mPlayer.PHitBox[num] = 0;
	}
	mPlayer.inversion = FALSE;
	mPlayer.StageHit = FALSE;

	JumpMax = mPlayer.MoveY + mPlayer.Size * 4;
	Jumpflg = false;

	//�v���C���[�摜�i�[
	mPlayer.img = 0;
	LoadDivGraph("images/char/mario.png", 9, 9, 1, 32, 32, mPlayer.PlayerImage);
}

/******************************
* �I������
*******************************/
void Player_Finalize() {

}

/******************************
* �X�V����
*******************************/
void Player_Update() {
	Player_Move(iNowKey);
	Player_Jump(iNowKey);
	Player_DrawSetting(iNowKey);
	//PlayerHitBox�X�V
	for (int num = 0; num < 4; num++) {
		switch (num) {
		case 0:	//left
			mPlayer.PHitBox[num] = mPlayer.MoveX - 10;
			break;
		case 1:	//top
			mPlayer.PHitBox[num] = mPlayer.MoveY - mPlayer.Center;
			break;
		case 2:	//right
			mPlayer.PHitBox[num] = mPlayer.MoveX + 10;
			break;
		case 3:	//bottom
			mPlayer.PHitBox[num] = mPlayer.MoveY + mPlayer.Center;
			break;
		}
	}
	Player_StageHit(mPlayer.PHitBox);

	if (mPlayer.MoveY > mgr.SCREEN_WIDTH) {	//�������Ė߂�
		mPlayer.MoveY = YDeath;
	}

	if (mPlayer.StageHit == FALSE) {	//���R����
		mPlayer.MoveY += 2;
	}
	else {
		Jumpflg = FALSE;
	}


	JumpMax = mPlayer.Size * 4;
}

/******************************
* �`�揈��
*******************************/
void Player_Draw() {
	DrawRotaGraph(mPlayer.MoveX, mPlayer.MoveY,1.0,0, mPlayer.PlayerImage[mPlayer.img], TRUE,mPlayer.inversion);

	//Debug����
	Player_Debug();
}

/******************************
* �֐�
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
		if ((iNowKey & PAD_INPUT_1) || (iNowKey & PAD_INPUT_UP)) {	//SPACE���͏���
			mPlayer.oldMoveY = mPlayer.MoveY;
			mPlayer.MoveY -= JumpMax;
			Jumpflg = true;
		}
	}
	
}

//�v���C���[�Ƃ̓����蔻�菈��
bool Player_HitBoxJudge(int PlayerHitBox[4], int Hit[4]) {
	if ((PlayerHitBox[1] <= Hit[3] && PlayerHitBox[0] >= Hit[2]) ||
		(PlayerHitBox[1] <= Hit[3] && PlayerHitBox[2] <= Hit[0]) ||
		(PlayerHitBox[3] >= Hit[1] && PlayerHitBox[0] >= Hit[2]) ||
		(PlayerHitBox[3] >= Hit[1] && PlayerHitBox[2] <= Hit[0])){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//�v���C���[�ƃX�e�[�W�̓����蔻��
void Player_StageHit(int PlayerHitBox[4]) {
	int Judge[4] = {	//�v���C���[�ƃX�e�[�W
			mPlayer.PHitBox[0] + mPlayer.Size,
			mPlayer.PHitBox[1] - mPlayer.Size,
			mPlayer.PHitBox[2] - mPlayer.Size,
			mPlayer.PHitBox[3] + mPlayer.Size,
	};

	for (int numY = 0; numY < mStage.ChipY; numY++) {
		for (int numX = 0; numX < mStage.ChipX; numX++) {
			if (mStage.MapHitBox[numY][numX][0] <= Judge[0] &&
				mStage.MapHitBox[numY][numX][1] >= Judge[1] &&
				mStage.MapHitBox[numY][numX][2] >= Judge[2] &&
				mStage.MapHitBox[numY][numX][3] <= Judge[3]) {
					mPlayer.StageHit = Player_HitBoxJudge(mPlayer.PHitBox, mStage.MapHitBox[numY][numX]);
					if (mPlayer.StageHit == TRUE) break;
			}
		}
		if (mPlayer.StageHit == TRUE) {
			mPlayer.MoveY = mPlayer.oldMoveY;
			break;
		}
	}
}

void Player_DrawSetting(int iNowKey) {
	if (Jumpflg == false) {		//�W�����v������Ȃ�
		if ((iNowKey & PAD_INPUT_RIGHT) || (iNowKey & PAD_INPUT_LEFT)) {
			//�摜����(1�`3���J��Ԃ�)
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
	else if(Jumpflg == true){		//�W�����v��
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