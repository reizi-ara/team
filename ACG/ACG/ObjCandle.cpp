
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

	lavel_select = 0;

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
	time = 0;

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


		if (lavel_select > 3)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 3;


		//エンターキーを押してシーン：ゲームメインに移行する
		if (menu_flag)
		{
			time++;
			if (time >= 30)
			{
				if (Input::GetVKey(VK_RETURN))
				{
					p_menu_close = true;
				}
				else if(p_menu_close)
				{
					if (lavel_select == 0) {
						p_menu_close = false;
						Audio::Start(8);//SE
					}
					else if (lavel_select == 1) {
						p_menu_close = false;
						Audio::Start(8);//SE
						//Scene::SetScene(new CSceneGameOver());
					}
					else if (lavel_select == 2) {
						p_menu_close = false;
						Audio::Start(8);//SE
						Scene::SetScene(nullptr);
					}
					else if (lavel_select == 3) {
						p_menu_close = false;
						time = 0;
						Audio::Start(8);//SE
						Audio::Stop(2);//メニューBGMストップ
						Audio::Start(0);//メインBGMスタート
						stopD = true;


						lavel_select = 0;

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
		src.m_top = 64.0f * 4;
		src.m_left = 64.0f * 5;
		src.m_right = 64.0f * 6;
		src.m_bottom = 64.0f * 5;
		//x上海紅茶館->o大英紅茶館
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top = -16.0f + m_py - size;
		dst.m_left = 0.0f - 16.0f + m_px + block->GetScroll() - size;
		dst.m_right = 64.0f + 16.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = 64.0f + m_py + size;

		//描画
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (menu_flag)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 910.0f;
		src.m_bottom = 512.0f;

		//背景の位置を設定し描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//強調表示用バー
		//切り取り位置の設定
		src.m_top = 64.0f * 5;
		src.m_left = 64.0f * 5;
		src.m_right = 64.0f * 5 + 192;
		src.m_bottom = 64.0f * 5 + 64;

		//バーの位置を設定し描画
		dst.m_top = 100.0f + lavel_select * 50;
		dst.m_left = 250.0f;
		dst.m_right = 30.0f;
		dst.m_bottom = 140.0f + lavel_select * 50;
		//Draw::Draw(2, &src, &dst, c, 0.0f); 
		Font::StrDraw(L"←", 220, 90 + lavel_select * 50,50,c);


		Font::StrDraw(L"クレジット", 50, 100, 32, c);
		Font::StrDraw(L"オプション", 50, 150, 32, c);
		Font::StrDraw(L"ゲーム終了", 50, 200, 32, c);
		Font::StrDraw(L"戻る", 50, 250, 32, c);
	

		if (lavel_select == 0) {
			Font::StrDraw(L"クレジット一覧", 690, 40, 32, c);
			Font::StrDraw(L"製作者", 350, 70, 20, c);
			Font::StrDraw(L"総合ディレクター:永原 大暉", 350, 100, 27, c);
			Font::StrDraw(L"ゲームプランナー:畠 将仁", 350, 135, 27, c);
			Font::StrDraw(L"ゲームプログラマー:荒巻 佑真", 350, 170, 27, c);
			Font::StrDraw(L"ゲームデザイナー:田幡 俊幸", 350, 205, 27, c);
			Font::StrDraw(L"アシスタント:岡田 悠樹", 350, 240, 27, c);
			Font::StrDraw(L"BGM・効果音", 350, 300, 20, c);
			Font::StrDraw(L"効果音ラボ→https://soundeffect-lab.info/", 350, 330, 27, c);
			Font::StrDraw(L"Wingless Seraph→https://wingless-seraph.net/", 350, 365, 27, c);
			Font::StrDraw(L"無料効果音→https://taira-komori.jpn.org/index.html", 350, 400, 27, c);
			Font::StrDraw(L"魔王魂→https://maoudamashii.jokersounds.com/", 350, 435, 27, c);
			Font::StrDraw(L"効果音辞典→https://sounddictionary.info/", 350, 470, 27, c);
			Font::StrDraw(L"G-Sound→https://g-miya.net/index.html", 350, 505, 27, c);
			Font::StrDraw(L"くらげ工匠→http://www.kurage-kosho.info/index.html", 350, 540, 27, c);
			Font::StrDraw(L"ノスタルジア→http://nostalgiamusic.info/index.html", 350, 575, 27, c);
		}
		if (lavel_select == 1) {
			Font::StrDraw(L" オプション", 690, 40, 32, c);
		}
		if (lavel_select == 2) {
			Font::StrDraw(L" ゲーム終了", 690, 40, 32, c);
			Font::StrDraw(L"ゲームを終了してタブを閉じます。", 450, 300, 45, c);
		}
	}
}