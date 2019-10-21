//STGデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"	

//コンストラクタ
CSceneGameStart::CSceneGameStart()
{

}

//デストラクタ
CSceneGameStart::~CSceneGameStart()
{

}

//ゲームスタート初期化メソッド
void CSceneGameStart::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"かぼちゃの館");

	//タイトルオブジェクト作成
	CObjGameStart*obj = new CObjGameStart(); //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_GAME_START, 10);//タイトルオブジェクト登録

}

//ゲームスタート実行中メソッド
void CSceneGameStart::Scene()
{

}