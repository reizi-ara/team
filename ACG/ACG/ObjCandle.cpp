
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
	m_ani_max_time = 4;		//アニメーション間隔幅

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;
	menu_flag = false;

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
}

//アクション
void CObjCandle::Action()
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

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//接触時
		isplayerhit = true;

		if (Input::GetVKey('E'))
		{
			p_menuflag = true;

			obj->SetVX(0.0f);
			obj->SetVY(0.0f);
		}


	}
	else
	{
		isplayerhit = false;

	}

	if (isplayerhit && menu_flag == false)
	{
		if (Input::GetVKey(VK_RETURN) == true&&oneET_flag==true)
		{
			menu_flag = true;
			obj->SetMF(menu_flag);	//主人公の動き制限用のフラグ送り
			oneET_flag = false;

			Audio::Stop(0);//メインBGMストップ
			Audio::Start(2);//メニューBGMスタート
		}
		else
		{
			oneET_flag = true;
		}
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


		if (lavel_select > 5)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 5;


		//エンターキーを押してシーン：ゲームメインに移行する
		if (Input::GetVKey(VK_RETURN) == true && menu_flag )
		{
			if (oneET_flag)
			{
				if (lavel_select == 0)
				{
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;

				}

				else if (lavel_select == 1)
				{
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 2) {
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 3) {
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 4)
				{
					Audio::Start(8);//SE
					Scene::SetScene(nullptr);
					oneET_flag = false;
				}

				else if (lavel_select == 5)
				{
					Audio::Start(8);//SE
					Audio::Stop(2);//メニューBGMストップ
					Audio::Start(0);//メインBGMスタート
					menu_flag = false;
					oneET_flag = false;

					lavel_select = 0;

					obj->SetMF(menu_flag);	//主人公の動き制限用のフラグ送り

					

				}
			}

		}
		else
		{
			m_key_flag = true;
			oneET_flag = true;

		}

		obj->SetVX(0);
		obj->SetVY(0);
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
void CObjCandle::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

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
		Draw::Draw(2, &src, &dst, c, 0.0f);


		Font::StrDraw(L"アイテム", 50, 100, 32, c);
		Font::StrDraw(L"装備", 50, 150, 32, c);
		Font::StrDraw(L"キャラクター", 50, 200, 32, c);
		Font::StrDraw(L"セーブ", 50, 250, 32, c);
		Font::StrDraw(L"ゲーム終了", 50, 300, 32, c);
		Font::StrDraw(L"戻る", 50, 350, 32, c);
	
	}
}