//使用するヘッダー
#include "GameL/DrawFont.h"
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "main.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

#define PLAYERLIFE 100
#define MUTEKITIME 120

//イニシャライズ
void CObjHero::Init()
{
	attack_set = false;
	attack_flag = false;
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
	//メニューバー位置
	lavel_select = 0;


	muteki_time = MUTEKITIME/2;
	overplayerlife = p_life;
	g_damage = 0;
	sohuran = 1;
	

	Message_flag = false;
}

//アクション
void CObjHero::Action()
{
	if (g_damage > 0) {
		CObjEffect* objef = new CObjEffect(m_px, m_py, 2);
		Objs::InsertObj(objef, OBJ_THORN, 15);
	}
	if (g_damage>0&&muteki_time<=0)
	{
		if (Input::GetVKey('S')) {
			p_life -= g_damage*0.333;
		}
		else {
			p_life -= g_damage;
			Audio::Start(7);//効果音
		}
		
		muteki_time = MUTEKITIME;
	}
	if(muteki_time > 0)
	{
		muteki_time--;
	}
	g_damage = 0;


	if (Input::GetVKey('E'))
	{
		p_menuflag = true;

		Audio::Stop(0);//メインBGMストップ
		Audio::Start(2);//メニューBGMスタート
	}

	

	if (p_menuflag == false)
	{


		//Rシーンリセット
		if (Input::GetVKey('R')){
			Scene::SetScene(new CSceneMain());
		}
		if (Input::GetVKey('T')){
			p_life-=2.0f;
		}
		if (Input::GetVKey('H')){
			p_life+= 2.0f;
		}



		if (p_life > p_maxlife)
			p_life = p_maxlife;
		//HP0以下でゲームオーバへ移行
		if (p_life <= 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}

		//Wでジャンプ
		if (Input::GetVKey('W'))
			if (m_hit_down)
				m_vy = -15;


		if (Input::GetVKey(VK_SHIFT))
		{//Shiftで速度アップ
			m_speed_power = 1.4f;
			m_ani_max_time = 2;
		}
		else
		{//通常速度
			m_speed_power = 0.8f;
			m_ani_max_time = 4;
		}

		//キーの入力方向
		if (Input::GetVKey('S'))//しゃがみ
		{
			p_life += 0.1;
			m_pose = 2.0f;
			m_ani_time += 1;
			if (muteki_time > 0)
				muteki_time += 0.5;
		}
		else
		{
			if (Input::GetVKey('D'))//右に移動
			{
				
				
				m_vx += m_speed_power;
				m_posture = 1.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else if (Input::GetVKey('A'))//左に移動
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
		{
			if (Input::GetVKey('A') || Input::GetVKey('D'))
			{
				Audio::Start(5);//効果音
			}
			m_ani_frame = 0;
		}



		m_vx += -(m_vx*0.2);//摩擦
		m_vy += 9.8 / (16.0f);//自由落下運動
		
		//ブロックとの当たり判定実行
		CObjBlock*pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pd->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

		


	}
	else if (p_menuflag == true)	//メニューテスト
	{
				if (Input::GetVKey('S'))
				{
					if (lavel_button == true)
					{
						lavel_select++;

						lavel_button = false;

						Audio::Start(9);//SE

					}
				}
				else
					lavel_button = true;

				if (Input::GetVKey('W'))
				{
					if (lavel_button2 == true)
					{
						lavel_select--;

						lavel_button2 = false;

						Audio::Start(9);//SE

					}
				}
				else
					lavel_button2 = true;


				if (lavel_select > 5)
					lavel_select = 0;
				if (lavel_select < 0)
					lavel_select = 5;


				//エンターキーを押してシーン：ゲームメインに移行する
				if (Input::GetVKey(VK_RETURN) == true)
				{
					if (lavel_select == 0)
					{
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameOver());	
						m_key_flag = false;
						
					}

					else if (lavel_select == 1)
					{
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameOver());
						m_key_flag = false;
					}
					
					else if (lavel_select == 2) {
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameOver());
						m_key_flag = false;
					}

					else if (lavel_select == 3) {
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameOver());
						m_key_flag = false;
					}

					else if (lavel_select == 4)
					{
						Audio::Start(8);//SE
						Scene::SetScene(nullptr);
					}

					else if (lavel_select == 5)
					{
						Audio::Start(8);//SE
						Audio::Stop(2);//メニューBGMストップ
						Audio::Start(0);//メインBGMスタート
						p_menuflag = false;
						
					}

				}
				else
				{
					m_key_flag = true;
				}
		
				m_vx = 0;
				m_vy = 0;
	}


	//表示位置の更新
	m_px += m_vx * sohuran;
	m_py += m_vy * sohuran;

	CObjMessage* obj = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	

}



