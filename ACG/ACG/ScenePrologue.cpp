//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GamrLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CScenePrologue::CScenePrologue()

{

}

//デストラクタ
CScenePrologue::~CScenePrologue()
{

}

//ゲームオーバー初期化メゾット
void CScenePrologue::InitScene()
{

	//ゲームオーバーオブジェクト作成
	CObjPrologue*obj = new CObjPrologue();
	Objs::InsertObj(obj, OBJ_PROLOGUE, 10);

	//背景読み込み
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite2.png", 2, TEX_SIZE_512);

	//音楽読み込み
	Audio::LoadAudio(0, L"s_end.wav", BACK_MUSIC);

	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

}

//ゲームオーバー実行中メゾット
void CScenePrologue::Scene()
{

}