//�g�p����w�b�_�[�t�@�C��

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameStart::Init()
{
	m_key_flag = false;
	lavel_select = 0;
	lavel_button = true;
	lavel_button2 = true;
}

//�A�N�V����
void CObjGameStart::Action()
{
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


	if (lavel_select > 2)
		lavel_select = 0;
	if (lavel_select < 0)
		lavel_select = 2;


	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (lavel_select == 0)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneMain());

			}

			else if (lavel_select == 1)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneGameOption());

			}
			else if (lavel_select == 2)
			{
				Scene::SetScene(nullptr);
			}
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameStart::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f*3;
	src.m_bottom = 64.0f*7;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�����\���p�o�[
	//�؂���ʒu�̐ݒ�
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�o�[�̈ʒu��ݒ肵�`��
	dst.m_top = 340.0f+lavel_select*50;
	dst.m_left = 300.0f;
	dst.m_right = 520.0f;
	dst.m_bottom = 380.0f+lavel_select*50;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	Font::StrDraw(L"�X�^�[�g", 340, 340, 32, c);
	Font::StrDraw(L"�I�v�V����", 320, 390, 32, c);
	Font::StrDraw(L"�I��", 365, 440, 32, c);
}