//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

#include "main.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "MacroManagement.h"

//使用するネームスペース
using namespace GameL;


CObjBlock::CObjBlock(int map[MAP_Y][MAP_X])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
}

//イニシャライズ
void CObjBlock::Init()
{
	mmmm = false;
	m_scroll = 0.0f;
	ikkai = true;
}

//アクション
void CObjBlock::Action()
{

	if (ikkai == true)
	{
		//メインからマップ2のアドレスを持ってくる
		CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
		map2 = sceneM->GetM1();
		One_chg = sceneM->GetONEs();
		ikkai = false;

	}

	if (m_chg > MAP_NULL_NUMBER)
	{
		m_chg = MAP_NUMBER_5;
	}
	
	int count = 0;//1000回数えるよう

	if (m_chg == MAP_NUMBER_1 && One_chg == true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;

	}
	else if (m_chg == MAP_NUMBER_2 &&One_chg==true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;

	}
	else if (m_chg == MAP_NUMBER_3 && One_chg == true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;


	}
	else if (m_chg == MAP_NUMBER_4 && One_chg == true)
	{

		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}
	else if (m_chg == MAP_NUMBER_5 && One_chg == true)	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;
	}
	/*else if (m_chg == 5 && One_chg == true) {
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int) * (MAP_Y * MAP_X));
		One_chg = false;
	}*/

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < WINDOW_SIZE_W / BLOOK_BACK_SCROLL_LINE)
	{
		hero->SetX(WINDOW_SIZE_W / BLOOK_BACK_SCROLL_LINE);				//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();  //主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロール
	if (hx > WINDOW_SIZE_W / BLOOK_PREVIOUS_SCROLL_LINE)
	{
		hero->SetX(WINDOW_SIZE_W / BLOOK_PREVIOUS_SCROLL_LINE);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	
	//敵出現ラインの列を検索
	for (int ex = SCENE_MAIN_MAP_READ_INITIAL_X; ex < MAP_X; ex++) {
		for (int i = SCENE_MAIN_MAP_READ_INITIAL_Y; i < MAP_Y; i++)
		{
			if (m_map[i][ex] == BLOOK_NULL_NUMBER) {
				;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_PJ_NUMBER) {//敵1(PJ-xyhat
				CObjEnemy* obj20 = new CObjEnemy(ex * 64.0f, i * 64.0f, 30, 20, ENEMY_PJ_TYPE);
				Objs::InsertObj(obj20, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_EYE_NUMBER) {//敵2目
				CObjEnemy* obj21 = new CObjEnemy(ex * 64.0f, i * 64.0f, 30, 20, ENEMY_EYE_TYPE);
				Objs::InsertObj(obj21, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_DOC_NUMBER) {//敵3(inu
				CObjEnemy* obj22 = new CObjEnemy(ex * 64.0f, i * 64.0f, 50, 45, ENEMY_DOG_TYPE);
				Objs::InsertObj(obj22, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_CACTUS_NUMBER) {//緑の
				CObjEnemy* obj23 = new CObjEnemy(ex * 64.0f, i * 64.0f, 60, 35, ENEMY_GREEN_TYPE);
				Objs::InsertObj(obj23, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ITEM_HEAL_NUMBER) {//item:hp*0.5
				CObjEnemy* obj25 = new CObjEnemy(ex * 64.0f, i * 64.0f, 60, 10, ENEMY_HEAL_TYPE);
				Objs::InsertObj(obj25, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ITEM_BIGHEAL_NUMBER) {//item
				CObjEnemy* obj26 = new CObjEnemy(ex * 64.0f, i * 64.0f, 200, 10, ENEMY_HEAL_TYPE);
				Objs::InsertObj(obj26, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_BOSS_NUMBER) {//boss
				CObjBoss* obj27 = new CObjBoss(ex * 64.0f, i * 64.0f, 200, 50);
				Objs::InsertObj(obj27, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_HAND_NUMBER) {//触腕
				CObjhand* obj30 = new CObjhand(ex * 64.0f, i * 64.0f, 0, 7);
				Objs::InsertObj(obj30, OBJ_HAND, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_THORN3_NUMBER) {//蔦3
				CObjThorn* obj33 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 3);
				Objs::InsertObj(obj33, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_THORN7_NUMBER) {//蔦7
				CObjThorn* obj37 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 7);
				Objs::InsertObj(obj37, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_CANDLE_NUMBER) {//蝋燭
				CObjCandle* obj39 = new CObjCandle(ex * 64.0f, i * 64.0f);
				Objs::InsertObj(obj39, OBJ_CANDLE, 99);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == BLOCK_OBJ_NEXT_DOOR_NUMBER) {//次マップ移動扉
				CObjMapChanger* obj40 = new CObjMapChanger(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj40, OBJ_MAPCHANGER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BACK_DOOR_NUMBER) {//次マップ移動扉
				CObjMapBacker* obj41 = new CObjMapBacker(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj41, OBJ_MAPBACKER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_END_DOOR_NUMBER) {//エンディング扉
				CObjEndingDoor* obj42 = new CObjEndingDoor(ex * 64.0f, i * 64.0f);
				Objs::InsertObj(obj42, OBJ_ENDING_DOOR, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK1_NUMBER) {//本棚1
				CObjMessage* obj50 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE1);
				Objs::InsertObj(obj50, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK2_NUMBER) {//本棚2				
				CObjMessage* obj51 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE2);
				Objs::InsertObj(obj51, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK3_NUMBER) {//本棚3
				CObjMessage* obj52 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE3);
				Objs::InsertObj(obj52, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK4_NUMBER) {//本棚4
				CObjMessage* obj53 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE4);
				Objs::InsertObj(obj53, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK5_NUMBER) {//本棚5
				CObjMessage* obj54 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE5);
				Objs::InsertObj(obj54, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
		}
	}
}

//BlockHit関数
//引数1　float*　ｘ　：判定を行うobjectのX位置
//引数2　float*　ｙ　：判定を行うobjectのY位置
//引数3　bool　scroll_on　：判定を行うobjectはスクロールに影響を与えるかどうか（true＝与える　false＝与えない）
//引数4　bool*　up　：上下左右判定の上部分に当たってるかどうかを返す
//引数5　bool*　down　：上下左右判定の下部分に当たってるかどうかを返す
//引数6　bool*　left　：上下左右判定の左部分に当たってるかどうかを返す
//引数7　bool*　right　：上下左右判定の右部分に当たってるかどうかを返す
//引数8　float*　ｖｙ　：左右判定時の反発による移動方向・力の値を変えて返す
//引数9　float*　ｖｙ　：上下判定時による自由落下運動による移動方向・力の値を変えて返す
//引数10　int*　ｂｔ　：下部分判定時、特殊なブロックのタイプ返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4〜10に返す
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool* left, bool *right,
	float* vx, float*vy, int* bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (m_map[i][j] > 0&&m_map[i][j]<=9)
			{
				//要素番号を座標に変更
				float bx = j*64.0f;
				float by = i*64.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll: 0;

				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 64.0f>bx) && (*x + (-scroll)<bx + 64.0f) && (*y + 64.0f>by) && (*y<by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さのより短い場合判定に入る
					if (len < 86.0f)
					{
						//角度で上下左右を判定
						if ((r<45 && r>0) || r>315)
						{
							//右
							*right=true;//主人公の左の部分が衝突している
							*x=bx+64.0f+(scroll);//ブロックの位置+主人公の幅
							*vx = -(*vx)*0.1f;//-VX*反発係数
						}
						if (r>45 && r<135)
						{
							//上
							*down=true;//主人公の下の部分が衝突している
							*y=by-64.0f;//ブロックの位置ー主人公の幅
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];
							*vy = 0.0f;
						}
						if (r>135 && r<225)
						{
							//左
							*left = true;//主人公の右の部分が衝突している
							*x = bx - 64.0f + (scroll);//ブロックの位置ー主人公の幅
							*vx = -(*vx)*0.1f;//-VX*反発係数
						}
						if (r>225 && r<315)
						{
							//下
							*up = true;//主人公の上の部分が衝突している
							*y = by + 64.0f;//ブロックの位置+主人公の幅
							if(*vy<0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}

//BlockDrawMethod関数
//引数1　float　ｘ：リソース切り取り位置X
//引数2　float　ｙ：リソース切り取り位置Y
//引数3　RECT＿F*ｄｓｔ：描画位置
//引数4　float　ｃ[]：カラー情報
//引数5　int スプライトナンバー
//ブロックを64×64限定描画用。リソース切り取り位置のみｘ・ｙで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[],int s)
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(s, &src, dst, c, 0.0f);
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4]  = { 0.7f,0.7f,0.7f,1.0f };
	float cr[4] = { 0.4f,0.4f,0.4f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示!n
	src.m_top = 512.0f*0;
	src.m_left = 0.0f;
	src.m_right = 910.0f;
	src.m_bottom = 512.0f+ src.m_top;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f+m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j] == 1)
				{
					BlockDraw(0.0f, 128.0f, &dst, c,2);
				}
				else if (m_map[i][j] == 2)
				{
					BlockDraw(64.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 3)
				{
					BlockDraw(128.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 4)
				{
					BlockDraw(192.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 5)
				{
					BlockDraw(256.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 6)
				{
					BlockDraw(320.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 13)
				{
					BlockDraw(128.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 14)
				{
					BlockDraw(192.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 15)
				{
					BlockDraw(256.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 16)
				{
					BlockDraw(320.0f, 128.0f, &dst, cr, 2);
				}
				else
				{

				}
			}
		}
	}
}





void CObjBlock::Transfer(int map[MAP_Y][MAP_X],int* map2)
{
	int count = 0;
	//マップ情報を移す
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{

			map[i][j] = *(map2 + count);
			count++;

		}

	}
}




