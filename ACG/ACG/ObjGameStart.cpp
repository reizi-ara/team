//�g�p����w�b�_�[�t�@�C��

#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameStart::Init()
{

}
//�A�N�V����
void CObjGameStart::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
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
	src.m_right = 960.0f;
	src.m_bottom = 450.0f;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	Font::StrDraw(L"���ڂ���̊�", 240, 220, 32, c);

	Font::StrDraw(L"GameStart : PushEnterKey", 210, 380, 32, c);
}

