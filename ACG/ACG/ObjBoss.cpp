//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBoss.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "GameL/Audio.h"

#define MUTEKI 8;
#define DE_MAGE 10;//hidame
#define SARCH 400

//使用するネームスペースdayo
using namespace GameL;

CObjBoss::CObjBoss(float x, float y, float l, float a)
{
	m_px = x;
	m_py = y;
	en_life = l;
	atk = a;
}

//イニシャライズ
void CObjBoss::Init()
{

	Audio::Stop(0);//出現時BGM変更
	Audio::Start(1);

	awake = false;//起動確認
	m_vx = 0.0f;	//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//向き/右向き0.0ｆ　左向き1.0ｆ
	m_move = true;		//同義、要修正↑統合
	dir_act = m_move;	//向き変更検知用

	m_ani_time = 0;		//animation frame controal time
	m_ani_frame = 1;

	m_speed_power = 0.0f;	//通常速度



	muteki_time = MUTEKI;



	time_1 = 0;//起動からの時間

	time_2 = 0;//弾発射間隔制御時間

	dy_time = 0;//消去猶予時間

	form = 0;//要整理
	acmt[0] = 0;
	acmt[1] = 1;
	bulletQ = 0;
	bulletA = 0;

	damagecolortime = 10;//被ダメージ表現時間



	CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();//異マップ移動時削除
	if (sceneM == nullptr) {}
	else destryNum = sceneM->GetDS();
}

