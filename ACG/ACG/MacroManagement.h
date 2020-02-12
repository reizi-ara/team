#pragma once

#define OWATA //後で消す。

//敵マクロ-------------------------------------
#define TIME_SLOW_EE 120	//目玉の待機時間
#define TIME_RUSH_EE 360	//目玉の突撃時間


//タイトルandメニュー関連-----------------------
#define LAVEL_TOP   0		//ラベルの一番上(クレジットorスタート)

#define LAVEL_MID_M 1		//メニューラベルの真ん中(タイトルへ)
#define LAVEL_BOT_M 2		//メニューラベルの一番下(戻る)

#define LAVEL_BOT_T 1		//タイトルラベルの一番下(ゲーム終了)

#define START_CUT_TOP		0.0f	//タイトル画像切り取り上
#define START_CUT_LEFT		0.0f	//タイトル画像切り取り左
#define START_CUT_RIGHT		910.0f  //タイトル画像切り取り右
#define START_CUT_BOTTOM	512.0f	//タイトル画像切り取り下

#define START_BUTTON_CUT_TOP	0.0f	//ボタン切り取り上
#define START_BUTTON_CUT_LEFT	64.0f	//ボタン切り取り左
#define START_BUTTON_CUT_RIGHT	64.0f	//ボタン切り取り右
#define START_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define END_BUTTON_CUT_TOP		0.0f	//ボタン切り取り上
#define END_BUTTON_CUT_LEFT		0.0f	//ボタン切り取り左
#define END_BUTTON_CUT_RIGHT	64.0f	//ボタン切り取り右
#define END_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define START_BUTTON_LEFT_EXP	4		//start左拡大
#define START_BUTTON_RIGHT_EXP	8		//start右拡大

#define END_BUTTOM_RIGHT_EXP	4		//end右拡大

#define START_POS_TOP		 80		//ボタン描画上調整
#define START_POS_LEFT		150		//ボタン描画左調整
#define START_POS_RIGHT		150		//ボタン描画右調整
#define START_POS_BOTTOM	160		//ボタン描画下調整
#define END_POS_TOP			160		//エンドボタン描画上調整
#define END_POS_LEFT		150		//エンドボタン描画左調整
#define END_POS_RIGHT		150		//エンドボタン描画右調整
#define END_POS_BOTTOM		240		//エンドボタン描画下調整

//遅延処理マクロ--------------------------------
#define TIME_INI     0		//初期値 0
#define TIME_INI_HM  0		//HEROマップデバッグ初期値

#define TIME_DELAY 30		//遅延処理(主にENTERキー遅延)
#define TIME_DELAY_GO 120   //GAMEOVER遅延


#define MAP_X (100)			//マップ横
#define MAP_Y (10)			//マップ縦



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

//Boss_____________________________________________

#define BOSSMUTEKI 10;//被攻撃時無敵時間
#define PASSIVE_DAMAGE 10;//共通被ダメージ
#define SARCH 400//感知範囲、起動

#define OBJ64OFSET_CENTER 32.0f//６４サイズオブジェクト中心




//_____________________________________________








