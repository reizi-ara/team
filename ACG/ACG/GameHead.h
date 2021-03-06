#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_TIME,
	OBJ_ENEMY,
	

	OBJ_GAME_START,
	OBJ_GAME_OVER,
	OBJ_GAME_OPTION,
	OBJ_GAME_CLEAR,
	OBJ_PROLOGUE,

	OBJ_MENU,

	OBJ_TUTA,
	OBJ_CANDLE,

	OBJ_MAPCHANGER,
	OBJ_MAPBACKER,
	OBJ_ENDING_DOOR,

	OBJ_HAND,
	OBJ_THORN,
	OBJ_MESSAGE,
	OBJ_MESSAGE2,
	OBJ_BOSS
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------

#include "ObjBlock.h"
#include "ObjTime.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "ObjEffect.h"
#include "Objmessage.h"
#include "ObjMessage2.h"
#include "ObjEndingDoor.h"
#include "ObjCandle.h"

#include "ObjHero.h"
#include "ObjEnemy.h"
#include "Objhand.h"
#include "ObjBoss.h"
#include "ObjThorn.h"
#include "ObjTuta.h"
#include "Objbullet.h"

#include "ObjGameStart.h"
#include "ObjGameOption.h"
#include "ObjPrologue.h"
#include "ObjGameOver.h"
#include "ObjGameClear.h"

#include "MacroManagement.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneGameStart.h"
#include "SceneGameOver.h"
#include "SceneGameOption.h"
#include "SceneGameClear.h"
#include "ScenePrologue.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneGameStart
//-----------------------------------------------