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
	OneRead = false;
	m_chg = 0;

	//外部データの読み込み(ステージ情報）
	//unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;			 //ステージ情報の大きさ
	p[0] = Save::ExternalDataOpen(L"map_0.csv", &size);//外部データ読み込み
	p[1] = Save::ExternalDataOpen(L"map_1.csv", &size);//外部データ読み込み
	p[2] = Save::ExternalDataOpen(L"map_2.csv", &size);//外部データ読み込み
	p[3] = Save::ExternalDataOpen(L"map_3.csv", &size);//外部データ読み込み
	p[4] = Save::ExternalDataOpen(L"map_4.csv", &size);//外部データ読み込み

	MapRead(m_chg, map2, p);//マップロード関数？

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み

	Draw::LoadImageW(L"splite0.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"splite1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"splite2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"splite6.png", 6, TEX_SIZE_512);
	
	//910:512*
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite4.png", 4, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite5.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite7.png", 7, TEX_SIZE_1024);

	Draw::LoadImageW(L"kuro.png", 88, TEX_SIZE_1024);


	//主人公オブジェクトの作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 14);

	//blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map2);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);


	

	//音楽読み込み
	//BGM群
	Audio::LoadAudio(0, L"s_mainstage.wav", BACK_MUSIC);//メインBGM
	Audio::LoadAudio(1, L"s_Boss.wav", BACK_MUSIC);//ボスのBGM
	Audio::LoadAudio(2, L"s_menu.wav", BACK_MUSIC);//メニューのBGM

	//SE群
	Audio::LoadAudio(5, L"s_walk.wav", EFFECT);//歩きと走りSE
	Audio::LoadAudio(6, L"s_door.wav", EFFECT);//ドアSE
	Audio::LoadAudio(7, L"s_attack.wav", EFFECT);//敵ダメージ時SE
	Audio::LoadAudio(8, L"s_ok.wav", EFFECT);//決定SE
	Audio::LoadAudio(9, L"s_select.wav", EFFECT);//セレクトSE
	Audio::LoadAudio(10, L"s_book_open.wav", EFFECT);//本開け
	Audio::LoadAudio(11, L"s_book_close.wav", EFFECT);//本閉じ
	Audio::LoadAudio(12, L"s_chicken.wav", EFFECT);//手のSE
	Audio::LoadAudio(13, L"s_attackA.wav", EFFECT);//手のSE


	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);
}

//実行中メソッド
void CSceneMain::Scene()
{
	if (m_chg >= 5)
	{
		m_chg = 5;
	}

	//マップ読み込み
	if (m_chg == 0 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 1 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 2 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;
	}
	if (m_chg == 3 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 4 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	/*else if (m_chg == 5 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 6 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 7 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 8 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 9 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}*/

}

void CSceneMain::MapRead(int m_chg, int map[MAP_Y][MAP_X], unique_ptr<wchar_t>* p)
{
	int count = 1;
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			int w = 0;
			swscanf_s(&p[m_chg].get()[count], L"%d", &w);

			map[i][j] = w;
			count += 3;
		}
	}

}




