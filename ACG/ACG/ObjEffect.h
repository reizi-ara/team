#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjEffect :public CObj
{
public:
	CObjEffect(float x, float y, float t);
	~CObjEffect() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー


private:
	float m_px;
	float m_py;
	int type;
	int time;

};
