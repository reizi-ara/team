#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイム
class CObjTime :public CObj
{
	public:
		CObjTime() {};
		~CObjTime() {};
		void Init();	//イニシャライズ
		void Action();  //アクション
		void Draw();	//ドロー

		void SetTimeFlag(bool b) { m_flag_time = b; }
	private:
		int m_time;//時間
		bool m_flag_time;//時間計測スタートフラグ
};