#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjBullet :public CObj
{
public:
	CObjBullet(float x, float y, float a,float s);
	~CObjBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_px;	//位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
	int atk;//攻撃力
	float speed;
	int frameQ;
};