//アクション
void CObjBoss::Action()
{
	//ブロック・判定
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = hero->GetX() - block->GetScroll()+32.0f;
	float pl_y = hero->GetY() + 32.0f;
	float sl = block->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;

	//移動力減衰
	m_vx *= 0.8f;

	//起動
	if (pl_x <= en_x + SARCH &&
		pl_x >= en_x - SARCH &&
		awake == false)
		awake = true;

	//被攻撃
	if (pl_x <= en_x + 24 - (32 * (hero->Getposture() * 2 - 1)) &&
		pl_x >= en_x - 88 - (32 * (hero->Getposture() * 2 - 1)) &&
		pl_y <= en_y - 96.0f && pl_y >= en_y - 220.0f &&
		hero->Getattack() > 0 && muteki_time <= 0) {
		muteki_time = MUTEKI;
		en_life -= DE_MAGE;
		damagecolortime = 0;
	}

	//与攻撃
	if (pl_x <= en_x + 24.0f &&
		pl_x >= en_x - 88.0f &&
		pl_y <= en_y - 96.0f &&
		pl_y >= en_y - 224.0f) {
		if (form == 1) {
			hero->GiveDamageToPlayer(atk * 0.8);
		}
		else {
			hero->GiveDamageToPlayer(atk * 0.25);
		}
		if (atk_kb == false) {//&&obj->Getmutekitime()<=0) {
			if (pl_x<= en_x) {
				hero->SetVX(-35);
			}
			else if (pl_x> en_x) {
				hero->SetVX(35);
			}
		}
		atk_kb = true;
	}
	else {
		atk_kb = false;
	}

	//ブロックとの当たり判定実行しない
	//シーン移動削除処理
	CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();
	if (destryNum != MdestryNum) {
		Audio::Stop(1);//効果音ストップ
		Audio::Start(0);//効果音スタート
		this->SetStatus(false);
	}
	if (Input::GetVKey('L')) {
		en_life -= 5.0f;
	}

	//プレイヤー勝利
	if (en_life <= 0)
	{


		dy_time++;
		time_1 = 0;
		if (dy_time < 180) {
			CObjEffect* objef = new CObjEffect(m_px + block->GetScroll() -
				((dy_time * 77) % 64) * (dy_time % 2 * 2 - 1),
				m_py - ((dy_time * 137) % 128) * (dy_time % 2 * 2 - 1) - 64,
				1);
			Objs::InsertObj(objef, OBJ_THORN, 15);
		}
	}
	if (dy_time > 200) {

		Audio::Stop(1);//効果音ストップ
		//Audio::Start(0);//効果音スタート 要らんかもしれんからコメントアウト。
		CObjEndingDoor* EndDoor = (CObjEndingDoor*)Objs::GetObj(OBJ_ENDING_DOOR);
		EndDoor->DoorSystemPG(2);//ドアが２で開くので2を

		this->SetStatus(false);
	}

	//表示位置の更新
	m_px += m_vx;
	m_py += m_vy;


	//向き変更
	if (pl_x<= en_x)
		m_move = true;
	if (pl_x> en_x)
		m_move = false;
	if (dir_act != m_move) {
		dir_act = m_move;
		m_speed_power = 0.0f;
	}

	//アニメーション
	if (m_move == false) {//向き
		m_posture = 1.0f;
		m_ani_time += 2;
	}
	else if (m_move == true) {
		m_posture = 0.0f;
		m_ani_time += 2;
	}
	if (m_ani_time > 8) {
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 8) {//ループ処理
		m_ani_frame = 0;
	}

	//ノックバックh
	muteki_time--;
	if (muteki_time > 0 && awake == true) {
		if (pl_x<= en_x) {
			m_vx = (5 + m_speed_power) * 0.8f;
		}
		else if (pl_x> en_x) {
			m_vx = (-5 - m_speed_power) * 0.8f;
		}
	}
	if (muteki_time == 0)
		m_speed_power *= 0.7f;
	//-------------------------------------------------------------
	if (muteki_time <= 0 && awake == true) {
		time_1++;

		if (time_1 == 20) {
			acmt[0] = 1;
			acmt[1] = 1;
		}
		if (time_1 == 200) {

			bulletQ = 1;
		}
		if (time_1 == 900) {
			acmt[0] = 0;
			acmt[1] = 0;
		}
		if (time_1 == 990) {
			acmt[0] = 0;
			acmt[1] = 1;
			bulletQ = 0;
		}
		if (time_1 == 1100) {
			acmt[0] = 1;
			acmt[1] = 2;
		}
		if (time_1 == 1200) {
			acmt[0] = 0;
		}
		if (time_1 == 1280) {
			acmt[0] = 1;
			acmt[1] = 3;
		}
		if (time_1 == 1400) {
			acmt[0] = 0;
			acmt[1] = 1;
		}
		if (time_1 == 1600) {
			acmt[0] = 1;
			acmt[1] = 0;
		}
		if (time_1 == 1700) {
			acmt[0] = 0;
			acmt[1] = 4;
		}
		if (time_1 == 1750) {
			acmt[0] = 1;
			acmt[1] = 4;
		}
		if (time_1 == 1850) {
			acmt[0] = 0;
			acmt[1] = 5;
		}
		if (time_1 == 1920) {
			acmt[0] = 0;
			acmt[1] = 1;
		}
		if (time_1 == 2000) {
			acmt[0] = 0;
			acmt[1] = 1;
			bulletQ = 2;
		}



		if (time_1 == 2560) {
			acmt[0] = 0;
			acmt[1] = 0;
			time_1 = 900;
			bulletQ = 0;
		}

		if (bulletQ == 1) {
			if (time_1 % 120 == 0) {
				for (int i = 0; i < 8; i++) {
					CObjBullet* objbt = new CObjBullet(100 - sl + i * 200 + (time_1 % 100), 0, 20, 3);
					Objs::InsertObj(objbt, OBJ_ENEMY, 10);
				}
				bulletA = 1;
				time_2 = 0;
			}
		}

		if (bulletQ == 2) {
			if (time_1 % 5 == 0 && time_1 % 100 < 20) {
				for (int i = 0; i < 6; i++) {
					CObjBullet* objbt = new CObjBullet(100 - sl + i * 250 + (time_1 % 100), 0, 20, 10);
					Objs::InsertObj(objbt, OBJ_ENEMY, 10);
				}

				bulletA = 1;
				time_2 = 0;
			}
		}

		if (acmt[0] == 1) {//高さ合わせ
			if (pl_y + 128 <= en_y) {
				m_py -= 2;
			}
			else if (pl_y + 128 > en_y) {
				m_py += 2;
			}
		}

		if (acmt[1] == 1) {//近距離　待機
			form = 0;
			if (pl_x+ 256 <= en_x) {
				m_px += (pl_x+ 256 - en_x) / 130;
			}
			else if (pl_x+ 256 > en_x) {
				m_px += (pl_x+ 256 - en_x) / 130;
			}
		}

		if (acmt[1] == 2) {//遠距離　突進準備
			form = 0;
			if (pl_x+ 1536 <= en_x) {
				m_px += (pl_x+ 1536 - en_x) / 90;
			}
			else if (pl_x+ 1536 > en_x) {
				m_px += (pl_x+ 1536 - en_x) / 90;
			}
		}

		if (acmt[1] == 3) {//突進
			form = 1;
			if (pl_x- 1024 <= en_x) {
				m_px += (pl_x- 1024 - en_x) / 30;
			}
			else if (pl_x- 1024 > en_x) {
				m_px += (pl_x - 1024 - en_x) / 30;
			}
		}
		if (acmt[1] == 4) {//びむー　待機
			form = 2;
			if (pl_x + 512 <= en_x) {
				m_px += (pl_x + 512 - en_x) / 20;
			}
			else if (pl_x + 512 > en_x) {
				m_px += (pl_x + 512 - en_x) / 20;
			}
		}
		if (acmt[1] == 5) {//びむー
			form = 3;
			if (pl_x + 512 <= en_x) {
				m_px += (pl_x  + 512 - en_x) / 20;
			}
			else if (pl_x  + 512 > en_x) {
				m_px += (pl_x + 512 - en_x) / 20;
			}
			if (Input::GetVKey('S') == false) {

				if (pl_x  <= en_x + 24.0f &&
					pl_x >= en_x - 2188.0f &&
					pl_y <= en_y - 110.0f &&
					pl_y >= en_y - 165.0f) {/////////////////////////////////////
					hero->GiveDamageToPlayer(atk * 1.2f);
					hero->SetVX(-20);
					hero->SetVY(5);
				}
			}
		}



	}

	time_2++;
	if (bulletA == true && time_2 > 8)
		bulletA = false;
	if (damagecolortime < 10)
		damagecolortime++;
}

