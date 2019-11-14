#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//初期化メソッド
		void Scene();		//実行中メソッド

		int* GetM1() { return &map2[0][0]; }//マップ情報２を送る関数？
	
	private:
		int m_chg;	//マップチェンジ

		int map2[10][100];	//マップ情報２
};