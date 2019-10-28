/*
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjMenu.h"
#include"ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMessageBox::Init()
{
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//アクション
void CObjMessageBox::Action()
{
	 {

		if (Input::GetVKey(VK_RETURN)==true)
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

			}
		}

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > 4)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 4;

}
		

//ドロー
void CObjMessageBox::Draw()
{
	if (p_menuflag == true)
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
		Draw::Draw(2, &src, &dst, c, 0.0f);

		//強調表示用バー
		//切り取り位置の設定
		src.m_top = 256.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		


		Font::StrDraw(L"アイテム", 340, 340, 32, c);
		Font::StrDraw(L"装備", 320, 390, 32, c);
		Font::StrDraw(L"キャラクター", 365, 440, 32, c);
		Font::StrDraw(L"セーブ", 50, 490, 32, c);
		Font::StrDraw(L"ゲーム終了", 50, 540, 32, c);
	}
}


*/