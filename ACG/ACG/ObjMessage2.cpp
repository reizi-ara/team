
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

#include "GameHead.h"
#include "Objmessage2.h"
#include "main.h"

#define LIFE 80;
//使用するネームスペースdayo
using namespace GameL;

CObjMessage2::CObjMessage2(float x, float y, float t)
{
	m_px = x;	//位置
	m_py = y;

	type = t;
}

//イニシャライズ
void CObjMessage2::Init()
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

	hit_length = 64.0f;

	size = 0;
	Message_flag = false;
	book_isplayerhit = false;

}

//アクション
void CObjMessage2::Action()
{

	//通常速度
	m_ani_max_time = 8;//アニメーション間隔幅



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

	CObjMessage* window = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	book_isplayerhit = window->Getwindow_flag();

	if (Message_flag == false)
	{
		if (book_isplayerhit == true)
		{
			if (Input::GetVKey('Q') == true)
			{
				Message_flag = true;
				obj->SetVX(0.0f);
				obj->SetVY(0.0f);
			}

		}
	}


	if (Message_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Message_flag = false;

		}
	}














}

//ドロー
void CObjMessage2::Draw()
{
	if (Message_flag == true)
	{
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 64.0f * 6;
		src.m_left = 64.0f * 0;
		src.m_right = 64.0f * 8;
		src.m_bottom = 64.0f * 8;

		//背景の位置を設定し描画
		dst.m_top = WINDOW_SIZE_H * 0.7;
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Draw::Draw(2, &src, &dst, c, 0.0f);

		Font::StrDraw(L"この不気味な洋館に迷い込んで数日が経った。", 150, 550, 25, c);
		Font::StrDraw(L"もしかすると私以外に迷い込んだ人間がいるかもしれない。", 150, 575, 25, c);
		Font::StrDraw(L"何か分かったことがあればこのメモに記そうと思う。", 150, 600, 25, c);
		Font::StrDraw(L"著者：田幡", 750, 675, 20, c);
	}
}