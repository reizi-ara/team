//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEnemy.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "GameL/Audio.h"

#define MUTEKI 20;
#define DE_MAGE 10;//hidame
#define SARCH 64*4
#define SIZE 64*1

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y, float l, float a, float t)
{
	m_px = x;	//�ʒu
	m_py = y;
	en_life = l;
	atk = a * 2 / 3;
	type_n = t;
}

//�C�j�V�����C�Y
void CObjEnemy::Init()
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

	CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}
	Delete_flag = false;

	stopF = true;
	stopM = true;
}

//�A�N�V����
void CObjEnemy::Action()
{
	CObjMessage* objM = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	CObjCandle* objC = (CObjCandle*)Objs::GetObj(OBJ_CANDLE);
	if (objM == NULL || objC == NULL)
	{
		;
	}
	else
	{
		stopF = objM->GetStopE();
		stopM = objC->GetStopD();
	}

	if (stopF == true && stopM == true)
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
		m_vx += -(m_vx * 0.098);

		//���R�����^��
		m_vy += 1.8 / (4.0f);

		//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
		int d;
		//�u���b�N�Ƃ̓����蔻����s
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);

		if (type_n == 5)//item move
		{
			m_vx = 0;
			m_vy = 0;
		}
		//�\���ʒu�̍X�V
		m_px += m_vx;
		m_py += m_vy;

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


		//���W
		CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float pl_x = obj->GetX();
		float pl_y = obj->GetY();
		pl_x += 32.0f;
		pl_y += 32.0f;
		CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		float sl = block3->GetScroll();
		float en_x = m_px + 32.0f;
		float en_y = m_py + 32.0f;
		//�^�C�v�ɂ���ēG�̓�����ύX����Ƃ�
		if (type_n == 3 || type_n == 4)
		{
			time++;
			if (time % (80 + type_n * 20) == 0)
				m_vy = -(10 + (type_n - 2));
			if (time > (80 + type_n * 20))
				time = 0;
		}

		//�ڂ̋����̂Ƃ�
		if (type_n == 2) {
			time++;
			//�g���b�L�[�ɓ������
			if (time >= 120)
			{
				m_vx = 0;
			}
			if (time == 360)
			{
				time = 0;
			}
		}



		//�u���b�N�Փ˂Ō����ύX
		if (m_hit_left == true)
			m_move = true;
		if (m_hit_right == true)
			m_move = false;
		if (pl_x - sl <= en_x - 48.0f * 6)
			m_move = true;
		if (pl_x - sl >= en_x + 48.0f * 6)
			m_move = false;

		if (dir_act == m_move)
		{
		}
		else
		{
			dir_act = m_move;
			m_speed_power = 0.0f;
		}
		//�^�_���[�W
		if (pl_x - sl <= en_x + 48.0f &&
			pl_x - sl >= en_x - 48.0f &&
			pl_y <= en_y + 48.0f &&
			pl_y >= en_y - 48.0f )
		{
			if (type_n != 5)
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
			else if (type_n == 5)
			{
				obj->PlayerHealMini();
				en_life-=1;
			}


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
			pl_y >= en_y - 80.0f &&
			obj->Getattack() > 0 &&
			obj->Getattack() != 4 &&
			muteki_time <= 0)
		{
			muteki_time = MUTEKI;
			en_life -= DE_MAGE;

			CObjEffect* objef = new CObjEffect(m_px + block->GetScroll(), m_py, 2);
			Objs::InsertObj(objef, OBJ_THORN, 15);

			Audio::Start(7);//���ʉ�
		}

		//���ŃG�t�F�N�g
		if (en_life <= 0) {
			CObjEffect* objef = new CObjEffect(m_px + block->GetScroll(), m_py, 1);
			Objs::InsertObj(objef, OBJ_THORN, 15);
			if (type_n != 5) {
				CObjEnemy* obj25 = new CObjEnemy(m_px, m_py, atk*1.4, 10, 5);
				Objs::InsertObj(obj25, OBJ_ENEMY, 11);
			}

			Delete_flag = true;
		}
		//����
		if (Delete_flag == true)
		{

			//Delete_flag = false;
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



		//�폜�p����
		CSceneMain* sceneM = (CSceneMain*)Scene::GetScene();
		MdestryNum = sceneM->GetDS();

		if (destryNum != MdestryNum)
		{
			this->SetStatus(false);
		}



	}

}

//�h���[
void CObjEnemy::Draw()
{
	int AniData[8] =
	{
		0,1,2,3,4,5,6,7
	};
	//�`��J���[���
	float c[4] = { 0.75f,0.75f,0.75f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f + 64.0 * (type_n - 1);
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = src.m_top + 64.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//�`��
	if (type_n != 5)
	{
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	else
	{
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}