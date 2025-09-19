#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"

Game mGame;
/******************************
* 初期化処理
*******************************/
void Game_Initialize() {
	mGame.numStage = 1;		//ゲームステージ数初期化
	Stage_Initialize();		//ステージ初期化
	Player_Initialize();	//プレイヤー初期化
}

/******************************
* 終了処理
*******************************/
void Game_Finalize() {
	Stage_Finalize();	//ステージ終了
	Player_Finalize();	//プレイヤー終了処理
}

/******************************
* 更新処理
*******************************/
void Game_Update() {
	//Escキーで強制終了
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
		SceneMgr_ChangeScene(eScene_Menu);
	}

	Stage_Update();		//ステージ更新
	Player_Update();	//プレイヤー更新
}

/******************************
* 描画処理
*******************************/
void Game_Draw() {
	Stage_Draw();		//ステージ描画
	Player_Draw();		//プレイヤー描画
}