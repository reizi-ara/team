//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"
#include"main.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	m_key_flag = false;
	ReturnKey_flag = false;
	time=0;
	Endnum = 0;
	one_flag = true;
}
//�A�N�V����
void CObjGameClear::Action()
{
	time++;
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
	if (Endnum >= 4)
	{
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

	//���b�Z�[�W�֘A
	if (Input::GetVKey(VK_RETURN) == true&&time>=30)
	{
		one_flag = false;
		//ReturnKey_flag = true;
		Endnum += 1;		
		time = 0;
		Audio::Start(2);//���ʉ�
	}
}

//�h���[
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128*7;
	src.m_bottom = 1024/2;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(8, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top	= MESSAGE_CUT_TOP;
	src.m_left	= MESSAGE_CUT_LEFT;
	src.m_right = MESSAGE_CUT_RIGHT;
	src.m_bottom= MESSAGE_CUT_BOTTOM;

	//�w�i�̈ʒu��ݒ肵�`��
	dst.m_top = WINDOW_SIZE_H * 0.7;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(2, &src, &dst, c, 0.0f);
	if (Endnum == 0)
	{
		Font::StrDraw(L"�u������...�O�H�v",					MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"�u���Ƃ��O�ɏo��ꂽ�悤���B�v",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"�u�ق≻�����͉��������񂾂낤�v",	MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 1)
	{
		Font::StrDraw(L"������̊ق𒲂ׂ邽�߂Ɍ��������Ƃ���", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"���̊ق͐Ռ`���Ȃ�����",				 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"�X�̉\���R�̂悤�ɕ������Ă���",		 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"�݂�Ȃ��\�̂��Ƃ�Y��Ă���",			 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE4_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 2)
	{
		Font::StrDraw(L"�����A���̊ق��Ȃ��Ȃ����C�����Ȃ�����",	 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE1_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"�܂��ǂ����ɂ���悤�ȋC�����ĐS�z��������", MESSAGE_SENTENCE_W, MESSAGE_SENTENCE2_H, MESSAGE_SENTENCE_SIZE, c);
		Font::StrDraw(L"���̂����Y��Ă�����",						 MESSAGE_SENTENCE_W, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 3)
	{
		Font::StrDraw(L"�`END�`", (WINDOW_SIZE_W/2)-50, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
	else if (Endnum == 4)
	{
		Font::StrDraw(L"�˂��A����ق̉\���Ēm���Ă�H...", 400, MESSAGE_SENTENCE3_H, MESSAGE_SENTENCE_SIZE, c);
	}
}

