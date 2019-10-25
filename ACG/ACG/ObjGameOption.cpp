//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"main.h"
#include"ObjGameStart.h"

#define SERECT_MIN_OP (0)
#define SERECT_MAX_OP (0)

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOption::Init()
{
	m_key_flag = true;
	lavel_option = true;
	lavel_option2 = true;
	lavel_select_op = SERECT_MIN_OP;
}

//アクション
void CObjGameOption::Action()
{
	if (Input::GetVKey('S'))
	{
		if (lavel_option == true)
		{
			lavel_select_op++;

			lavel_option = false;

		}
	}
	else
		lavel_option = true;

	if (Input::GetVKey('W'))
	{
		if (lavel_option2 == true)
		{
			lavel_select_op--;

			lavel_option2 = false;

		}
	}
	else
		lavel_option2 = true;


	if (lavel_select_op > SERECT_MAX_OP)
		lavel_select_op = SERECT_MIN_OP;
	if (lavel_select_op < SERECT_MIN_OP)
		lavel_select_op = SERECT_MAX_OP;


	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (lavel_select_op == 0)
		{
			Scene::SetScene(new CSceneGameStart());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOption::Draw()
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
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//強調表示用バー
	//切り取り位置の設定
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//バーの位置を設定し描画
	dst.m_top = 340.0f + lavel_select_op * 50;
	dst.m_left = 300.0f;
	dst.m_right = 520.0f;
	dst.m_bottom = 380.0f + lavel_select_op * 50;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	Font::StrDraw(L"戻る", 380, 340, 32, c);
	Font::StrDraw(L"まだ作ってません。", 280, 390, 32, c);
	Font::StrDraw(L"ごめんなさい", 320, 440, 32, c);
}