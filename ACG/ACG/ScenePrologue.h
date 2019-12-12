#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CScenePrologue :public CScene
{
public:
	CScenePrologue();
	~CScenePrologue();
	void InitScene();
	void Scene();
private:
};
