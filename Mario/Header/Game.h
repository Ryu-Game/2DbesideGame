#pragma once
extern class Game {
public:
	char numStage;

private:
}mGame;
void Game_Initialize();	//初期化
void Game_Finalize();	//終了処理
void Game_Update();		//更新
void Game_Draw();		//描画

void Game_HitBox();		//プレイヤーとの当たり判定