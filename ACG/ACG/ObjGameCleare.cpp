//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameClear.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjGameClear::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
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
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float cR[4] = { 1.0f,1.0f,1.0f,1.0f };

	/*
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 512.0f;
	src.m_left = 0.0f;
	src.m_right = 910.0f;
	src.m_bottom = 1024.0f;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(3, &src, &dst, c, 0.0f);
	*/

	//Font::StrDraw(L"����Ă����͈̂�̉��������̂��낤", (WINDOW_SIZE_W / 2) -500, 150, 48, cR);
	//Font::StrDraw(L"��ł���B", (WINDOW_SIZE_W / 2) - 130, 225, 48, cR);
	//Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", (WINDOW_SIZE_W / 2) - 500, 350, 48, cR);

}
