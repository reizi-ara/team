#pragma once
#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;



//シーン：ゲームタイトル
class CObjMapBacker : public CObj
{
public:
	CObjMapBacker(float x, float y, float t);
	~CObjMapBacker() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

	//int GetTT() { return m_change; }
	//int GetONE() { return m_OneChg; }

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

	//マップ変更用変数群
	bool m_OneChg;
	bool mmmm;

	int m_change;


};
