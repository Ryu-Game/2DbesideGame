#include "DxLib.h"
#include "SceneMgr.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//画面サイズの大きさ
	const int SCREEN_WIDTH = 512;		//Image(32 * 32) * 16
	const int SCREEN_HEIGHT = 384;		//Image(32 * 32) * 13(上下半分はみ出す)

	ChangeWindowMode(TRUE);				//ウィンドウモード変更
	DxLib_Init();						//Dxライブラリ初期化
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//画面サイズ
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);		//Windowサイズ
	SetDrawScreen(DX_SCREEN_BACK);		//裏画面設定
	SceneMgr_Initialize();				//初期シーン
	while (ProcessMessage() == 0) {
		ClearDrawScreen();				//画面初期化

		InputKey();					//入力情報
		
		SceneMgr_Update();				//更新
		SceneMgr_Draw();				//描画
		
		ScreenFlip();					//画面更新
	}
	SceneMgr_Finalize();				//終了画面

	DxLib_End();
	return 0;
}