//ドロー
void CObjBoss::Draw()
{
	int AniData[8] =
	{//横・縦
		0,0,1,1,2,2,3,3
	};
	float c[4] = { 0.8f ,0.8f * damagecolortime * 0.1,0.8f * damagecolortime * 0.1,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	if (form == 0) {
		src.m_top = 0;
		src.m_left = AniData[m_ani_frame] * 256.0f;
		src.m_right = src.m_left + 256.0f;
		src.m_bottom = src.m_top + 256.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = (256.0f * m_posture) + m_px + block->GetScroll() - 128.0f;
		dst.m_right = (256.0f - 256.0f * m_posture) + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = 64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	if (form == 2 || form == 3) {
		src.m_top = 0;
		src.m_left = AniData[m_ani_frame] * 256.0f;
		src.m_right = src.m_left + 256.0f;
		src.m_bottom = src.m_top + 256.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = m_px + block->GetScroll() - 128.0f;
		dst.m_right = 256.0f + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = 64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	if (form == 1) {
		src.m_top = 256;
		src.m_left = AniData[m_ani_frame / 2] * 512.0f;
		src.m_right = src.m_left + 512.0f;
		src.m_bottom = src.m_top + 256.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = m_px + block->GetScroll() - 128.0f;
		dst.m_right = 512.0f + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = 64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);

		src.m_top = 512;
		src.m_left = AniData[m_ani_frame] * 256.0f;
		src.m_right = src.m_left + 256.0f;
		src.m_bottom = src.m_top + 256.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = m_px + block->GetScroll() - 128.0f;
		dst.m_right = 256.0f + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = 64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	if (form == 2 || form == 3) {

		src.m_top = 768;
		src.m_left = AniData[m_ani_frame] * 256.0f;
		src.m_right = src.m_left + 256.0f;
		src.m_bottom = src.m_top + 128.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = m_px + block->GetScroll() - 128.0f;
		dst.m_right = 256.0f + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = -64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);

		src.m_top = 896;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 1024.0f;
		src.m_bottom = src.m_top + 128.0f;

		if (form == 2) {
			dst.m_top = -120.0f + m_py;
			dst.m_left = -1500 + m_px + block->GetScroll() - 128.0f;
			dst.m_right = 128 + m_px + block->GetScroll() - 128.0f;
			dst.m_bottom = -128.0f + m_py;
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
		if (form == 3) {
			dst.m_top = -192.0f + m_py;
			dst.m_left = -1500 + m_px + block->GetScroll() - 128.0f;
			dst.m_right = 128 + m_px + block->GetScroll() - 128.0f;
			dst.m_bottom = -64.0f + m_py;
			Draw::Draw(7, &src, &dst, c, 0.0f);
		}
	}

	if (bulletA == true) {
		src.m_top = 768;
		src.m_left = AniData[m_ani_frame] * 256.0f;
		src.m_right = src.m_left + 256.0f;
		src.m_bottom = src.m_top + 128.0f;

		dst.m_top = -192.0f + m_py;
		dst.m_left = m_px + block->GetScroll() - 128.0f;
		dst.m_right = 256.0f + m_px + block->GetScroll() - 128.0f;
		dst.m_bottom = -64.0f + m_py;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
}