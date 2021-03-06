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
#include "MacroManagement.h"

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
	m_chg = MAP_NUMBER_1;
	map_score = -1;
	//外部データの読み込み(ステージ情報）
	//unique_ptr<wchar_t> p;//ステージ情報ポインター
	int size;			 //ステージ情報の大きさ
	p[MAP_NUMBER_1] = Save::ExternalDataOpen(L"map_0.csv", &size);//外部データ読み込み
	p[MAP_NUMBER_2] = Save::ExternalDataOpen(L"map_1.csv", &size);//外部データ読み込み
	p[MAP_NUMBER_3] = Save::ExternalDataOpen(L"map_2.csv", &size);//外部データ読み込み
	p[MAP_NUMBER_4] = Save::ExternalDataOpen(L"map_3.csv", &size);//外部データ読み込み
	p[MAP_NUMBER_5] = Save::ExternalDataOpen(L"map_4.csv", &size);//外部データ読み込み

	MapRead(m_chg, map2, p);//マップロード関数？

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//グラフィック読み込み
	Draw::LoadImageW(L"splite0.png", SPLITE_NUMBER_0, TEX_SIZE_512);
	Draw::LoadImageW(L"splite1.png", SPLITE_NUMBER_1, TEX_SIZE_512);
	Draw::LoadImageW(L"splite2.png", SPLITE_NUMBER_2, TEX_SIZE_512);
	Draw::LoadImageW(L"splite6.png", SPLITE_NUMBER_6, TEX_SIZE_512);
	
	//910:512*
	Draw::LoadImageW(L"splite3.png", SPLITE_NUMBER_3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite4.png", SPLITE_NUMBER_4, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite5.png", SPLITE_NUMBER_5, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite7.png", SPLITE_NUMBER_7, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite8.png", SPLITE_NUMBER_8, TEX_SIZE_1024);

	//Draw::LoadImageW(L"kuro.png", 88, TEX_SIZE_1024);


	//主人公オブジェクトの作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 14);

	//blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map2);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);


	

	//音楽読み込み
	//BGM群
	Audio::LoadAudio(SCENE_MAIN_BGM_MAINSTAGE, L"s_mainstage.wav", BACK_MUSIC);//メインBGM
	Audio::LoadAudio(SCENE_MAIN_BGM_BOSS, L"s_Boss.wav", BACK_MUSIC);//ボスのBGM
	Audio::LoadAudio(SCENE_MAIN_BGM_MENU, L"s_menu.wav", BACK_MUSIC);//メニューのBGM

	//SE群
	Audio::LoadAudio(SCENE_MAIN_SE_WALK, L"s_walk.wav", EFFECT);//歩きと走りSE
	Audio::LoadAudio(SCENE_MAIN_SE_DOOR, L"s_door.wav", EFFECT);//ドアSE
	Audio::LoadAudio(SCENE_MAIN_SE_DAMEGE, L"s_attack.wav", EFFECT);//攻撃SE
	Audio::LoadAudio(SCENE_MAIN_SE_DECIDE, L"s_ok.wav", EFFECT);//決定SE
	Audio::LoadAudio(SCENE_MAIN_SE_SELECT, L"s_select.wav", EFFECT);//セレクトSE
	Audio::LoadAudio(SCENE_MAIN_SE_BOOK_OPEN, L"s_book_open.wav", EFFECT);//本開け
	Audio::LoadAudio(SCENE_MAIN_SE_BOOK_CLOSE, L"s_book_close.wav", EFFECT);//本閉じ
	Audio::LoadAudio(SCENE_MAIN_SE_HAND, L"s_chickens.wav", EFFECT);//手のSEとダメージ
	Audio::LoadAudio(SCENE_MAIN_SE_ATTACK, L"s_damage.wav", EFFECT);//攻撃ヒット時SE


	//ボリューム
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(SCENE_MAIN_BGM_MAINSTAGE);
}

//実行中メソッド
void CSceneMain::Scene()
{

	//マップの数を超えると強制的に最後のマップに戻す
	if (m_chg > MAP_NULL_NUMBER)
	{
		m_chg = MAP_NUMBER_5;
	}

	//マップ読み込み
	if (m_chg == MAP_NUMBER_1 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == MAP_NUMBER_2 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == MAP_NUMBER_3 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;
	}
	if (m_chg == MAP_NUMBER_4 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == MAP_NUMBER_5 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}

}

void CSceneMain::MapRead(int m_chg, int map[MAP_Y][MAP_X], unique_ptr<wchar_t>* p)
{
	int count = SCENE_MAIN_MAP_READ_COUNT;
	for (int i = SCENE_MAIN_MAP_READ_INITIAL_Y; i < MAP_Y; i++)
	{
		for (int j = SCENE_MAIN_MAP_READ_INITIAL_X; j < MAP_X; j++)
		{
			int w = 0;
			swscanf_s(&p[m_chg].get()[count], L"%d", &w);

			map[i][j] = w;
			count += 3;
		}
	}

}




