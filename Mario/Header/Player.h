#pragma once
#include "Input.h"
#include "Stage.h"
static class Player {
public:
	int MoveX, MoveY;	//�ړ����W
	int oldMoveY;
	bool inversion;

	//HitBox
	int PHitBox[4];		//right, top, left, bottom
	const int Size = 32;
	const int Center = 16;
	bool StageHit;

	//�摜
	int img;
	int PlayerImage[9];	//�摜�i�[
private:
}mPlayer;
void Player_Initialize();	//������
void Player_Finalize();		//�I������
void Player_Update();		//�X�V
void Player_Draw();			//�`��

void Player_Move(int iNowKey);		//�ړ�����
void Player_Jump(int iNowKey);		//�W�����v����
void Player_DrawSetting(int iNowky);	//�摜�ݒ�
bool Player_HitBoxJudge(int PlayerHitBox[4], int Hit[4]);		//�q�b�g�{�b�N�X
void Player_StageHit(int PlayerHitBox[4]);
void Player_Debug();		//Debug����