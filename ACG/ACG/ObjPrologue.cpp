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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128 * 7;
	src.m_bottom = 1024 / 2;

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(8, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 64.0f * 6;
	src.m_left = 64.0f * 0;
	src.m_right = 64.0f * 8;
	src.m_bottom = 64.0f * 8;

	//背景の位置を設定し描画
	dst.m_top = WINDOW_SIZE_H * 0.7;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);
	if (Endnum == 0)
	{
		Font::StrDraw(L"白上市この街に最近不思議なことが起こった。", 150, 550, 25, c);
		Font::StrDraw(L"なぜか急に古びた洋館が建っていたのだ、", 150, 575, 25, c);
		Font::StrDraw(L"そんなことがあったもんだから街では、", 150, 600, 25, c);
		//Font::StrDraw(L"そういった噂が流れていた。", 150, 625, 25, c);
		//Font::StrDraw(L"", 150, 650, 25, c);

	
	}
	else if (Endnum == 1)
	{
		Font::StrDraw(L"「あの洋館には化け物が出る」とか", 150, 550, 25, c);
		Font::StrDraw(L"「あの洋館の中は実は異空間だ」とか", 150, 575, 25, c);
		Font::StrDraw(L"そんな噂が流れているせいで洋館に訪れる人は多かった。", 150, 650, 25, c);

	}
	else if (Endnum == 2)
	{
		//Font::StrDraw(L"", 150, 550, 25, c);
		Font::StrDraw(L"そして僕も…その中の一人だった。", 250, 600, 25, c);
		//Font::StrDraw(L"", 150, 650, 25, c);
		//Font::StrDraw(L"著者：田幡", 750, 675, 20, c);
	}
}

