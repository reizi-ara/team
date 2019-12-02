//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBoss.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"

#define MUTEKI 20;
#define DE_MAGE 50;//hidame
#define SARCH 64*4
#define SIZE 64*1

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjBoss::CObjBoss(float x, float y, float l, float a, float t)
{
	m_px = x;	//�ʒu
	m_py = y;
	en_life = l;
	atk = a;
	type_n = t;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{

	awake = false;
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.0f;	//�ʏ푬�x
	m_ani_max_time = 8;		//�A�j���[�V�����Ԋu��

	m_move = true;
	dir_act = m_move;
	//block�Ƃ̏Փˊm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	float p_x = 0;
	float p_y = 0;
	time = 0;

	muteki_time = MUTEKI;

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
void CObjBoss::Action()
{
	//����
	if (m_py > 1000.0f)
	{
		this->SetStatus(false);
	}

	//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�����Ԋu��


	//����
	if (m_move == false)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 2;
	}

	else if (m_move == true)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 2;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 8)
	{
		m_ani_frame = 0;
	}



	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��
	m_vy += 1.8 / (4.0f);

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//�\���ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//���W
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;
	
	//�^�_���[�W
	if (pl_x - sl <= en_x + 48.0f&&
		pl_x - sl >= en_x - 48.0f &&
		pl_y <= en_y + 48.0f&&
		pl_y >= en_y - 48.0f&&
		m_vx != 0)
	{
		obj->GiveDamageToPlayer(atk);
		if (atk_kb == false)
		{
			if (pl_x - sl <= en_x)
			{
				obj->SetVX(-10);
			}

			else if (pl_x - sl > en_x)
			{
				obj->SetVX(10);
			}
		}
		atk_kb = true;



	}
	else
	{
		atk_kb = false;
	}



	muteki_time--;
	//��U��
	if (pl_x - sl <= en_x + SIZE - 40.0f * (obj->Getposture() * 2 - 1) &&
		pl_x - sl >= en_x - SIZE - 40.0f * (obj->Getposture() * 2 - 1) &&
		pl_y <= en_y + 80.0f &&
		pl_y >= en_y - 80.0f&&
		obj->Getattack() > 0 &&
		obj->Getattack() != 4 &&
		muteki_time <= 0)
	{

		muteki_time = MUTEKI;
		en_life -= DE_MAGE;
	}

	if (en_life <= 0)
	{

		this->SetStatus(false);
	}

	//�N��
	if (pl_x - sl <= en_x + 48.0f + SARCH &&
		pl_x - sl >= en_x - 48.0f - SARCH &&
		awake == false)
	{
		awake = true;
	}

	if (muteki_time > 0 && awake == true)
	{
		if (pl_x - sl <= en_x)
		{
			m_vx = +m_speed_power * 10;
			//obj->SetVX(10);
		}

		else if (pl_x - sl > en_x)
		{
			m_vx = -m_speed_power * 10;
			//obj->SetVX(-10);
		}
	}
	if (muteki_time == 0)
		m_speed_power = 0;

	if (muteki_time <= 0 && awake == true)
	{
		m_speed_power += 0.011f;
	}
	if (m_speed_power > 1.6f)
		m_speed_power = 1.6f;



	if (m_speed_power > 3.0f)
		m_speed_power = 3.0f;

	if (en_life <= 0)
	{
		Scene::SetScene(new CSceneGameClear());
	}




}

//�h���[
void CObjBoss::Draw()
{
	int AniData[8] =
	{
		0,1,2,3,4,5,6,7
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f + 64.0*(type_n - 1);
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 128.0f/2 + AniData[m_ani_frame] * 64;
	src.m_bottom = src.m_top + 256.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right = (64-64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f*4 + m_py;

	//�`��
	Draw::Draw(7, &src, &dst, c, 0.0f);
}