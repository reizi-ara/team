//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"ObjStartBack.h"



//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStartBack::Init()
{
	m_x = 0.0f;
}

//�A�N�V����
void CObjStartBack::Action()
{
	/*
	//�w�i1�̓���
	m_x1 -= 10.0f;
	if (m_x1 < -800.0f)
		m_x1 = 800;

	//�w�i2�̓���
	m_x2 -= 10.0f;
	if (m_x2 < -800.0f)
		m_x2 = 800;
	*/
}
//�h���[
void CObjStartBack::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	/*
	//�w�i2�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	*/

	//1�Ԗڂɓo�^�����O���t�B�b�N��src'dst'c�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

