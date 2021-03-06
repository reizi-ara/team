#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//シーン：ゲームタイトル
class CObjMapChanger : public CObj
{
public:
	CObjMapChanger(float x, float y, float t);
	~CObjMapChanger() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

private:
	float m_px;	//位置
	float m_py;

	 //blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool isplayerhit;

	bool m_OneChg;

	int m_change;

	bool mmmm;

	//
	int time_a;	//製作者マップ変更コマンドの関数

	//削除用
	int destryNum;
	int MdestryNum;

};
