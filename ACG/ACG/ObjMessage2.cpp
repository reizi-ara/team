
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
#include "GameL/Audio.h"

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
	Audio::Start(10);//本開きSE

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
	time = 0;
}

//アクション
void CObjMessage2::Action()
{
	if (time < 30)
		time++;
	if (Input::GetVKey(VK_RETURN)&& time >= 30 ||
		Input::GetVKey('W')||
		Input::GetVKey('A')||
		Input::GetVKey('D'))
	{
			CObjMessage* objM = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

			objM->Toarrivewindow(0);

			Audio::Start(11);//本閉じSE
			
			this->SetStatus(false);
			
	}
}

//ドロー
void CObjMessage2::Draw()
{
	
		float c[4] = { 0.7f,0.7f,0.7f,1.0f };

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

		if (type == 1) {
			Font::StrDraw(L"この不気味な洋館に迷い込んで数日が経った。", 150, 550, 25, c);
			Font::StrDraw(L"もしかすると私以外に迷い込んだ人間がいるかもしれない。", 150, 575, 25, c);
			Font::StrDraw(L"何か分かったことがあればこのメモに記そうと思う。", 150, 600, 25, c);
			Font::StrDraw(L"著者：田幡", 750, 675, 20, c);
		}
		else if (type == 2) {
			Font::StrDraw(L"aaaaaaaaaaaaaaaaaaaaaaaaa", 150, 550, 25, c);
			Font::StrDraw(L"もしかすると私以外に迷い込んだ人間がいるかもしれない。", 150, 575, 25, c);
			Font::StrDraw(L"何か分かったことがあればこのメモに記そうと思う。", 150, 600, 25, c);
			Font::StrDraw(L"著者：田幡", 750, 675, 20, c);
		}
	
}