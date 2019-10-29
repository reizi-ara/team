#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjMenu.h"
#include"ObjHero.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMenu::Init()
{
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//�A�N�V����
void CObjMenu::Action()
{
	if (p_menuflag == true) {

		p_itemflag = true;	   //�A�C�e���t���O
		p_equipflag= true;     //�����t���O
		p_charaflag= true;	   //�L�����N�^�[�t���O
		p_saveflag = true;	   //�Z�[�u�t���O


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


		//�G���^�[�L�[�������Ċe���j���[�Ɉڍs
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

//�h���[
void CObjMenu::Draw()
{
	if (p_menuflag == true)				//���j���[
	{

	}
}

