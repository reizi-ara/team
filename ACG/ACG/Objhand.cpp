
//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objhand.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjhand::CObjhand(float x, float y, float t,float d)
{
	m_px = x;	//�ʒu
	m_py = y;

	type = t;

	Damage = d;
}

//�C�j�V�����C�Y
void CObjhand::Init()
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

	float p_x = 0;
	float p_y = 0;

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;

	time = 0;

	//�폜�p
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}

}

//�A�N�V����
void CObjhand::Action()
{
	//�����蔻��
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;

	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length+16)
	{
		//�ڐG��
		isplayerhit = true;
	}
	else
	{
		isplayerhit = false;
	}

		

	//�����蔻�肱���܂�

	//��̃_���[�W
	if (isplayerhit == true)
	{
		obj->GiveDamageToPlayer(Damage);
		time++;
		if (time % 16==0)
			m_ani_frame += 1;
		if (m_ani_frame == 5)
		{
			m_ani_frame = 2;
		}
		isplayerhit = false;
	}






	//�폜�p����
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}


}

//�h���[
void CObjhand::Draw()
{

	int AniData[5] =
	{
		0,1,2,3,4
	};

	//�`��J���[���
	float c[4] = { 0.7f,0.7f,0.7f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;;
	src.m_bottom = 128.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py - size;
	dst.m_left = 0.0f + m_px + block->GetScroll() - size;
	dst.m_right = 64.0f + m_px + block->GetScroll() + size;
	dst.m_bottom = 64.0f + m_py + size;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}