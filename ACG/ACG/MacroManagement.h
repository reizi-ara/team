#pragma once

//シーンメインマクロ郡----------------------------------
//マップ番号
#define MAP_NUMBER_1 0
#define MAP_NUMBER_2 1
#define MAP_NUMBER_3 2
#define MAP_NUMBER_4 3
#define MAP_NUMBER_5 4

#define MAP_NULL_NUMBER 5	//マップが無くなる数字

//グラフィック読み込み番号
#define SPLITE_NUMBER_0 0
#define SPLITE_NUMBER_1 1
#define SPLITE_NUMBER_2 2
#define SPLITE_NUMBER_3 3
#define SPLITE_NUMBER_4 4
#define SPLITE_NUMBER_5 5
#define SPLITE_NUMBER_6 6
#define SPLITE_NUMBER_7 7
#define SPLITE_NUMBER_8 8

//BGM
#define SCENE_MAIN_BGM_MAINSTAGE	0	//メインBGM
#define SCENE_MAIN_BGM_BOSS			1	//ボスBGM
#define SCENE_MAIN_BGM_MENU			2	//メニューBGM

#define SCENE_MAIN_SE_WALK			5	//歩き、走りSE
#define SCENE_MAIN_SE_DOOR			6	//ドアSE
#define SCENE_MAIN_SE_DAMEGE		7	//ダメージSE
#define SCENE_MAIN_SE_DECIDE		8	//決定SE
#define SCENE_MAIN_SE_SELECT		9	//セレクトSE
#define SCENE_MAIN_SE_BOOK_OPEN		10	//本棚開きSE
#define SCENE_MAIN_SE_BOOK_CLOSE	11	//本棚閉じSE
#define SCENE_MAIN_SE_HAND			12	//手SEとダメージ
#define SCENE_MAIN_SE_ATTACK		13	//攻撃SE

//MapRead関数で使うマクロ
#define SCENE_MAIN_MAP_READ_COUNT 1		//MapReadカウント初期値
#define SCENE_MAIN_MAP_READ_INITIAL_Y 0	//Y初期値
#define SCENE_MAIN_MAP_READ_INITIAL_X 0	//X初期値

//ブロックマクロ群-----------------------------------------
#define BLOOK_BACK_SCROLL_LINE		7*1.6f		//後方スクロールライン 
#define BLOOK_PREVIOUS_SCROLL_LINE	7*4.0f		//前方スクロールライン 

//空白
#define BLOOK_NULL_NUMBER 0

//エネミー
#define BLOOK_ENEMY_PJ_NUMBER		20			//サークル
#define BLOOK_ENEMY_EYE_NUMBER		21			//目
#define BLOOK_ENEMY_DOC_NUMBER		22			//犬
#define BLOOK_ENEMY_CACTUS_NUMBER	23			//サボテン

//アイテム
#define BLOOK_ITEM_HEAL_NUMBER		25			//回復
#define BLOOK_ITEM_BIGHEAL_NUMBER	26			//大回復

//ボス
#define BLOOK_ENEMY_BOSS_NUMBER		27			//ボス

//トラップ
#define BLOCK_TRAP_HAND_NUMBER		30			//手
#define BLOCK_TRAP_THORN3_NUMBER	33			//ツタ3
#define BLOCK_TRAP_THORN7_NUMBER	37			//ツタ7

//置物、その他
#define BLOCK_OBJ_CANDLE_NUMBER		39			//キャンドル
#define BLOCK_OBJ_NEXT_DOOR_NUMBER	40			//ドア進み
#define BLOCK_OBJ_BACK_DOOR_NUMBER	41			//ドア戻り
#define BLOCK_OBJ_END_DOOR_NUMBER	42			//ドアEND
#define BLOCK_OBJ_BOOK1_NUMBER		50			//本棚1
#define BLOCK_OBJ_BOOK2_NUMBER		51			//本棚2
#define BLOCK_OBJ_BOOK3_NUMBER		52			//本棚3
#define BLOCK_OBJ_BOOK4_NUMBER		53			//本棚4
#define BLOCK_OBJ_BOOK5_NUMBER		54			//本棚5

