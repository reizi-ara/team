#pragma once
#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjEndingDoor : public CObj
{
public:
	CObjEndingDoor(float x, float y);
	~CObjEndingDoor() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

	void DoorSystemPG(int dead) { DoorSystem = dead; }

private:
	float m_px;	//位置
	float m_py;

	int DoorSystem;//ドア開閉用変数:2開く、1閉ざす

	int hit_length;//中心からの距離

	int size;
	bool isplayerhit;

	//削除用
	int destryNum;	//生成時のマップ番号
	int MdestryNum;	//現在のマップ番号

};
