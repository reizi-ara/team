
//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjTuta.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjTuta::CObjTuta(float x, float y)
{
	m_px = x;	//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjTuta::Init()
{
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.0f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_move = true;

	//block�Ƃ̏Փˊm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	en_life = LIFE;
	//�����蔻��p��HitBox���쐬
	//Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);

	float p_x = 0;
	float p_y = 0;
}

//�A�N�V����
void CObjTuta::Action()
{

	//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�����Ԋu��



	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	/*	//HitBox�̈ʒu�̕ύX
		CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(m_px + block->GetScroll(), m_py);*/

		//�΃v���C���[�U��
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;
	//�^�_���[�W
	if (pl_x - sl <= en_x + 48.0f &&
		pl_x - sl >= en_x - 48.0f &&
		pl_y <= en_y + 48.0f &&
		pl_y >= en_y - 48.0f)
	{
		obj->GiveDamageToPlayer(0.1f);
	}

}

//�h���[
void CObjTuta::Draw()
{
	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px + block->GetScroll();
	dst.m_right = 64.0f + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}