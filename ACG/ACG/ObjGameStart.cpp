//使用するヘッダーファイル

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"
#include"main.h"
#include"GameL/Audio.h"
#include"MacroManagement.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameStart::Init()
{
	m_key_flag = false;
	lavel_select = LAVEL_TOP;
	lavel_button = true;
	lavel_button2 = true;
}

//アクション
void CObjGameStart::Action()
{
	if (Input::GetVKey('S'))
	{
		if (lavel_button == true)
		{
			Audio::Start(1);//効果音

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
			Audio::Start(1);//効果音

			lavel_select--;

			lavel_button2 = false;

		}
	}
	else
		lavel_button2 = true;


	if (lavel_select > LAVEL_BOT_T)
		lavel_select = LAVEL_TOP;
	if (lavel_select < LAVEL_TOP)
		lavel_select = LAVEL_BOT_T;


	//エンターキーを押してシーン：ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Audio::Start(2);//効果音
		if (m_key_flag == true)
		{
			if (lavel_select == LAVEL_TOP)
			{
				m_key_flag = false;
				Scene::SetScene(new CScenePrologue());

			}

			/*else if (lavel_select == 1)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneGameOption());

			}*/
			else if (lavel_select == LAVEL_BOT_T)
			{
				Scene::SetScene(nullptr);
			}
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameStart::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 1.0f,1.0f,1.0f,0.5f };


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景
	//切り取り位置の設定
	src.m_top	= START_CUT_TOP;
	src.m_left	= START_CUT_LEFT;
	src.m_right = START_CUT_RIGHT;
	src.m_bottom= START_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top	= 0.0f;
	dst.m_left	= 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom= WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);




	//スタートボタン
	//切り取り位置の設定
	src.m_top	= START_BUTTON_CUT_TOP;
	src.m_left	= START_BUTTON_CUT_LEFT  * START_BUTTON_LEFT_EXP;
	src.m_right = START_BUTTON_CUT_RIGHT * START_BUTTON_RIGHT_EXP;
	src.m_bottom= START_BUTTON_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top	= WINDOW_SIZE_H / 2	+ START_POS_TOP;
	dst.m_left	= WINDOW_SIZE_W / 2 - START_POS_LEFT;
	dst.m_right = WINDOW_SIZE_W / 2 + START_POS_RIGHT;
	dst.m_bottom= WINDOW_SIZE_H / 2 + START_POS_BOTTOM;
	if (lavel_select == LAVEL_TOP)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);


	/*
	//オプションボタン
	//切り取り位置の設定
	src.m_top = 64.0f * 3;
	src.m_left = 0.0f;
	src.m_right = 64.0f * 4;
	src.m_bottom = 64.0f * 4;

	//背景の位置を設定し描画
	dst.m_top = WINDOW_SIZE_H / 2 + 80;
	dst.m_left = WINDOW_SIZE_W / 2 - 150;
	dst.m_right = WINDOW_SIZE_W / 2 + 150;
	dst.m_bottom = WINDOW_SIZE_H / 2 + 160;
	if (lavel_select == 1)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);
	*/

	//ゲーム終了ボタン
	//切り取り位置の設定
	src.m_top	= END_BUTTON_CUT_TOP;
	src.m_left	= END_BUTTON_CUT_LEFT;
	src.m_right = END_BUTTON_CUT_RIGHT * END_BUTTOM_RIGHT_EXP;
	src.m_bottom= END_BUTTON_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top	= WINDOW_SIZE_H / 2 + END_POS_TOP;
	dst.m_left	= WINDOW_SIZE_W / 2 - END_POS_LEFT;
	dst.m_right = WINDOW_SIZE_W / 2 + END_POS_RIGHT;
	dst.m_bottom= WINDOW_SIZE_H / 2 + END_POS_BOTTOM;
	if (lavel_select == LAVEL_BOT_T)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);


}