//本棚タイプ
#define BLOCK_BOOK_TYPE1 1
#define BLOCK_BOOK_TYPE2 2
#define BLOCK_BOOK_TYPE3 3
#define BLOCK_BOOK_TYPE4 4
#define BLOCK_BOOK_TYPE5 5

//敵マクロ-------------------------------------
#define ENEMY_PJ_TYPE		1	//パンジャン
#define ENEMY_EYE_TYPE		2	//目タイプ
#define ENEMY_DOG_TYPE		3	//犬タイプ
#define ENEMY_GREEN_TYPE	4	//サボテンタイプ
#define ENEMY_HEAL_TYPE		5	//回復タイプ


#define TIME_SLOW_EE 120	//目玉の待機時間
#define TIME_RUSH_EE 360	//目玉の突撃時間


//Boss_____________________________________________

#define BOSSMUTEKI 10;//被攻撃時無敵時間
#define PASSIVE_DAMAGE 10;//共通被ダメージ
#define SARCH 400//感知範囲、起動

#define OBJ64OFSET_CENTER 32.0f//６４サイズオブジェクト中心


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

//END扉閉じ切り取り位置
#define END_DOOR_CLOSE_CUT_TOP 0.0f
#define END_DOOR_CLOSE_CUT_LEFT 0.0f
#define END_DOOR_CLOSE_CUT_RIGHT 128.0f
#define END_DOOR_CLOSE_CUT_BOTTOM 128.0f

//END扉開き切り取り位置
#define END_DOOR_OPEN_CUT_TOP 0.0f
#define END_DOOR_OPEN_CUT_LEFT 128.0f
#define END_DOOR_OPEN_CUT_RIGHT 128.0f*2
#define END_DOOR_OPEN_CUT_BOTTOM 128.0f

//END扉表示位置
#define END_DOOR_PUT_TOP -64.0f
#define END_DOOR_PUT_LEFT -64.0f
#define END_DOOR_PUT_RIGHT 64.0f
#define END_DOOR_PUT_BOTTOM 64.0f



//ゲームクリア-------------------------------
#define GAME_CLEAR_CUT_RIGHT	128*7		//ゲームクリア背景切り取り右
#define GAME_CLEAR_CUT_BOTTOM	1024/2		//ゲームクリア背景切り取り下

//ゲームオーバー-----------------------------
#define GAME_OVER_CUT_TOP		512.0f		//ゲームオーバー背景切り取り上

#define GAME_OVER_CUT_RIGHT		910.0f		//ゲームオーバー背景切り取り右
#define GAME_OVER_CUT_BOTTOM	1024.0f		//ゲームオーバー背景切り取り下

//メッセージウィンドウ-----------------------
#define MESSAGE_CUT_TOP			64.0f*6		//メッセージウィンドウ切り取り上
#define MESSAGE_CUT_LEFT		64.0f*0		//メッセージウィンドウ切り取り左
#define MESSAGE_CUT_RIGHT		64.0f*8		//メッセージウィンドウ切り取り右
#define MESSAGE_CUT_BOTTOM		64.0f*8		//メッセージウィンドウ切り取り下

#define MESSAGE_SENTENCE_W		150			//メッセージ行頭横軸
#define MESSAGE_SENTENCE1_H		550			//メッセージ1行目縦軸
#define MESSAGE_SENTENCE2_H		575			//メッセージ2行目縦軸
#define MESSAGE_SENTENCE3_H		600			//メッセージ3行目縦軸
#define MESSAGE_SENTENCE4_H		625			//メッセージ4行目縦軸
#define MESSAGE_SENTENCE5_H		650			//メッセージ5行目縦軸

#define MESSAGE_PRO_SENTENCE_W	250			//プロローグメッセ

#define MESSAGE_SENTENCE_SIZE	25			//メッセージ文字サイズ
//_____________________________________________

//接触時当たり判定
#define HIT_AREA_X      32.0f     //x軸の当たり判定の＋値
#define HIT_AREA_Y      32.0f     //y軸の当たり判定の＋値