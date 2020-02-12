//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"
#include"main.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	m_key_flag = false;
	ReturnKey_flag = false;
	time=0;
	Endnum = 0;
	one_flag = true;
}
//アクション
void CObjGameClear::Action()
{
	time++;
	//エンターキーを押してシーン：ゲームタイトルに移行する
	if (Endnum >= 4)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneGameStart());

			}
		}

		else
		{
			m_key_flag = true;
		}
	}

	//メッセージ関連
	if (Input::GetVKey(VK_RETURN) == true&&time>=30)
	{
		one_flag = false;
		//ReturnKey_flag = true;
		Endnum += 1;		
		time = 0;
		Audio::Start(2);//効果音
	}
}

//ドロー
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128*7;
	src.m_bottom = 1024/2;

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(8, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top	= MESSAGE_CUT_TOP;
	src.m_left	= MESSAGE_CUT_LEFT;
	src.m_right = MESSAGE_CUT_RIGHT;
	src.m_bottom= MESSAGE_CUT_BOTTOM;

	//背景の位置を設定し描画
	dst.m_top = WINDOW_SIZE_H * 0.7;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);
	if (Endnum == 0)
	{
		Font::StrDraw(L"「ここは...外？」",					MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"「何とか外に出られたようだ。」",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"「館や化け物は何だったんだろう」",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 1)
	{
		Font::StrDraw(L"後日その館を調べるために向かったところ", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"その館は跡形もなかった",				 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"街の噂も嘘のように聞こえてこず",		 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"みんなも噂のことを忘れていた",			 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE4_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 2)
	{
		Font::StrDraw(L"ただ、あの館がなくなった気がしなかった",	 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"まだどこかにあるような気がして心配だったが", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"そのうち忘れていった",						 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 3)
	{
		Font::StrDraw(L"～END～", (WINDOW_SIZE_W/2)-50, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 4)
	{
		Font::StrDraw(L"ねえ、ある館の噂って知ってる？...", 400, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
}

