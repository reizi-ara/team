#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CSceneGameClear :public CScene
{
public:
	CSceneGameClear();
	~CSceneGameClear();
	void InitScene();
	void Scene();
private:
};
