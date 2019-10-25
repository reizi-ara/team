//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGINF (0)

//Gameで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h" 
#include "GameL\UserData.h" 

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//外部データの読み込み(ステージ情報）
	unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;			 //ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"マップ.csv", &size);//外部データ読み込み

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"player.png", 1, TEX_SIZE_512);

	//主人公オブジェクトの作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//タイムオブジェクト作成
	CObjTime*objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);

	//メニューオブジェクト作成
	CObjMenu*objm = new CObjMenu();
	Objs::InsertObj(objm, OBJ_MENU, 5);
}

//実行中メソッド
void CSceneMain::Scene()
{

}