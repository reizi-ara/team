#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"ObjBullet.h"
#include"GameHead.h"
#include"main.h"
using namespace GameL;
using namespace std;
/*
#define A_MODE 1
#define HIT_L 16.0f
//A_MODE 0:三角関数関数使用 1:三角関数関数不使用？
CObjBullet::CObjBullet(int s)
{
	speed = s;
}
void CObjBullet::Init()
{
	CObjEnemy* enm = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	CObjHero* ply = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (enm == nullptr)
		return;
	if (ply == nullptr)
		return;

	pos_x = enm->GetEX();
	pos_y = enm->GetEY();
	angle = 0.0f;
	her_x = ply->GetHX();
	her_y = ply->GetHY();
	time_D = 0;

	if (A_MODE == 0)
	{
		angle = atan2(her_y - pos_y, her_x - pos_x);



		vec_x = cos(angle);
		vec_y = sin(angle);
	}
	else if (A_MODE == 1)
	{
		length = sqrt(pow((her_x - pos_x), 2) + pow((her_y - pos_y), 2));
		//斜辺

		vec_x = (her_x - pos_x) / length;
		vec_y = (her_y - pos_y) / length;
	}



	hit_len = HIT_L;
}

void CObjBullet::Action()
{

	CObjHero* ply1 = (CObjHero*)Objs::GetObj(OBJ_HERO);
	her_x = ply1->GetHX();
	her_y = ply1->GetHY();


	if (pos_x + 16.0f <= her_x + 16.0f + hit_len &&
		pos_x + 16.0f > her_x + 16.0f - hit_len &&
		pos_y + 16.0f <= her_y + 16.0f + hit_len &&
		pos_y + 16.0f > her_y + 16.0f - hit_len)
	{
		this->SetStatus(false);
	}



	pos_x += vec_x * speed;
	pos_y += vec_y * speed;


	if (time_D > 600)
		this->SetStatus(false);
	time_D++;
}

void CObjball::Draw()
{
	float c[4] = { 1.0f ,1.0f ,1.0f ,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 32.0f + src.m_left;
	src.m_bottom = 32.0f + src.m_top;

	dst.m_top = 0.0f + pos_y;
	dst.m_left = 0.0f + pos_x;
	dst.m_right = 32.0f + dst.m_left;
	dst.m_bottom = 32.0f + dst.m_top;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
*/