//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGINF (0)

//Gameで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h" 
#include "GameL\UserData.h" 
#include "GameL\Audio.h"

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
	One_chg = false;
	m_chg = 0;

	//外部データの読み込み(ステージ情報）
	//unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;			 //ステージ情報の大きさ
	p[0] = Save::ExternalDataOpen(L"マップ.csv", &size);//外部データ読み込み

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p[0].get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み

	Draw::LoadImageW(L"メッセージウインドウ.png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"splite0.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"splite1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"splite2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"フキダシ3.png", 8, TEX_SIZE_512);
	
	
	//910:512*
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite4.png", 4, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite5.png", 5, TEX_SIZE_1024);

	


	

	//主人公オブジェクトの作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);
	//音楽読み込み
	Audio::LoadAudio(0, L"閉ざされた部屋.wav", BACK_MUSIC);

	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneMain::Scene()
{


	CObjMapChanger*MapChanger = (CObjMapChanger*)Objs::GetObj(OBJ_MAPCHANGER);

	if (MapChanger == nullptr)
	{
		;
	}
	else
	{
		m_chg = MapChanger->GetTT();
		One_chg = MapChanger->GetONE();
	}

	if (m_chg == 1)
	{

		unique_ptr<wchar_t> p1;//ステージ情報ポインター
		int size;			 //ステージ情報の大きさ
		p1 = Save::ExternalDataOpen(L"仮マップ１.csv", &size);//外部データ読み込み

		int count = 1;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int w = 0;
				swscanf_s(&p1.get()[count], L"%d", &w);

				map2[i][j] = w;
				count += 2;
			}
		}
		//One_chg = false;

	}


	if (m_chg == 2)
	{

		unique_ptr<wchar_t> p2;//ステージ情報ポインター
		int size;			 //ステージ情報の大きさ
		p2 = Save::ExternalDataOpen(L"マップ2.csv", &size);//外部データ読み込み

		int count = 1;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int w = 0;
				swscanf_s(&p2.get()[count], L"%d", &w);

				map2[i][j] = w;
				count += 2;
			}
		}

		//One_chg = false;
	}



}



