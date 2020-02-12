#pragma once

#define OWATA //後で消す。

//敵マクロ-------------------------------------
#define TIME_SLOW_EE 120	//目玉の待機時間
#define TIME_RUSH_EE 360	//目玉の突撃時間


//ロウソク-------------------------
#define CANDLE_CUT_TOP		64.0f * 4	//ロウソク切り取り上
#define CANDLE_CUT_LEFT		64.0f * 5	//ロウソク切り取り左
#define CANDLE_CUT_RIGHT	64.0f * 6	//ロウソク切り取り右
#define CANDLE_CUT_BOTTOM	64.0f * 5	//ロウソク切り取り下

#define CANDLE_PUT_TOP		-16.0f			//ロウソク描画上
#define CANDLE_PUT_LEFT		 0.0f - 16.0f	//ロウソク描画左
#define CANDLE_PUT_RIGHT	64.0f + 16.0f	//ロウソク描画右
#define CANDLE_PUT_BOTTOM	64.0f			//ロウソク描画下



//タイトルandメニュー関連-----------------------
#define LAVEL_TOP   0		//ラベルの一番上(クレジットorスタート)

#define LAVEL_MID_MENU  1		//メニューラベルの真ん中(タイトルへ)
#define LAVEL_BOT_MENU  2		//メニューラベルの一番下(戻る)

#define LAVEL_BOT_TITLE 1		//タイトルラベルの一番下(ゲーム終了)

#define START_BACK_CUT_TOP		0.0f	//タイトル画像切り取り上
#define START_BACK_CUT_LEFT		0.0f	//タイトル画像切り取り左
#define START_BACK_CUT_RIGHT	910.0f  //タイトル画像切り取り右
#define START_BACK_CUT_BOTTOM	512.0f	//タイトル画像切り取り下

#define START_BUTTON_CUT_TOP	0.0f	//ボタン切り取り上
#define START_BUTTON_CUT_LEFT	64.0f*4	//ボタン切り取り左
#define START_BUTTON_CUT_RIGHT	64.0f*8	//ボタン切り取り右
#define START_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define END_BUTTON_CUT_TOP		0.0f	//ボタン切り取り上
#define END_BUTTON_CUT_LEFT		0.0f	//ボタン切り取り左
#define END_BUTTON_CUT_RIGHT	64.0f*4	//ボタン切り取り右
#define END_BUTTON_CUT_BOTTOM	64.0f	//ボタン切り取り下

#define START_POS_PUT_TOP		 80		//ボタン描画上調整
#define START_POS_PUT_LEFT		150		//ボタン描画左調整
#define START_POS_PUT_RIGHT		150		//ボタン描画右調整
#define START_POS_PUT_BOTTOM	160		//ボタン描画下調整
#define END_POS_PUT_TOP			160		//エンドボタン描画上調整
#define END_POS_PUT_LEFT		150		//エンドボタン描画左調整
#define END_POS_PUT_RIGHT		150		//エンドボタン描画右調整
#define END_POS_PUT_BOTTOM		240		//エンドボタン描画下調整

#define MENU_BACK_CUT_TOP		0.0f	//メニュー画像切り取り上
#define MENU_BACK_CUT_LEFT		0.0f	//メニュー画像切り取り左
#define MENU_BACK_CUT_RIGHT		910.0f  //メニュー画像切り取り右
#define MENU_BACK_CUT_BOTTOM	512.0f	//メニュー画像切り取り下

#define MENU_BACK_PUT_TOP		0.0f	//メニュー背景描画上
#define MENU_BACK_PUT_LEFT		0.0f	//メニュー背景描画左

#define MENU_BAR_W				220		//メニュー矢印横軸
#define MENU_BAR_H				90		//メニュー矢印縦軸

#define MENU_BAR_MOVE			50		//メニューバー移動幅
#define MENU_BAR_SIZE			50		//メニューバーサイズ

#define MENU_LAVEL_W			50		//メニューラベル行頭横軸
#define MENU_LAVEL_CREDIT_H		100		//「クレジット」縦軸
#define MENU_LAVEL_ESC_H		150		//「タイトルへ」縦軸
#define MENU_LAVEL_BACK_H		200		//「戻る」縦軸
#define MENU_LAVEL_SIZE			32		//メニューラベルサイズ

#define MENU_CREDIT_CON_HEAD_W	690		//「クレジット一覧」横軸
#define MENU_CREDIT_CON_HEAD_H	40		//「クレジット一覧」縦軸
#define MENU_CREDIT_CON_HEAD_SIZE	32	//「クレジット一覧」サイズ

#define MENU_CREDIT_CON_W		350		//クレジット中身行頭横軸
#define MENU_CREATOR_H			70		//「制作者」縦軸
#define MENU_MEMBER1_H			100		//メンバー縦軸
#define MENU_MEMBER2_H			135		//メンバー縦軸
#define MENU_MEMBER3_H			170		//メンバー縦軸
#define MENU_MEMBER4_H			205		//メンバー縦軸
#define MENU_MEMBER5_H			240		//メンバー縦軸

#define MENU_OFFER_H			300		//「BGM・効果音」縦軸
#define MENU_URL1_H				330		//url縦軸
#define MENU_URL2_H				365		//url縦軸
#define MENU_URL3_H				400		//url縦軸
#define MENU_URL4_H				435		//url縦軸
#define MENU_URL5_H				470		//url縦軸
#define MENU_URL6_H				505		//url縦軸
#define MENU_URL7_H				540		//url縦軸
#define MENU_URL8_H				575		//url縦軸
#define MENU_URL9_H				330		//url縦軸

#define MENU_CON_GENRE_SIZE		20		//クレジット中身ジャンルサイズ
#define MENU_CREDIT_CON_SIZE	27		//クレジット中身サイズ

#define MENU_CON_TXT_W			400		//メニューテキスト縦軸
#define MENU_CON_TXT_H			300		//メニューテキスト横軸
#define MENU_CON_TXT_SIZE		45		//メニューテキストサイズ


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



//メッセージウィンドウ-----------------------
#define MESSAGE_CUT_TOP			64.0f*6		//メッセージウィンドウ切り取り上
#define MESSAGE_CUT_LEFT		64.0f*0		//メッセージウィンドウ切り取り左
#define MESSAGE_CUT_RIGHT		64.0f*8		//メッセージウィンドウ切り取り右
#define MESSAGE_CUT_BOTTOM		64.0f*8		//メッセージウィンドウ切り取り下


//_____________________________________________








