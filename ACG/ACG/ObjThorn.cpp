
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjThorn.h"

#define LIFE 90
#define SIZE 64*1
#define DE_MAGE 50
#define MUTEKI 20;
//使用するネームスペースdayo
using namespace GameL;

CObjThorn::CObjThorn(float x, float y, float t,float s,int w)
{
	m_px = x;	//位置
	m_py = y;

	type = t;
	Downspeed = s;

	type = w;
	size = (w-1)*32;
}

//イニシャライズ
void CObjThorn::Init()
{
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0ｆ　左向き1.0ｆ

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.0f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;

	//blockとの衝突確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	en_life = LIFE;

	float p_x = 0;
	float p_y = 0;

	hit_length = 70.0f;

	isplayerhit = false;

	time = 0;
	arw = isplayerhit;

	muteki_time = 0;

	time = 0;
	Revival_time = 0;

	ani_slowBack = 0;

	//削除用
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}

}

//アクション
void CObjThorn::Action()
{
	if (en_life > 0)
	{
		//当たり判定
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float pl_x = obj->GetX();
		float pl_y = obj->GetY();
		pl_x += 32.0f;
		pl_y += 32.0f;

		CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		float sl = block3->GetScroll();
		float en_x = m_px + 32.0f;
		float en_y = m_py + 32.0f;

		if (pl_x - sl <= en_x + hit_length + size &&
			pl_x - sl >= en_x - hit_length - size &&
			pl_y <= en_y + hit_length &&
			pl_y >= en_y - hit_length+16)
		{
			//接触時
			isplayerhit = true;

		}
		else if(isplayerhit == true)
		{
			isplayerhit = false;
			obj->GiveSpeed(1.0f);
			

		}
		else
		{
			if (m_ani_frame != 0)
			{
				ani_slowBack++;
			}
			if (ani_slowBack >= 30)
			{
				m_ani_frame--;
				ani_slowBack = 0;
			}
		}



		//当たり判定ここまで

		muteki_time--;
		if (isplayerhit == true)
		{
			obj->GiveSpeed(Downspeed);
			time++;
			if (time % 16 == 0)
				m_ani_frame += 1;
			if (m_ani_frame == 5)
			{
				m_ani_frame = 3;
			}
			if (obj->Getattack() > 0 &&
				obj->Getattack() != 4 &&
				muteki_time <= 0)
			{
				muteki_time = MUTEKI;
				en_life -= DE_MAGE;
			}
		}


		if (en_life <= 0)
		{
			obj->SetVX(0.0f);
			obj->SetVY(0.0f);
			obj->GiveSpeed(1.0f);
		}





	}
	
	if (en_life < 0)
	{
		m_ani_frame = 0;
		Revival_time++;
		if (Revival_time > 90)
		{
			en_life = LIFE;
			Revival_time = 0;
		}
		
	}


	
	
	
	//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}


	
}

//ドロー
void CObjThorn::Draw()
{

	int AniData[5] =
	{
		0,1,2,3,4
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	for (int z = 0; z < type; z++)
	{
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px + block->GetScroll() - size+64*z;
		dst.m_right = dst.m_left+ 64.0f;
		dst.m_bottom = 64.0f + m_py;

		//描画
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
}