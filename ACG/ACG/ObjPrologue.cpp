//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjPrologue.h"
#include"main.h"
#include"GameL/Audio.h"

#include "MacroManagement.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPrologue::Init()
{
	m_key_flag = false;
	ReturnKey_flag = false;
	time = TIME_INI;
	Endnum = 0;
	one_flag = true;
}
//アクション
void CObjPrologue::Action()
{
	time++;
	//エンターキーを押してシーン：ゲームタイトルに移行する
	if (Endnum >= 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneMain());

			}
		}
		else
		{
			m_key_flag = true;
		}
	}

	//メッセージ関連
	if (Input::GetVKey(VK_RETURN) == true && time >= TIME_DELAY && Endnum < 3)
	{
		one_flag = false;
		Endnum += 1;
		time = TIME_INI;
		Audio::Start(2);//効果音
	}
}

//ドロー
void CObjPrologue::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top	= 0.0f;
	src.m_left	= 0.0f;
	src.m_right = GAME_CLEAR_CUT_RIGHT;
	src.m_bottom= GAME_CLEAR_CUT_BOTTOM;

	//背景1の位置を設定し描画
	dst.m_top	= 0.0f;
	dst.m_left	= 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom= WINDOW_SIZE_H;
	Draw::Draw(8, &src, &dst, c, 0.0f);

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
	if (Endnum == 0)
	{
		Font::StrDraw(L"白上市この街に最近不思議なことが起こった。", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"なぜか急に古びた洋館が建っていたのだ、",	 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"そんなことがあったもんだから街では、",		 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 1)
	{
		Font::StrDraw(L"「あの洋館には化け物が出る」とか",			 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"「あの洋館の中は実は異空間だ」とか",		 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"そんな噂が流れているせいで洋館に訪れる人は多かった。", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);

	}
	else if (Endnum == 2)
	{
		Font::StrDraw(L"そして僕も…その中の一人だった。", MESSAGE_PRO_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
}

