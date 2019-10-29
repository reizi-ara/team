#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjTuta : public CObj
{
	public:
		CObjTuta(float x,float y) ;
		~CObjTuta() {};
		void Init();		//イニシャライズ
		void Action();		//アクション
		void Draw();		//ドロー
	private:
		float word_x; //主人公のx座標
		float word_y; //主人公のy座標

		int window_flag;

		float m_x;//メッセージ座標
		float m_y;
};
