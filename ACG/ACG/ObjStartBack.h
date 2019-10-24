#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:背景
class CObjStartBack : public CObj
{
public:
	CObjStartBack() {};
	~CObjStartBack() {};
	void Init();     //イニシャライズ
	void Action();  //アクション
	void Draw();//ドロー
private:
	float m_x;//背景1の位置情報
};
