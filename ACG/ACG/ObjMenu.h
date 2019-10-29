#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjMenu : public CObj
{
public:
	CObjMenu() {};
	~CObjMenu() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー

	int p_menuflag;		//メニュー展開フラグ
private:
	bool m_key_flag;//キーフラグ
	int lavel_select;//選択時協調バー用
	bool lavel_button;//一回発動用
	bool lavel_button2;//一回発動用
	
	bool p_itemflag;	//アイテムフラグ
	bool p_equipflag;   //装備フラグ
	bool p_charaflag;	//キャラクターフラグ
	bool p_saveflag;	//セーブフラグ
};
