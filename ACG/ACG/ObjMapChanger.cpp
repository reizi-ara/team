
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMapChanger.h"

#include "GameL/Audio.h"
#include "GameL/UserData.h"

#include "MacroManagement.h"

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

	CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();
	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//接触時
		if (sceneM->CheckMassageActivate()) {
			time_a = 60;
			Audio::Start(6);//効果音

			isplayerhit = true;
			m_OneChg = true;

			CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
			obj->SetX(6 * 64);
			obj->SetY(7 * 64);
			obj->SetMAPMaxControl(-1);

			CObjBlock*objB = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
			objB->SetScroll(5);
			objB->SetM_CHG(mmmm);
			objB->Set_ikkai(m_OneChg);//ブロックのマップアドレスをtrueにする部分

			CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
			sceneM->SetMMMMMM(m_change);
			sceneM->SetASDF(m_OneChg);


		}





	}
	else
	{
		isplayerhit = false;

		m_OneChg = false;
	}
	//当たり判定ここまで

	if (sceneM->CheckMassageActivate() == false)
	{

	}



		//削除用処理
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}



}

//ドロー
void CObjMapChanger::Draw()
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

	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();

	if (sceneM->CheckMassageActivate() == 0)
	{
		//切り取り位置の設定
		src.m_top = 64.0f * 7;
		src.m_left = 64.0f * 1;
		src.m_right = 64.0f * 2;
		src.m_bottom = 64.0f * 8;
		//x上海紅茶館->o大英紅茶館
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top = -64.0f - 48.0f + m_py - size;
		dst.m_left = 8.0f + m_px + block->GetScroll() - size;
		dst.m_right = 32.0f + 24.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = -48.0f + m_py + size;
		//描画
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}
}


