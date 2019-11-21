#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

#define MAP_X (100)
#define MAP_Y (10)

//シーン：メイン
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//初期化メソッド
		void Scene();		//実行中メソッド

		int* GetM1() { return &map2[0][0]; }//マップ情報２を送る関数？

		int GetDS() { return m_chg; }

		int GetONEs() { return One_chg; }
	
	private:
		int m_chg;	//マップチェンジ
		int One_chg;//一回処理用

		int map2[10][100];	//マップ情報２



		unique_ptr<wchar_t> p[5];//ステージ情報ポインター

};
