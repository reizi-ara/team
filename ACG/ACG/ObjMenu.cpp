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


		//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
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
		float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 960.0f;
		src.m_bottom = 450.0f;

		//�w�i�̈ʒu��ݒ肵�`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		//�����\���p�o�[
		//�؂���ʒu�̐ݒ�
		src.m_top = 256.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		//�o�[�̈ʒu��ݒ肵�`��
		dst.m_top = 100.0f + lavel_select * 50;
		dst.m_left = 250.0f;
		dst.m_right = 30.0f;
		dst.m_bottom = 140.0f + lavel_select * 50;
		Draw::Draw(0, &src, &dst, c, 0.0f);


		Font::StrDraw(L"�A�C�e��", 50, 100, 32, c);
		Font::StrDraw(L"����", 50, 150, 32, c);
		Font::StrDraw(L"�L�����N�^�[", 50, 200, 32, c);
		Font::StrDraw(L"�Z�[�u", 50, 250, 32, c);
		Font::StrDraw(L"�Q�[���I��", 50, 300, 32, c);
		Font::StrDraw(L"�߂�", 50, 350, 32, c);
	}
}

