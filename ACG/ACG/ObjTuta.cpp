//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjTuta.h"
#include "main.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"

//使用するネームスペースdayo
using namespace GameL;

CObjTuta::CObjTuta(float x, float y)
{
	m_x = x;	//位置
	m_y = y;
}

//イニシャライズ
void CObjTuta::Init()
{

	float p_x = 0;
	float p_y = 0;
}

//アクション
void CObjTuta::Action()
{
	
	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//メッセージウインドウ
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = word_x + 32.0f;
	float en_y = word_y + 32.0f;
	if (pl_x - sl <= en_x + 48.0f + 16.0f&&
		pl_x - sl >= en_x - 48.0f - 16.0f &&
		pl_y <= en_y + 48.0f&&
		pl_y >= en_y - 48.0f&&
		Input::GetVKey('E'))
	{
		window_flag = 1;
	}
   
}

//ドロー
void CObjTuta::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 78.0f;
	src.m_bottom = 193.0f;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (window_flag == 1)
	{
		//表示位置の設定
		dst.m_top = (WINDOW_SIZE_H/3);
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Font::StrDraw(L"メッセージウインドウだよ♪", (WINDOW_SIZE_H/3)*1, (WINDOW_SIZE_W/3)*2, 32, c);
	}

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
