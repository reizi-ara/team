#pragma once
#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjCandle : public CObj
{
public:
	CObjCandle(float x, float y);
	~CObjCandle() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

	

private:
	float m_px;	//位置
	float m_py;

	float m_ani_max_time;//アニメーション動作間隔

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool isplayerhit;
	bool menu_flag;

	//メニュー
	int lavel_select;	//上下ボタンセレクト用
	bool lavel_button;//一回発動用
	bool lavel_button2;//一回発動用

	//メニュー展開時の操作フラグ
	bool p_menuflag;
	bool p_menu_close;




	//削除用
	int destryNum;
	int MdestryNum;

	int time, times;
	int Unfold;

};

