#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjMenu.h"
#include"ObjHero.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMenu::Init()
{
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//アクション
void CObjMenu::Action()
{
	if (p_menuflag == true) {

		p_itemflag = true;	   //アイテムフラグ
		p_equipflag= true;     //装備フラグ
		p_charaflag= true;	   //キャラクターフラグ
		p_saveflag = true;	   //セーブフラグ


		if (Input::GetVKey('S'))
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

			}
		}
		else
			lavel_button = true;

		if (Input::GetVKey('W'))
		{
			if (lavel_button2 == true)
			{
				lavel_select--;

				lavel_button2 = false;

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > 5)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 5;


		//エンターキーを押して各メニューに移行
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (lavel_select == 0)
			{
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 1)
			{
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 2) {
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 3) {
				Scene::SetScene(new CSceneGameOver());
				m_key_flag = false;
			}

			else if (lavel_select == 4)
			{
				Scene::SetScene(nullptr);
			}

			else if (lavel_select == 5)
			{
				p_menuflag = false;
			}

		}
		else
		{
			m_key_flag = true;
		}
	}
}

//ドロー
void CObjMenu::Draw()
{
	if (p_menuflag == true)				//メニュー
	{

	}
}

