
//使用するヘッダー
#include "GameL/DrawFont.h"
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjCandle.h"
#include "main.h"
#include "GameL/Audio.h"
#include "MacroManagement.h"

#define LIFE 80;
//使用するネームスペースdayo
using namespace GameL;

CObjCandle::CObjCandle(float x, float y)
{
	m_px = x;	//位置
	m_py = y;

}

//イニシャライズ
void CObjCandle::Init()
{
	hit_length = 64.0f;
	size = 0;

	isplayerhit = false;
	menu_flag = false;
	p_menuflag = false;

	p_menu_close = false;

	lavel_select = LAVEL_TOP;

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
	time = TIME_INI;

	Unfold = 0;
	stopD = true;
}

//アクション
void CObjCandle::Action()
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

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//接触時
		isplayerhit = true;
			obj->PlayerHeal();
		
		if (Input::GetVKey(VK_RETURN) == true && menu_flag == false)
		{
			menu_flag = true;
			obj->SetMF(menu_flag);	//主人公の動き制限用のフラグ送り			

			Audio::Stop(0);//メインBGMストップ
			Audio::Start(2);//メニューBGMスタート
			stopD = false;
			
		}
		

	}
	else
	{
		isplayerhit = false;

	}


	if (menu_flag == true)	//メニューテスト
	{
		

		if (Input::GetVKey('S'))
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

				Audio::Start(9);//SE

			}
		}
		else
			lavel_button = true;

		if (Input::GetVKey('W'))
		{
			if (lavel_button2 == true)
			{
				lavel_select--;

				lavel_button2 = false;

				Audio::Start(9);//SE

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > LAVEL_BOT_MENU)
			lavel_select = LAVEL_TOP;
		if (lavel_select < LAVEL_TOP)
			lavel_select = LAVEL_BOT_MENU;


		//エンターキーを押してシーン：ゲームメインに移行する
		if (menu_flag)
		{
			time++;
			if (time >= TIME_DELAY)
			{
				if (Input::GetVKey(VK_RETURN))
				{
					p_menu_close = true;
				}
				else if(p_menu_close)
				{
					if (lavel_select == LAVEL_TOP) {
						p_menu_close = false;
						Audio::Start(8);//SE
					}
					else if (lavel_select == LAVEL_MID_MENU) {
						p_menu_close = false;
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameStart());
					}
					else if (lavel_select == LAVEL_BOT_MENU) {
						p_menu_close = false;
						time = 0;
						Audio::Start(8);//SE
						Audio::Stop(2);//メニューBGMストップ
						Audio::Start(0);//メインBGMスタート
						stopD = true;


						lavel_select = LAVEL_TOP;

						menu_flag = false;
						obj->SetMF(menu_flag);	//主人公の動き制限用のフラグ送り
						

					}
				}
				


			}

		}
		obj->SetVX(0);
		obj->SetVY(0);

	}
	else
	{

	}

	//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum){
		this->SetStatus(false);
	}




}

