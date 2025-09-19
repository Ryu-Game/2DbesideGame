#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
static int mImageHandle; //画像ハンドル格納用変数

/******************************
* 初期化処理
*******************************/
void Menu_Initialize() {
	//mImageHandle = LoadGraph(TEXT("images/Screen/Scene_Menu.png")); //画像のロード
}

/******************************
* 終了処理
*******************************/
void Menu_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}

/******************************
* 更新処理
*******************************/
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) {
		SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		DxLib_End();
	}
}

/******************************
* 描画処理
*******************************/
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(20, 360, TEXT("メニュー画面です。"), GetColor(136, 136, 255));
	DrawString(20, 380, TEXT("Gキーを押すとゲーム画面に進みます。"), GetColor(136, 136, 255));
	DrawString(20, 400, TEXT("Cキーを押すと 設定画面に進みます。"), GetColor(136, 136, 255));
	DrawString(20, 420, TEXT("ESCキーを押すと 終了します。"), GetColor(136, 136, 255));
}