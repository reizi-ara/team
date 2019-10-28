//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjStartBack.h"



//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStartBack::Init()
{
	m_x = 0.0f;
}

//アクション
void CObjStartBack::Action()
{
	/*
	//背景1の動作
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;

	//背景2の動作
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;
	*/
}
//ドロー
void CObjStartBack::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	/*
	//背景2の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	*/

	//1番目に登録したグラフィックをsrc'dst'cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

