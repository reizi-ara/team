//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjTuta.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTuta::Init()
{

}

//アクション
void CObjTuta::Action()
{

}

//ドロー
void CObjTuta::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;//ネタ：1600
	src.m_bottom = 512.0f;//900

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);
}