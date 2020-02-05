#pragma once

#define OWATA //後で消す。


//タイトルandメニュー関連-----------------------
#define LAVEL_TOP   0		//ラベルの一番上(クレジットorスタート)

#define LAVEL_MID_M 1		//メニューラベルの真ん中(タイトルへ)
#define LAVEL_BOT_M 2		//メニューラベルの一番下(戻る)

#define LAVEL_BOT_T 1		//タイトルラベルの一番下(ゲーム終了)

//遅延処理マクロ--------------------------------
#define TIME_INI    0		//初期値 0
#define TIME_INI_M  0		//マップデバッグ初期値

#define TIME_DELAY 30		//遅延処理(主にENTERキー遅延)
#define TIME_DELAY_GO 120   //GAMEOVER遅延
#define MAP_X (100)
#define MAP_Y (10)



//エンドドア　マクロ群-----------------------------------
#define END_DOOR_HIT_LENGTH 64.0
#define END_DOOR_SISTEM_CLOSE 1
#define END_DOOR_SISTEM_OPEN 2

#define END_DOOR_CUT_TOP 0.0f
#define END_DOOR_CUT_LEFT 0.0f
#define END_DOOR_CUT_RIGHT 128.0f
#define END_DOOR_CUT_BOTTOM 128.0f

#define END_DOOR_PUT_TOP -64.0f
#define END_DOOR_PUT_LEFT -64.0f
#define END_DOOR_PUT_RIGHT 64.0f
#define END_DOOR_PUT_BOTTOM 64.0f