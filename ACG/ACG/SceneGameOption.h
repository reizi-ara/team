#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneGameOption :public CScene
{
public:
	CSceneGameOption();
	~CSceneGameOption();
	void InitScene();//ゲームタイトルの初期化メソッド
	void Scene();    //ゲームタイトルの実行中メソッド
private:
};
