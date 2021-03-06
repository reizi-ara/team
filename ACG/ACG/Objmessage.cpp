
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objmessage.h"
#include "main.h"
#include "MacroManagement.h"


#define LIFE 80;
//使用するネームスペースdayo
using namespace GameL;

CObjMessage::CObjMessage(float x, float y, float t)
{
	m_px = x;	//位置
	m_py = y;

	type = t;
}

//イニシャライズ
void CObjMessage::Init()
{
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0ｆ　左向き1.0ｆ

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.0f;	//通常速度
	m_ani_max_time = 4;		//アニメーション間隔幅

	m_move = true;

	//blockとの衝突確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	en_life = LIFE;

	float p_x = 0;
	float p_y = 0;

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;
	Message_flag =0;

	//エネミーストップ変数
	stopE = true;

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
	time = TIME_INI;

	Unfold = 0;
}

//アクション
void CObjMessage::Action()
{

	//当たり判定
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += HIT_AREA_X;
	pl_y += HIT_AREA_Y;

	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + HIT_AREA_X;
	float en_y = m_py + HIT_AREA_Y;

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//接触時
		isplayerhit = true;
		obj->SetMessageflag(isplayerhit);
	}
	else 
	{
		isplayerhit = false;
		obj->SetMessageflag(isplayerhit);

	}

	CObjMessage2* obje = new CObjMessage2(64.0f, 64.0f,type);
	CObjMessage2* objM = (CObjMessage2*)Objs::GetObj(OBJ_MESSAGE2);
	
	
	if (Unfold==0&&time < TIME_DELAY)
	{
		time++;
	}
	if (time >= TIME_DELAY)
	{
		Message_flag = 0;
		Unfold = 1;
		time = 0;
	}
	if (isplayerhit && Message_flag == 0)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
			sceneM->MassageActivate();
			Objs::InsertObj(obje, OBJ_MESSAGE2, 15);

			obj->SetVX(0.0f);
			obj->SetVY(0.0f);
			Message_flag = 1;

			stopE = false;
		}
	}




	//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}




}

//ドロー
void CObjMessage::Draw()
{

	//描画カラー情報
	float c[4] = { 0.5f,0.5f,0.5f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 64.0f*4;
	src.m_left = 64.0f*2;
	src.m_right = 64.0f*4;
	src.m_bottom = 64.0f*6;
	//x上海紅茶館->o大英紅茶館
	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = -64.0f + m_py - size;
	dst.m_left = 0.0f-16.0f + m_px + block->GetScroll() - size;
	dst.m_right = 64.0f+16.0f + m_px + block->GetScroll() + size;
	dst.m_bottom = 64.0f + m_py + size;

	//描画
	Draw::Draw(2, &src, &dst, c, 0.0f);

	CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM->CheckMassageActivate()==0)
	{
		//切り取り位置の設定
		src.m_top = 64.0f * 7;
		src.m_left = 64.0f * 0;
		src.m_right = 64.0f * 1;
		src.m_bottom = 64.0f * 8;
		//x上海紅茶館->o大英紅茶館
		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top = -64.0f-48.0f + m_py - size;
		dst.m_left = 8.0f + m_px + block->GetScroll() - size;
		dst.m_right = 32.0f+24.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = -48.0f + m_py + size;
		//描画
		Draw::Draw(6, &src, &dst, c, 0.0f);
	}

}