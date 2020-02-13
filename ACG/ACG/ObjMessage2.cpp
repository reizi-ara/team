
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
#include "MacroManagement.h"

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
	time = TIME_INI;
}

//アクション
void CObjMessage2::Action()
{
	if (time < TIME_DELAY)
		time++;
	if (Input::GetVKey(VK_RETURN)&& time >= TIME_DELAY ||
		Input::GetVKey('W')||
		Input::GetVKey('A')||
		Input::GetVKey('D'))
	{
			CObjMessage* objM = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

			objM->Toarrivewindow(0);
			objM->SetStopE(true);//メッセージのやつをtrueにしてエネミーが動くようにする処理


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
		src.m_top	= MESSAGE_CUT_TOP;
		src.m_left	= MESSAGE_CUT_LEFT;
		src.m_right = MESSAGE_CUT_RIGHT;
		src.m_bottom= MESSAGE_CUT_BOTTOM;

		//背景の位置を設定し描画
		dst.m_top	= WINDOW_SIZE_H * 0.7;
		dst.m_left	= 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom= WINDOW_SIZE_H;
		Draw::Draw(2, &src, &dst, c, 0.0f);

		if (type == 1) {
			Font::StrDraw(L"――この不気味な洋館に迷い込んで何日が経っただろうか？",		MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"探索で解った事はメモに記していく。後に役立てば良いのだが...",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"もしかすると私以外に迷い込んだ人間がいるかもしれない。",		MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"T・B・T", 750, 675, 20, c);
		}
		else if (type == 2) {
			Font::StrDraw(L"この洋館には得体の知れない『何か』が徘徊しているようだ。",			MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"こちらを見つけたと思えば一直線に追い掛け回してくる。",				MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"だが、抵抗はできる。何か金属製のもので叩くかすれば対処は可能だ。",  MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"それと、明るいところには寄り付かない傾向があるようだ。",			MESSAGE_SENTENCE_W, MESSAGE_SENTENCE4_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"――所々にあるロウソクの明かりでやり過ごせるだろうか...？",			MESSAGE_SENTENCE_W, MESSAGE_SENTENCE5_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"T・B・T", 950, 675, 20, c);
		}
		else if (type == 3) {
			Font::StrDraw(L"未だ脱出の糸口は見つけられない。",									  MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);//ままだが、ここでのやり方も慣れてきた
			Font::StrDraw(L"今はまだ食料や水分はある。問題は屋敷の全貌が分からないことだ。",	  MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"化け物どもが多く、探索にとても時間がかかってしまう。出口は何処だ...", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);//油断しないようにしなければ。
			Font::StrDraw(L"T・B・T", 950, 675, 20, c);
		}
		else if (type == 4) {
			Font::StrDraw(L"遂に最後の空白が埋まった！",					MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"もうそこらの化け物どもは余裕で撃退出来る、",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"脱出はすぐそこだ！",							MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"T・B・T", 950, 675, 20, c);
		}
		else if (type == 5) {
			Font::StrDraw(L"無理だ奴を倒すのは、",			MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"そこらの化け物とは違いすぎる",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"何なんだあの光は",				MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"奴さえ倒せれば...",				MESSAGE_SENTENCE_W, MESSAGE_SENTENCE4_H, MESSAGE_SENTENCE_SIZE, c);
			Font::StrDraw(L"T・V・T", 950, 675, 20, c);
		}
}