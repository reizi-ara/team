//STGデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"	

//コンストラクタ
CSceneGameOption::CSceneGameOption()
{

}

//デストラクタ
CSceneGameOption::~CSceneGameOption()
{

}

//ゲームスタート初期化メソッド
void CSceneGameOption::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"戻る");
	Font::SetStrTex(L"まだ作ってません。");
	Font::SetStrTex(L"ごめんなさい");

	//背景読み込み
	Draw::LoadImageW(L"splite5.png", 2, TEX_SIZE_1024);
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);

	Draw::LoadImageW(L"splite4.png", 4, TEX_SIZE_1024);

	//オプションオブジェクト作成
	CObjGameOption*obj = new CObjGameOption(); //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAME_OPTION, 10);//タイトルオブジェクト登録

}

//ゲームスタート実行中メソッド
void CSceneGameOption::Scene()
{

}