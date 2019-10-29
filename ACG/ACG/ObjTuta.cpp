
//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjTuta.h"

#define LIFE 80;
//使用するネームスペースdayo
using namespace GameL;

CObjTuta::CObjTuta(float x, float y)
{
	m_px = x;	//位置
	m_py = y;
}

//イニシャライズ
void CObjTuta::Init()
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
	//当たり判定用のHitBoxを作成
	//Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);

	float p_x = 0;
	float p_y = 0;
}

//アクション
void CObjTuta::Action()
{

	//通常速度
	m_ani_max_time = 4;//アニメーション間隔幅



	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	/*	//HitBoxの位置の変更
		CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(m_px + block->GetScroll(), m_py);*/

		//対プレイヤー攻撃
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;
	//与ダメージ
	if (pl_x - sl <= en_x + 48.0f &&
		pl_x - sl >= en_x - 48.0f &&
		pl_y <= en_y + 48.0f &&
		pl_y >= en_y - 48.0f)
	{
		obj->GiveDamageToPlayer(0.1f);
	}

}

//ドロー
void CObjTuta::Draw()
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
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = 64.0f + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}