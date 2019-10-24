#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjGameStart : public CObj
{
public:
	CObjGameStart() {};
	~CObjGameStart() {};
	void Init();		//イニシャライズ
	void Action();		//アクション
	void Draw();		//ドロー
private:
	bool m_key_flag;//キーフラグ
	int lavel_select;//選択時協調バー用
	bool lavel_button;//一回発動用
	bool lavel_button2;//一回発動用

};
