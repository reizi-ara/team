#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:主人公
class CObjGameClear : public CObj
{
public:
	CObjGameClear() {};
	~CObjGameClear() {};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();//ドロー

private:
	bool m_key_flag;
	bool ReturnKey_flag;
	int time;
	int Endnum;
	bool one_flag;
};

