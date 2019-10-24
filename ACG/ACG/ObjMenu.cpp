#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMenu.h"

const static int GAME_Y = 240;    //「ゲーム」文字のy位置
const static int CONFIG_Y = 270;    //「設定」文字のy位置

typedef enum {
	eMenu_Game,        //ゲーム
	eMenu_Config,    //設定

	eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

//更新
/*void Menu_Update() {
	if (Input::GetVKey('S')==1) {//下キーが押されていたら
		NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
	}
	if (Input::GetVKey('W') == 1) {//上キーが押されていたら
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
	}
	if (Input::GetVKey(VK_RETURN) == 1) {//エンターキーが押されたら
		switch (NowSelect) {//現在選択中の状態によって処理を分岐
		case eMenu_Game://ゲーム選択中なら
			CObjMenu(eScene_Game);//シーンをゲーム画面に変更
			break;
		case eMenu_Config://設定選択中なら
			SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
			break;
		}
	}
}*/

//ドロー
void Menu_Draw() {
	
}
//ドロー
void CObjGameStart::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 960.0f;
	src.m_bottom = 450.0f;

	//背景1の位置を設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	Font::StrDraw(L"メニュー画面", 200, 150, 32, c);
	Font::StrDraw(L"上下k－を押し、エンターキーを押してください。", 200, 170, 32, c);
	Font::StrDraw(L"ゲーム", 280, GAME_Y, 32, c);
	Font::StrDraw(L"設定", 280, CONFIG_Y, 32, c);

	int y = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case eMenu_Game://ゲーム選択中なら
		y = GAME_Y;    //ゲームの座標を格納
		break;
	case eMenu_Config://設定選択中なら
		y = CONFIG_Y;    //設定の座標を格納
		break;
	}
	Font::StrDraw(L"■", 250,y,32,c);
}