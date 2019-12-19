#pragma once
#include"GameL/SceneObjManager.h"

using namespace GameL;

class CObjBullet :public CObj
{
public:
	CObjBullet(int s);
	~CObjBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float pos_x;
	float pos_y;
	float speed;
	float angle;
	float length;

	float vec_x;
	float vec_y;

	float her_x;
	float her_y;

	float hit_len;

	int time_D;
};