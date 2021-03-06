//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"
#include"main.h"
#include "MacroManagement.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;
	time = TIME_INI;
}
//アクション
void CObjGameOver::Action()
{
	time++;
	if (time >= TIME_DELAY_GO)
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
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float cR[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top	= GAME_OVER_CUT_TOP;
	src.m_left	= 0.0f;
	src.m_right = GAME_OVER_CUT_RIGHT;
	src.m_bottom= GAME_OVER_CUT_BOTTOM;

	//背景1の位置を設定し描画
	dst.m_top	= 0.0f;
	dst.m_left	= 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom= WINDOW_SIZE_H;
	Draw::Draw(3, &src, &dst, c, 0.0f);

}

