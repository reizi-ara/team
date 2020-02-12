//使用するヘッダー
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEndingDoor.h"
#include "MacroManagement.h"

//使用するネームスペースdayo
using namespace GameL;

CObjEndingDoor::CObjEndingDoor(float x, float y)
{
	m_px = x;	//位置
	m_py = y;
}

//イニシャライズ
void CObjEndingDoor::Init()
{
	hit_length = END_DOOR_HIT_LENGTH;

	size = 0;
	isplayerhit = false;

	DoorSystem = END_DOOR_SISTEM_CLOSE;

	//削除用
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}

}

//アクション
void CObjEndingDoor::Action()
{

	//当たり判定
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;

	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();

	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//接触時
		isplayerhit = true;
	}
	else
	{
		isplayerhit = false;
	}
	//当たり判定ここまで



	//ボス討伐でドアに当たるとクリア画面へ。
	if (isplayerhit == true && DoorSystem == END_DOOR_SISTEM_OPEN)
	{
		Scene::SetScene(new CSceneGameClear());
	}


		//削除用処理
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}


}

//ドロー
void CObjEndingDoor::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//閉じる
	if (DoorSystem == 1)
	{
		//切り取り位置の設定
		src.m_top = END_DOOR_CLOSE_CUT_TOP;
		src.m_left = END_DOOR_CLOSE_CUT_LEFT;
		src.m_right = END_DOOR_CLOSE_CUT_RIGHT;
		src.m_bottom = END_DOOR_CLOSE_CUT_BOTTOM;

		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top = END_DOOR_PUT_TOP + m_py - size;
		dst.m_left = END_DOOR_PUT_LEFT + m_px + block->GetScroll() - size;
		dst.m_right = END_DOOR_PUT_RIGHT + m_px + block->GetScroll() + size;
		dst.m_bottom = END_DOOR_PUT_BOTTOM + m_py + size;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	//開く
	if (DoorSystem == 2)
	{
		//切り取り位置の設定
		src.m_top = END_DOOR_OPEN_CUT_TOP;
		src.m_left = END_DOOR_OPEN_CUT_LEFT;
		src.m_right = END_DOOR_OPEN_CUT_RIGHT;
		src.m_bottom = END_DOOR_OPEN_CUT_BOTTOM;

		//ブロック情報を持ってくる
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//表示位置の設定
		dst.m_top = -END_DOOR_PUT_TOP + m_py - size;
		dst.m_left = -END_DOOR_PUT_LEFT + m_px + block->GetScroll() - size;
		dst.m_right = END_DOOR_PUT_RIGHT + m_px + block->GetScroll() + size;
		dst.m_bottom = END_DOOR_PUT_BOTTOM + m_py + size;

		//描画
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}


}