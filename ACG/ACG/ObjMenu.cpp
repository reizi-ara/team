#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjMenu.h"
#include"ObjHero.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//アクション
void CObjMenu::Action()
{
	if (p_menuflag == true) {

		if (Input::GetVKey('S'))
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

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

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > 5)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 5;


		//エンターキーを押してシーン：ゲームメインに移行する
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (lavel_select == 0)
			{
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 1)
			{
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 2) {
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 3) {
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 4)
			{
				Scene::SetScene(nullptr);
			}

			else if (lavel_select == 5)
			{
				p_menuflag = false;
			}

		}
		else
		{
			m_key_flag = true;
		}
	}
}

//ドロー
void CObjMenu::Draw()
{
	if (p_menuflag == true)				//メニュー
	{
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 960.0f;
		src.m_bottom = 450.0f;

		//背景の位置を設定し描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		//強調表示用バー
		//切り取り位置の設定
		src.m_top = 256.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		//バーの位置を設定し描画
		dst.m_top = 100.0f + lavel_select * 50;
		dst.m_left = 250.0f;
		dst.m_right = 30.0f;
		dst.m_bottom = 140.0f + lavel_select * 50;
		Draw::Draw(0, &src, &dst, c, 0.0f);


		Font::StrDraw(L"アイテム", 50, 100, 32, c);
		Font::StrDraw(L"装備", 50, 150, 32, c);
		Font::StrDraw(L"キャラクター", 50, 200, 32, c);
		Font::StrDraw(L"セーブ", 50, 250, 32, c);
		Font::StrDraw(L"ゲーム終了", 50, 300, 32, c);
		Font::StrDraw(L"戻る", 50, 350, 32, c);
	}
}

