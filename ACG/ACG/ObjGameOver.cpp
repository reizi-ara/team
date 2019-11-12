//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;
}
//アクション
void CObjGameOver::Action()
{
	//エンターキーを押してシーン：ゲームタイトルに移行する
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

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float cR[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 512.0f;
	src.m_left = 0.0f;
	src.m_right = 910.0f;
	src.m_bottom = 1024.0f;

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	Font::StrDraw(L"YOU LOSE", (WINDOW_SIZE_W/2)-130, 150, 48, cR);
	Font::StrDraw(L"GAME OVER", (WINDOW_SIZE_W / 2) - 130, 225, 48, cR);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", (WINDOW_SIZE_W / 2) - 130, 350, 48, cR);

}

