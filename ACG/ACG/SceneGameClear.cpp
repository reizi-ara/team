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
CSceneGameClear::CSceneGameClear()

{

}

//デストラクタ
CSceneGameClear::~CSceneGameClear()
{

}

//ゲームオーバー初期化メゾット
void CSceneGameClear::InitScene()
{
	//出力させる文字のグラフィックを作成
	//Font::SetStrTex(L"私が戦っていたのは何だったのだろう");
	//Font::SetStrTex(L"謎である");
	//Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//ゲームオーバーオブジェクト作成
	CObjGameClear*obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

	//背景読み込み
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);

	//音楽読み込み
	Audio::LoadAudio(0, L"雨.wav", BACK_MUSIC);

	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);

}

//ゲームオーバー実行中メゾット
void CSceneGameClear::Scene()
{

}