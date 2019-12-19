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
	float m_px;	//�ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	int atk;//�U����
	float speed;
	int frameQ;
};