//ドロー
void CObjCandle::Draw()
{

	float c[4] = { 0.8f,0.8f,0.8f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	if (menu_flag == false)
	{
		//切り取り位置の設定
		src.m_top	= CANDLE_CUT_TOP;
		src.m_left	= CANDLE_CUT_LEFT;
		src.m_right = CANDLE_CUT_RIGHT;
		src.m_bottom= CANDLE_CUT_BOTTOM;
		//x上海紅茶館->o大英紅茶館
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top	= CANDLE_PUT_TOP	+ m_py - size;
		dst.m_left	= CANDLE_PUT_LEFT	+ m_px + block->GetScroll() - size;
		dst.m_right = CANDLE_PUT_RIGHT	+ m_px + block->GetScroll() + size;
		dst.m_bottom= CANDLE_PUT_BOTTOM + m_py + size;

		//描画
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (menu_flag)
	{
		//切り取り位置の設定
		src.m_top	= MENU_BACK_CUT_TOP;
		src.m_left	= MENU_BACK_CUT_LEFT;
		src.m_right = MENU_BACK_CUT_RIGHT;
		src.m_bottom= MENU_BACK_CUT_BOTTOM;

		//背景の位置を設定し描画
		dst.m_top	= MENU_BACK_PUT_TOP;
		dst.m_left	= MENU_BACK_PUT_LEFT;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom= WINDOW_SIZE_H;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//強調表示用バー
		//切り取り位置の設定
		/*src.m_top	= 64.0f * 5;
		src.m_left	= 64.0f * 5;
		src.m_right = 64.0f * 5 + 192;
		src.m_bottom= 64.0f * 5 + 64;

		//バーの位置を設定し描画
		dst.m_top	= MENU_BAR_PUT_TOP + lavel_select * 188;
		dst.m_left	= MENU_BAR_PUT_LEFT;
		dst.m_right = MENU_BAR_PUT_RIGHT;
		dst.m_bottom= MENU_BAR_PUT_BOTTOM + lavel_select * 50;
		Draw::Draw(2, &src, &dst, c, 0.0f); */

		//メニューバー
		Font::StrDraw(L"←", MENU_BAR_W, MENU_BAR_H + lavel_select * MENU_BAR_MOVE,MENU_BAR_SIZE,c);


		Font::StrDraw(L"クレジット", MENU_LAVEL_W, MENU_LAVEL_CREDIT_H, MENU_LAVEL_SIZE, c);
		Font::StrDraw(L"タイトルへ", MENU_LAVEL_W, MENU_LAVEL_ESC_H, MENU_LAVEL_SIZE, c);
		Font::StrDraw(L"戻る",		 MENU_LAVEL_W, MENU_LAVEL_BACK_H, MENU_LAVEL_SIZE, c);
		//Font::StrDraw(L"", 50, 250, 32, c);
	

		if (lavel_select == LAVEL_TOP) {
			Font::StrDraw(L"クレジット一覧",				MENU_CREDIT_CON_HEAD_W, MENU_CREDIT_CON_HEAD_H, MENU_CREDIT_CON_HEAD_SIZE, c);
			Font::StrDraw(L"制作者",						MENU_CREDIT_CON_W, MENU_CREATOR_H, MENU_CON_GENRE_SIZE, c);
			Font::StrDraw(L"総合ディレクター:永原 大暉",	MENU_CREDIT_CON_W, MENU_MEMBER1_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"ゲームプランナー:畠 将仁",		MENU_CREDIT_CON_W, MENU_MEMBER2_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"ゲームプログラマー:荒巻 佑真",	MENU_CREDIT_CON_W, MENU_MEMBER3_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"ゲームデザイナー:田幡 俊幸",	MENU_CREDIT_CON_W, MENU_MEMBER4_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"アシスタント:岡田 悠樹",		MENU_CREDIT_CON_W, MENU_MEMBER5_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"BGM・効果音",					MENU_CREDIT_CON_W, MENU_OFFER_H, MENU_CON_GENRE_SIZE, c);
			Font::StrDraw(L"効果音ラボ→https://soundeffect-lab.info/",				MENU_CREDIT_CON_W, MENU_URL1_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"Wingless Seraph→https://wingless-seraph.net/",			MENU_CREDIT_CON_W, MENU_URL2_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"無料効果音→https://taira-komori.jpn.org/index.html",	MENU_CREDIT_CON_W, MENU_URL3_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"魔王魂→https://maoudamashii.jokersounds.com/",			MENU_CREDIT_CON_W, MENU_URL4_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"効果音辞典→https://sounddictionary.info/",				MENU_CREDIT_CON_W, MENU_URL5_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"G-Sound→https://g-miya.net/index.html",				MENU_CREDIT_CON_W, MENU_URL6_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"くらげ工匠→http://www.kurage-kosho.info/index.html",	MENU_CREDIT_CON_W, MENU_URL7_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"ノスタルジア→http://nostalgiamusic.info/index.html",	MENU_CREDIT_CON_W, MENU_URL8_H, MENU_CREDIT_CON_SIZE, c);
		}
		if (lavel_select == LAVEL_MID_MENU) {
			Font::StrDraw(L"ゲームを終了してタイトルに戻ります。",	MENU_CON_TXT_W, MENU_CON_TXT_H, MENU_CON_TXT_SIZE, c);
		}
		if (lavel_select == LAVEL_BOT_MENU) {
			Font::StrDraw(L"ゲーム画面へ戻ります。",				MENU_CON_TXT_W, MENU_CON_TXT_H, MENU_CON_TXT_SIZE, c);
		}
	}

}