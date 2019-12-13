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

		//マップ変更用の関数群
		int* GetM1() { return &map2[0][0]; }//マップ情報２を送る関数？
		int GetDS() { return m_chg; }
		int GetONEs() { return One_chg; }
		void SetMMMMMM (int a) { m_chg += a; }

		void SetASDF(bool h) { OneRead = h; }
	
	private:
		int m_chg;	//マップチェンジ
		int One_chg;//一回処理用

		int map2[10][100];	//マップ情報２

		bool OneRead;

		unique_ptr<wchar_t> p[10];//ステージ情報ポインター

		void MapRead(int m_chg, int map[MAP_Y][MAP_X], unique_ptr<wchar_t>* p);

};

