#include "GameL\DrawTexTure.h"
#include "GameHead.h"
#include"ObjEffect.h"

#include "MacroManagement.h"
using namespace GameL;

CObjEffect::CObjEffect(float x, float y, float t)
{
	m_px = x;	//位置
	m_py = y;
	type = t;
}

//イニシャライズ
void CObjEffect::Init()
{
	time = TIME_INI;
}

//アクション
void CObjEffect::Action()
{
	time++;
	if (time > 8)
		this->SetStatus(0);
}

//ドロー
void CObjEffect::Draw()
{
	int AniData[8] =
	{
		0,0,1,1,2,2,3,3
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f + 128.0 * (type +1);
	src.m_left = 0.0f + AniData[time] * 128;
	src.m_right = src.m_left+128;
	src.m_bottom = src.m_top + 128;

	//表示位置の設定
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}