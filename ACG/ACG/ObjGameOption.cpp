//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"main.h"
#include"ObjGameStart.h"

#define SERECT_MIN_OP (0)
#define SERECT_MAX_OP (0)

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOption::Init()
{
	m_key_flag = false;
	lavel_option = true;
	lavel_option2 = true;
	lavel_select_op = SERECT_MIN_OP;
}

//�A�N�V����
void CObjGameOption::Action()
{
	if (Input::GetVKey('S'))
	{
		if (lavel_option == true)
		{
			lavel_select_op++;

			lavel_option = false;

		}
	}
	else
		lavel_option = true;

	if (Input::GetVKey('W'))
	{
		if (lavel_option2 == true)
		{
			lavel_select_op--;

			lavel_option2 = false;

		}
	}
	else
		lavel_option2 = true;


	if (lavel_select_op > SERECT_MAX_OP)
		lavel_select_op = SERECT_MIN_OP;
	if (lavel_select_op < SERECT_MIN_OP)
		lavel_select_op = SERECT_MAX_OP;


	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			m_key_flag = false;
			Scene::SetScene(new CSceneGameStart());
			
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOption::Draw()
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
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);



	//�߂�{�^��
	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f * 4;
	src.m_bottom = 64.0f * 2;

	//�o�[�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H / 2;
	dst.m_left = WINDOW_SIZE_W / 2 - 150;
	dst.m_right = WINDOW_SIZE_W / 2 + 150;
	dst.m_bottom = WINDOW_SIZE_H / 2 + 80;
	Draw::Draw(6, &src, &dst, c, 0.0f);


}