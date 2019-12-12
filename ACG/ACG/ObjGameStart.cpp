//�g�p����w�b�_�[�t�@�C��

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"
#include"main.h"
#include"GameL/Audio.h"

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
			Audio::Start(1);//���ʉ�

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
			Audio::Start(1);//���ʉ�

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
		Audio::Start(2);//���ʉ�
		if (m_key_flag == true)
		{
			if (lavel_select == 0)
			{
				m_key_flag = false;
				Scene::SetScene(new CScenePrologue());

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
	float b[4] = { 1.0f,1.0f,1.0f,0.5f };


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i
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




	//�X�^�[�g�{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 64.0f*4;
	src.m_right = 64.0f * 8;
	src.m_bottom = 64.0f;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H / 2;
	dst.m_left = WINDOW_SIZE_W / 2 - 150;
	dst.m_right = WINDOW_SIZE_W / 2 + 150;
	dst.m_bottom = WINDOW_SIZE_H / 2 + 80;
	if (lavel_select == 0)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);

	//�I�v�V�����{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f * 3;
	src.m_left = 0.0f;
	src.m_right = 64.0f * 4;
	src.m_bottom = 64.0f * 4;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H / 2 + 80;
	dst.m_left = WINDOW_SIZE_W / 2 - 150;
	dst.m_right = WINDOW_SIZE_W / 2 + 150;
	dst.m_bottom = WINDOW_SIZE_H / 2 + 160;
	if (lavel_select == 1)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);

	//�Q�[���I���{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f * 4;
	src.m_bottom = 64.0f;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H / 2 + 160;
	dst.m_left = WINDOW_SIZE_W / 2 - 150;
	dst.m_right = WINDOW_SIZE_W / 2 + 150;
	dst.m_bottom = WINDOW_SIZE_H / 2 + 240;
	if (lavel_select == 2)
		Draw::Draw(6, &src, &dst, c, 0.0f);
	else
		Draw::Draw(6, &src, &dst, b, 0.0f);


}