#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
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


		//ブロックと当たり判定
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool* left, bool *right,
			float* vx, float*vy, int* bt
		);

	private:
		void BlockDraw(float x, float y, RECT_F*dst, float c[],int s);
		int m_map[10][100];//マップ情報（仮）

		float m_scroll; //左右スクロール用


		int map[10][100];

		int m_chg;

		//unique_ptr<wchar_t> p[5];

};