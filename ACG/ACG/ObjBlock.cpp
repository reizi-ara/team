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
	
	int count = 0;//1000回数えるよう

	if (m_chg == 0 && One_chg == true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;

	}
	else if (m_chg == 1&&One_chg==true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;

	}
	else if (m_chg == 2 && One_chg == true)
	{
		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;


	}
	else if (m_chg == 3 && One_chg == true)
	{

		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}
	else if (m_chg == 4 && One_chg == true)
	{

		Transfer(map, map2);
		//マップデータをコピー
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}

	//主人公の位置を取得
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < WINDOW_SIZE_W /7*1.6f)
	{
		hero->SetX(WINDOW_SIZE_W / 7 * 1.6f);				//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();  //主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロール
	if (hx > WINDOW_SIZE_W / 7 * 4.0f)
	{
		hero->SetX(WINDOW_SIZE_W / 7 * 4.0f);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	
	//敵出現ラインの列を検索
	for (int ex = 0; ex < MAP_X; ex++) {
		for (int i = 0; i < MAP_Y; i++)
		{
			if (m_map[i][ex] == 0) {
				;
			}
			else if (m_map[i][ex] == 20) {//敵1(PJ
				CObjEnemy* obj20 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 1);
				Objs::InsertObj(obj20, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 21) {//敵2(Jump
				CObjEnemy* obj21 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 2);
				Objs::InsertObj(obj21, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 22) {//敵3
				CObjEnemy* obj22 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 3);
				Objs::InsertObj(obj22, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 23) {//敵4
				CObjEnemy* obj23 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 4);
				Objs::InsertObj(obj23, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 27) {//boss
				CObjBoss* obj27 = new CObjBoss(ex * 64.0f, i * 64.0f, 900, 50);
				Objs::InsertObj(obj27, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == 30) {//触腕
				CObjhand* obj30 = new CObjhand(ex * 64.0f, i * 64.0f, 0, 15);
				Objs::InsertObj(obj30, OBJ_HAND, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 33) {//蔦3
				CObjThorn* obj33 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 3);
				Objs::InsertObj(obj33, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 37) {//蔦7
				CObjThorn* obj37 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 7);
				Objs::InsertObj(obj37, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == 40) {//次マップ移動扉
				CObjMapChanger* obj40 = new CObjMapChanger(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj40, OBJ_MAPCHANGER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 41) {//次マップ移動扉
				CObjMapBacker* obj41 = new CObjMapBacker(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj41, OBJ_MAPBACKER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 50) {//本棚１
				CObjMessage* obje = new CObjMessage(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obje, OBJ_MESSAGE, 10);
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
//その結果は引数4～10に返す
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
	float c[4]  = { 1.0f,1.0f,1.0f,1.0f };
	float cr[4] = { 0.7f,0.7f,0.7f,1.0f };

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




	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
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




