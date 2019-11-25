
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMapChanger.h"

#include "GameL/UserData.h"

//使用するネームスペースdayo
using namespace GameL;

CObjMapChanger::CObjMapChanger(float x, float y,float t)
{
	m_px = x;	//位置
	m_py = y;

	type = t;
}

//イニシャライズ
void CObjMapChanger::Init()
{
	//blockとの衝突確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	float p_x = 0;
	float p_y = 0;

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;

	m_OneChg = false;
	m_change = 1;

	mmmm = false;
}

//アクション
void CObjMapChanger::Action()
{

	//当たり判定
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;

	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;
	
	if (pl_x - sl <= en_x + hit_length &&
	pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length
		&& m_OneChg == false)
	{//接触時
		isplayerhit = true;

		CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		obj->SetX(2*64);

		CObjBlock*objB = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		objB->SetScroll(0);
		

		CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
		sceneM->SetMMMMMM(m_change);

		m_OneChg = true;

		objB->SetM_CHG(mmmm);

	}
	else
	{
		isplayerhit = false;

		m_OneChg = false;
	}
	//当たり判定ここまで








}

//ドロー
void CObjMapChanger::Draw()
{
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = 0.0f + m_py-size;
	dst.m_left = 0.0f + m_px + block->GetScroll() - size;
	dst.m_right = 64.0f + m_px + block->GetScroll()+size;
	dst.m_bottom = 64.0f + m_py + size;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

/*
void MapChanger(int m, int m_map[MAP_Y][MAP_X],unique_ptr<wchar_t>* a)
{
	int size;

	int map[MAP_Y][MAP_X];

	a[m]=Save::ExternalDataOpen(L"仮マップ１.csv", &size);//外部データ読み込み

	int count = 1;
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			int w = 0;
			swscanf_s(&a[m].get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
	

}*/