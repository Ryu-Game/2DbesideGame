#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Stage.h"
Game mGame;

/******************************
* 初期化処理
*******************************/
void Game_Initialize() {
	//mGame.Stage = 0;
	Stage_Initialize();
}

/******************************
* 終了処理
*******************************/
/*void Game_Finalize() {
	Stage_Finalize();
}*/

/******************************
* 更新処理
*******************************/
void Game_Update() {
	//ゲーム処理
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);
	}
}

/******************************
* 描画処理
*******************************/
void Game_Draw() {
	Stage_Update();
	Stage_Draw();
	DrawString(20, 380, "ゲーム画面です。", GetColor(136, 136, 255));
	DrawString(20, 420, "Escキーを押すと メニュー画面に戻ります。", GetColor(136, 136, 255));
}