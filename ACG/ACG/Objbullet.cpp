#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"ObjBullet.h"
#include"GameHead.h"
#include"main.h"
using namespace GameL;
using namespace std;

#define A_MODE 1
#define HIT_L 16.0f
//A_MODE 0:三角関数関数使用 1:三角関数関数不使用？
CObjBullet::CObjBullet(float x, float y,  float a,float s)
{
	m_px = x;	//位置
	m_py = y;
	atk = a;
	speed = s;
}
void CObjBullet::Init()
{
	m_vx = 0;// -speed;
	m_vy=speed;
	frameQ=0;
	
}
void CObjBullet::Action()
{
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	float sl = block->GetScroll();

	if (pl_x - sl <= m_px + 48.0f &&
		pl_x - sl >= m_px -48.0f &&
		pl_y <= m_py + 48.0f &&
		pl_y >= m_py - 48.0f) {
		obj->GiveDamageToPlayer(atk);
	}


	//表示位置の更新
	m_px += m_vx;
	if (frameQ > 20) {
		m_py += m_vy;
		m_vy += 0.2;
	}

	frameQ++;

	if (frameQ > 500)
		this->SetStatus(false);
}

void CObjBullet::Draw()
{
	float c[4] = { 1.0f ,1.0f ,1.0f ,1.0f };
	RECT_F src;
	RECT_F dst;


	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	src.m_top = 196.0f;
	src.m_left = 64.0f*(frameQ%4);
	src.m_right = 64.0f + src.m_left;
	src.m_bottom = 64.0f + src.m_top;

	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px+block->GetScroll(); 
	dst.m_right = 64.0f + dst.m_left;
	dst.m_bottom = 64.0f + dst.m_top;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
