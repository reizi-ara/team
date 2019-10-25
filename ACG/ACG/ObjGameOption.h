#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjGameOption : public CObj
{
public:
	CObjGameOption() {};
	~CObjGameOption() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	bool m_key_flag;//キーフラグ
	int lavel_select_op;//選択時協調バー用
	bool lavel_option;//一回発動用
	bool lavel_option2;//一回発動用


};
