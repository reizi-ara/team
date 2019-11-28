#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "SceneMain.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CObjBlock :public CObj
{
	public:
		CObjBlock(int map[10][100]);
		~CObjBlock() {};
		void Init();	//イニシャライズ
		void Action();  //アクション
		void Draw();	//ドロー


		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }

		//マップ用
		void SetM_CHG(bool mmmm) { m_chg = mmmm; }
		void Set_ikkai(bool oneIkkai) { ikkai = oneIkkai; }



		//ブロックと当たり判定
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool* left, bool *right,
			float* vx, float*vy, int* bt
		);

		//メインの情報をブロックのマップに移し替える関数
		void Transfer(int map[MAP_Y][MAP_X], int * map2);
		

	private:
		void BlockDraw(float x, float y, RECT_F*dst, float c[],int s);
		int m_map[10][100];//マップ情報（仮）

		float m_scroll; //左右スクロール用

		//map用
		int* map2;					//メインからマップ情報のアドレスをもらうやつ
		int map[10][100];			//もらったやつを移し替えるマップ情報用配列

		int m_chg;					//マップ変更するおおもとの変数

		bool mmmm;					//アクション入って1回とm_chgr接触時のみ
		bool One_chg;				//マップを1度だけ読み込むフラグ
		bool ikkai;					//マップのアドレスを一回だけ持ってくるフラグ

		//unique_ptr<wchar_t> p[5];

		

};