/*
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjMenu.h"
#include"ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMessageBox::Init()
{
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//�A�N�V����
void CObjMessageBox::Action()
{
	 {

		if (Input::GetVKey(VK_RETURN)==true)
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

			}
		}

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > 4)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 4;

}
		

//�h���[
void CObjMessageBox::Draw()
{
	if (p_menuflag == true)
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
		Draw::Draw(2, &src, &dst, c, 0.0f);

		//�����\���p�o�[
		//�؂���ʒu�̐ݒ�
		src.m_top = 256.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		


		Font::StrDraw(L"�A�C�e��", 340, 340, 32, c);
		Font::StrDraw(L"����", 320, 390, 32, c);
		Font::StrDraw(L"�L�����N�^�[", 365, 440, 32, c);
		Font::StrDraw(L"�Z�[�u", 50, 490, 32, c);
		Font::StrDraw(L"�Q�[���I��", 50, 540, 32, c);
	}
}


*/