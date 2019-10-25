//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjMenu.h"

//使用するネームスペース
using namespace GameL;

#define PLAYERLIFE 100

//イニシャライズ
void CObjHero::Init()
{
	m_px = 70.0f;	//位置
	m_py = 64.0f;
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; 
	m_pose = 1.0f;
	/*
	0:待機 1:移動 2:しゃがみ 3:ジャンプ 4:攻撃 5:アイテム
	*/

	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	m_speed_power = 0.5f;	//通常速度
	m_ani_max_time = 8;		//アニメーション間隔幅

	//blockとの衝突確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	flg_j = false;
	m_block_type = 0;
	p_maxlife=PLAYERLIFE;
	p_life = p_maxlife;

	//メニュー展開時の操作フラグ
	p_menuflag = false;

	//当たり判定用のHitBoxを作成
	//Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	if (Input::GetVKey('E'))
	{
		p_menuflag = true;
	}

	

	if (p_menuflag == false)
	{


		//Ct+Rシーンリセット
		if (Input::GetVKey('R') && Input::GetVKey(VK_CONTROL))
		{
			//場外に出たらリスタート
			Scene::SetScene(new CSceneMain());
		}
		if (Input::GetVKey('T') && Input::GetVKey(VK_CONTROL))
		{//ダメージ付与
			GiveDamageToPlayer(6.0f);

		}

		//HP0以下でゲームオーバへ移行
		if (p_life <= 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}

		//Wでジャンプ
		if (Input::GetVKey('W'))
			if (m_hit_down)
				m_vy = -20;

		//攻撃時オブジェクト生成
		//if (Input::GetVKey('1'))



		if (Input::GetVKey(VK_SHIFT))
		{//Shiftで速度アップ
			m_speed_power = 1.1f;
			m_ani_max_time = 2;
		}
		else
		{//通常速度
			m_speed_power = 0.5f;
			m_ani_max_time = 4;
		}

		//キーの入力方向
		if (Input::GetVKey('S'))//しゃがみ
			m_pose = 2.0f;
		else
		{
			if (Input::GetVKey('D'))
			{
				m_vx += m_speed_power;
				m_posture = 1.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else if (Input::GetVKey('A'))
			{
				m_vx -= m_speed_power;
				m_posture = 0.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else
			{
				//m_ani_frame = 1;//キー入力がない場合は静止フレームにする
				m_ani_time += 1;
				m_pose = 0.0f;
			}
		}

		
		



		//HP
		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 8)
			m_ani_frame = 0;

		m_vx += -(m_vx*0.098);//摩擦
		m_vy += 9.8 / (16.0f);//自由落下運動

		//高速移動用によるBlock判定
		bool b;
		float pxx, pyy, r;
		CObjBlock*pbb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		if (pbb->GetScroll() > 0)
			pbb->SetScroll(0);

		//移動方向にレイを飛ばす
		float vx;
		if (m_vx > 0)
			vx = 500;
		else
			vx = -500;

		//レイ判定
		b = pbb->HeroBlockCrossPoint(m_px - pbb->GetScroll() + 32, m_py + 32, vx, 0.0f, &pxx, &pyy, &r);

		if (b == true)
		{
			//交点取得
			px = pxx + pbb->GetScroll();
			py = pyy;

			float aa = (m_px)-px;//A(交点→主人公の位置)ベクトル
			float bb = (m_px + m_vx) - px;//B(交点→主人公の移動先位置)ベクトル

										  //主人公の幅分のオフセット
			if (vx > 0)
				px += -64;
			else
				px += +2;

			//AとBが逆を向いてる(主人公が移動先が壁を越えている)
			if (aa*bb < 0)
			{
				//移動ベクトルを(交点→主人公の位置)ベクトルにする
				m_vx = px - m_px;
			}

		}
		else
		{
			px = 0.0f;
			py = 0.0f;
		}

		//ブロックとの当たり判定実行
		CObjBlock*pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pd->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

		/*	//自身のHitBoxを持ってくる
			CHitBox*hit = Hits::GetHitBox(this);
			//敵と当たっているか確認
			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{
				//主人公が敵とどの角度で当たっているかを確認
				HIT_DATA**hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ENEMY);

				for (int i = 0; i < hit->GetCount(); i++)
				{
					//敵との左右に当たったら
					float r = hit_data[i]->r;
					if ((r < 45 && r >= 0) || r > 315)
					{
						m_vx = -5.0f;
						p_life -= 10;
					}
					if (r > 135 && r < 225)
					{
						m_vx = +5.0f;
					}
					if (r >= 225 && r < 315)
					{
						//敵の移動方向を主人公の位置に加算
						m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

						CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
						//頭にのせる処理
						if (m_vy <- 1.0f)
						{
							//ジャンプしている場合は下記の影響を出ないようにする
						}
						else
						{
							//主人公が敵の頭に乗っているので、Yvecは0にして落下させない
							//また、地面に当たっている判定にする
							m_vy = 0.0f;
							m_hit_down = true;
						}
					}
				}
			}*/


			//表示位置の更新
		m_px += m_vx;
		m_py += m_vy;

		/*	//HitBoxの位置変更
			hit->SetPos(m_px, m_py);*/

	}
	else if (p_menuflag == true)
	{

	}
}

//ドロー
void CObjHero::Draw()
{
	int AniData[8] =
	{
		0,1,2,3,0,4,5,6
	}; 
	int AniData2[8] =
	{
		0,1,2,3,4,5,6,7
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	 //切り取り位置の設定
	src.m_top = 0.0f+m_pose * 64;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + src.m_left;
	src.m_bottom = 64.0f + src.m_top;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);




	//体力バー(枠)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f + src.m_left;
	src.m_bottom = 64.0f + src.m_top;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 16.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);


	//体力バー
	if (p_life / p_maxlife > 0.5)
	{
		src.m_top = 0.0f;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}
	else if (p_life / p_maxlife <= 0.5&& p_life / p_maxlife > 0.25)
	{
		src.m_top = 64.0f;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}
	else if (p_life / p_maxlife <= 0.25)
	{
		src.m_top = 64.0f*2;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f*(p_life/p_maxlife);
	dst.m_bottom = 16.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
	wepon_have = 6;//仮置き

	if (p_menuflag==false)
	{
		//アクション
		if (Input::GetVKey(VK_RETURN) && wepon_have > 0 && wepon_have != 4)
		{
			//切り取り位置の設定
			src.m_top = 0.0f + (wepon_have % 4 + 4) * 64;
			src.m_left = 0.0f + AniData2[m_ani_frame] * 64;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;

			//表示位置の設定
			dst.m_top = 0.0f + m_py;
			dst.m_left = (64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
			dst.m_right = (64 - 64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
			dst.m_bottom = 64.0f + m_py;

			//描画
			Draw::Draw(1, &src, &dst, c, 0.0f);
			wepon_attack = wepon_have;
		}
		else
		{
			wepon_attack = 0;
		}
	}
}