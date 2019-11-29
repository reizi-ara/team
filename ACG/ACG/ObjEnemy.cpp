//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEnemy.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"

#define MUTEKI 20;
#define DE_MAGE 50;//hidame
#define SARCH 64*4
#define SIZE 64*1

//使用するネームスペースdayo
using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y ,float l,float a,float t)
{
	m_px = x;	//位置
	m_py = y;
	en_life=l;
	atk=a;
	type_n=t;
}

//イニシャライズ
void CObjEnemy::Init()
{
	
	awake =false;
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0ｆ　左向き1.0ｆ

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.0f;	//通常速度
	m_ani_max_time = 8;		//アニメーション間隔幅

	m_move = true;
	dir_act = m_move;
	//blockとの衝突確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	float p_x = 0;
	float p_y = 0;
	time = 0;

	muteki_time = MUTEKI;

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
void CObjEnemy::Action()
{
	//落下
	if (m_py > 1000.0f)
	{
		this->SetStatus(false);
	}

	//通常速度
	m_ani_max_time = 4;//アニメーション間隔幅


	//方向
	if (m_move==false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 2;
	}

	else if (m_move==true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 2;
	}

	if (m_ani_time>m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 8)
	{
		m_ani_frame = 0;
	}

	

	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動
	m_vy += 1.8 / (4.0f);

	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//表示位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//座標
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px+32.0f;
	float en_y = m_py+32.0f;
	if (type_n == 2)
	{
		time++;
		if (time % 120 == 0)
			m_vy = -10;
		if (time > 120)
			time = 0;
	}
	//ブロック衝突で向き変更
	if (m_hit_left == true)
		m_move = true;
	if (m_hit_right == true)
		m_move = false;
	if(pl_x - sl <= en_x - 48.0f * 6)
		m_move = true;
	if(pl_x - sl >= en_x + 48.0f * 6)
		m_move = false;

	if(dir_act==m_move)
	{ }
	else
	{
		dir_act = m_move;
		m_speed_power = 0.0f;
	}
	//与ダメージ
	if (pl_x-sl <= en_x + 48.0f&&
		pl_x - sl >= en_x- 48.0f &&
		pl_y <= en_y + 48.0f&&
		pl_y >= en_y - 48.0f&&
		m_vx!=0)
	{
		obj->GiveDamageToPlayer( atk );
		if (atk_kb == false)
		{
			if (pl_x - sl <= en_x)
			{
				obj->SetVX(-10);
			}

			else if (pl_x - sl > en_x)
			{
				obj->SetVX(10);
			}
		}
		atk_kb = true;

		

	}
	else 
	{
			atk_kb = false;
	}
	
	

	muteki_time--;
	//被攻撃
	if (pl_x - sl <= en_x + SIZE - 40.0f * (obj->Getposture() * 2 - 1) &&
		pl_x - sl >= en_x - SIZE - 40.0f * (obj->Getposture() * 2 - 1)&&
		pl_y <= en_y + 80.0f &&
		pl_y >= en_y - 80.0f&&
		obj->Getattack() > 0 &&
		obj->Getattack() != 4&&
		muteki_time<=0)
	{

		muteki_time = MUTEKI;
		en_life -= DE_MAGE;
	}

	if (en_life <= 0)
	{

		this->SetStatus(false);
	}

	//起動
	if (pl_x - sl <= en_x + 48.0f +SARCH&&
		pl_x - sl >= en_x - 48.0f - SARCH&&
		awake == false)
	{
		awake = true;
	}
	
	if (muteki_time  > 0 && awake == true)
	{
		if (pl_x - sl <= en_x)
		{
			m_vx = +m_speed_power * 10;
			//obj->SetVX(10);
		}

		else if (pl_x - sl > en_x)
		{
			m_vx = -m_speed_power * 10;
			//obj->SetVX(-10);
		}
	}
	if (muteki_time == 0)
		m_speed_power = 0;

	if (muteki_time <= 0 && awake == true)
	{
		m_speed_power += 0.011f;
	}
	if(m_speed_power>1.6f)
		m_speed_power = 1.6f;



	if(m_speed_power>3.0f)
		m_speed_power = 3.0f;



	//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}


}

//ドロー
void CObjEnemy::Draw()
{
	int AniData[8] =
	{
		0,1,2,3,4,5,6,7
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f+64.0*(type_n-1);
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = src.m_top + 64.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}