#include "DxLib.h"
#include "Player.h"

/******************************
* ����������
*******************************/
void Player_Initialize() {
	mPlayer.MoveX = 80;
	mPlayer.MoveY = 304;
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

}

/******************************
* �`�揈��
*******************************/
void Player_Draw() {
	DrawGraph(mPlayer.MoveX, mPlayer.MoveY, mPlayer.PlayerImage[0], true);
}