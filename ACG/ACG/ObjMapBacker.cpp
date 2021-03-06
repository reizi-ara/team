
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMapBacker.h"

#include "GameL/Audio.h"
#include "GameL/UserData.h"

#include "MacroManagement.h"

//使用するネームスペースdayo
using namespace GameL;

CObjMapBacker::CObjMapBacker(float x, float y, float t)
{
	m_px = x;	//位置
	m_py = y;

	type = t;
}

//イニシャライズ
void CObjMapBacker::Init()
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
	m_change = -1;

	mmmm = false;

	//削除用
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}

}

//アクション
void CObjMapBacker::Action()
{

	//当たり判定
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block->GetScroll();
	float en_x = m_px + HIT_AREA_X;
	float en_y = m_py + HIT_AREA_Y;

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += HIT_AREA_X;
	pl_y += HIT_AREA_Y;

	

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length
		&& m_OneChg == false)
	{//接触時
		
		Audio::Start(6);//効果音

		isplayerhit = true;
		m_OneChg = true;

		//CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		obj->SetX(30 * 64);
		obj->SetY(7 * 64);
		obj->SetMAPMaxControl(1);

		//CObjBlock*objB = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		block->SetScroll(-73*64);
		block->SetM_CHG(mmmm);
		block->Set_ikkai(m_OneChg);//ブロックのマップアドレスをtrueにする部分

		CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
		sceneM->SetMMMMMM(m_change);
		sceneM->SetASDF(m_OneChg);


	}
	else
	{
		isplayerhit = false;

		m_OneChg = false;
	}
	//当たり判定ここまで




		//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}




}

//ドロー
void CObjMapBacker::Draw()
{

	//描画カラー情報
	float c[4] = { 0.6f,0.6f,0.6f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 64.0f * 4;
	src.m_left = 64.0f * 4;
	src.m_right = 64.0f * 5;
	src.m_bottom = 64.0f * 6;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = -64.0f * 1 + m_py - size;
	dst.m_left = 0.0f + m_px + block->GetScroll() - size;
	dst.m_right = 64.0f + m_px + block->GetScroll() + size;
	dst.m_bottom = 64.0f + m_py + size;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);
}