//ドロー
void CObjHero::Draw()
{
	int AniData[8] =
	{
		0,1,2,4,3,2,4,5
	}; 
	int AniData3[8] =
	{
		0,2,4,6,4,5,6,7
	};
	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	if (p_menuflag == false)
	{

		if (m_pose == 2.0f)
		{
			src.m_top = 0.0f + m_pose * 64;
			src.m_left = 0.0f;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else
		{
			src.m_top = 0.0f + m_pose * 64;
			src.m_left = 0.0f + AniData[m_ani_frame] * 64;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		//切り取り位置の設定


	   //表示位置の設定
		dst.m_top = 0.0f + m_py - 16.0f;
		dst.m_left = (64.0f*m_posture) + m_px;
		dst.m_right = (64 - 64.0f*m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;

		//描画
		Draw::Draw(0, &src, &dst, c, 0.0f);




		//体力バー(枠)
		src.m_top = 128.0f;
		src.m_left = 256.0f;
		src.m_right = 256.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;

		//表示位置の設定
		dst.m_top = 8.0f;
		dst.m_left = 8.0f;
		dst.m_right = 256.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		//描画
		Draw::Draw(0, &src, &dst, c, 0.0f);


		//体力バー
		if (p_life / p_maxlife > 0.5)//ao
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 3;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else if (p_life / p_maxlife <= 0.5&& p_life / p_maxlife > 0.2)//ki
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 2;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else if (p_life / p_maxlife <= 0.2)//aka
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 1;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}

		//表示位置の設定
		dst.m_top = 24.0f;
		dst.m_left = 16.0f;
		dst.m_right = (256.0f - 16.0f)*(p_life / p_maxlife) + dst.m_left;
		dst.m_bottom = 32.0f + dst.m_top;

		//描画
		if (p_life > 0)
			Draw::Draw(0, &src, &dst, c, 0.0f);



		wepon_have = 5;//仮置き


			//アクション
		if (Message_flag == false)
		{if(Input::GetVKey('S'))
		{ }
		else {
			if (Input::GetVKey(VK_RETURN))
			{
				if (attack_set == false && attack_flag == false)
				{
					m_ani_frame = 0;
					attack_set = true;
					attack_flag = true;
				}
			}
			else
			{
				attack_flag = false;
			}
		}
			if (attack_set == true && wepon_have > 0 && wepon_have != 4)
			{
				//切り取り位置の設定
				src.m_top = 0.0f + wepon_have * 64;
				src.m_left = 0.0f + AniData3[m_ani_frame] * 64;
				src.m_right = 64.0f + src.m_left;
				src.m_bottom = 64.0f + src.m_top + 46.0f;

				//表示位置の設定
				dst.m_top = 0.0f + m_py;
				dst.m_left = (64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
				dst.m_right = (64 - 64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
				dst.m_bottom = 64.0f + m_py;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
				wepon_attack = wepon_have;
			}
			else
			{
				wepon_attack = 0;
			}
		}
		if (m_ani_frame > 2)
		{
			attack_set = false;
		}
	}

	if (p_menuflag == true)				//メニュー
	{
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 910.0f;
		src.m_bottom = 512.0f;

		//背景の位置を設定し描画
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//強調表示用バー
		//切り取り位置の設定
		src.m_top = 64.0f*5;
		src.m_left = 64.0f * 5;
		src.m_right = 64.0f * 5+192;
		src.m_bottom = 64.0f * 5+64;

		//バーの位置を設定し描画
		dst.m_top = 100.0f + lavel_select * 50;
		dst.m_left = 250.0f;
		dst.m_right = 30.0f;
		dst.m_bottom = 140.0f + lavel_select * 50;
		Draw::Draw(2, &src, &dst, c, 0.0f);


		Font::StrDraw(L"アイテム", 50, 100, 32, c);
		Font::StrDraw(L"装備", 50, 150, 32, c);
		Font::StrDraw(L"キャラクター", 50, 200, 32, c);
		Font::StrDraw(L"セーブ", 50, 250, 32, c);
		Font::StrDraw(L"ゲーム終了", 50, 300, 32, c);
		Font::StrDraw(L"戻る", 50, 350, 32, c);
	}
}