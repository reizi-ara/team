//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjPrologue.h"
#include"main.h"
#include"GameL/Audio.h"

#include "MacroManagement.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPrologue::Init()
{
	m_key_flag = false;
	ReturnKey_flag = false;
	time = TIME_INI;
	Endnum = 0;
	one_flag = true;
}
//�A�N�V����
void CObjPrologue::Action()
{
	time++;
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
	if (Endnum >= 2)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				m_key_flag = false;
				Scene::SetScene(new CSceneMain());

			}
		}
		else
		{
			m_key_flag = true;
		}
	}

	//���b�Z�[�W�֘A
	if (Input::GetVKey(VK_RETURN) == true && time >= TIME_DELAY && Endnum < 3)
	{
		one_flag = false;
		Endnum += 1;
		time = TIME_INI;
		Audio::Start(2);//���ʉ�
	}
}

//�h���[
void CObjPrologue::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128 * 7;
	src.m_bottom = 1024 / 2;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(8, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f * 6;
	src.m_left = 64.0f * 0;
	src.m_right = 64.0f * 8;
	src.m_bottom = 64.0f * 8;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H * 0.7;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);
	if (Endnum == 0)
	{
		Font::StrDraw(L"����s���̊X�ɍŋߕs�v�c�Ȃ��Ƃ��N�������B", 150, 550, 25, c);
		Font::StrDraw(L"�Ȃ����}�ɌÂт��m�ق������Ă����̂��A", 150, 575, 25, c);
		Font::StrDraw(L"����Ȃ��Ƃ����������񂾂���X�ł́A", 150, 600, 25, c);
		//Font::StrDraw(L"�����������\������Ă����B", 150, 625, 25, c);
		//Font::StrDraw(L"", 150, 650, 25, c);

	
	}
	else if (Endnum == 1)
	{
		Font::StrDraw(L"�u���̗m�قɂ͉��������o��v�Ƃ�", 150, 550, 25, c);
		Font::StrDraw(L"�u���̗m�ق̒��͎��ً͈�Ԃ��v�Ƃ�", 150, 575, 25, c);
		Font::StrDraw(L"����ȉ\������Ă��邹���ŗm�قɖK���l�͑��������B", 150, 650, 25, c);

	}
	else if (Endnum == 2)
	{
		//Font::StrDraw(L"", 150, 550, 25, c);
		Font::StrDraw(L"�����Ėl���c���̒��̈�l�������B", 250, 600, 25, c);
		//Font::StrDraw(L"", 150, 650, 25, c);
		//Font::StrDraw(L"���ҁF�c��", 750, 675, 20, c);
	}
}

