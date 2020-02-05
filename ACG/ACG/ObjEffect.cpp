#include "GameL\DrawTexTure.h"
#include "GameHead.h"
#include"ObjEffect.h"

#include "MacroManagement.h"
using namespace GameL;

CObjEffect::CObjEffect(float x, float y, float t)
{
	m_px = x;	//�ʒu
	m_py = y;
	type = t;
}

//�C�j�V�����C�Y
void CObjEffect::Init()
{
	time = TIME_INI;
}

//�A�N�V����
void CObjEffect::Action()
{
	time++;
	if (time > 8)
		this->SetStatus(0);
}

//�h���[
void CObjEffect::Draw()
{
	int AniData[8] =
	{
		0,0,1,1,2,2,3,3
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f + 128.0 * (type +1);
	src.m_left = 0.0f + AniData[time] * 128;
	src.m_right = src.m_left+128;
	src.m_bottom = src.m_top + 128;

	//�\���ʒu�̐ݒ�
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}