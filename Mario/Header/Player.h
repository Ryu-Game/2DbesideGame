#pragma once
static class Player {
public:
	int MoveX, MoveY;	//�ړ����W

	int PlayerImage[9];	//�摜�i�[
private:
}mPlayer;
void Player_Initialize();	//������
void Player_Finalize();		//�I������
void Player_Update();		//�X�V
void Player_Draw();			//�`��