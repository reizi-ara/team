//�g�p����w�b�_�[
#include "GameL/DrawFont.h"
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "main.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define PLAYERLIFE 100
#define MUTEKITIME 120

//�C�j�V�����C�Y
void CObjHero::Init()
{
	cooltime = 12;
	attack_set = false;
	attack_flag = false;
	m_px = 70.0f;	//�ʒu
	m_py = 64.0f;
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; 
	m_pose = 1.0f;
	/*
	0:�ҋ@ 1:�ړ� 2:���Ⴊ�� 3:�W�����v 4:�U�� 5:�A�C�e��
	*/

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;	//�ʏ푬�x
	m_ani_max_time = 8;		//�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˊm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	flg_j = false;
	m_block_type = 0;
	p_maxlife=PLAYERLIFE;
	p_life = p_maxlife;

	//���j���[�W�J���̑���t���O
	p_menuflag = false;

	muteki_time = MUTEKITIME/2;
	overplayerlife = p_life;
	g_damage = 0;
	sohuran = 1;
	

	Message_flag = false;
	heal = 0.001f;
}

//�A�N�V����
void CObjHero::Action()
{

	//R�V�[�����Z�b�g
	if (Input::GetVKey('R')) {
		Scene::SetScene(new CSceneMain());
	}
	if (Input::GetVKey('T')) {
		p_life -= 2.0f;
	}
	if (Input::GetVKey('H')) {
		p_life += 2.0f;
	}

	cooltime--;


	

	

	

	if (p_menuflag == false)
	{
		

		//damage<-������
		if (g_damage > 0) {
			heal = 0.001f;
		}
		if (g_damage > 0 && muteki_time <= 0)
		{
			CObjEffect* objef = new CObjEffect(m_px, m_py, 2);
			Objs::InsertObj(objef, OBJ_THORN, 15);
			if (Input::GetVKey('S') && p_life / p_maxlife < 1.0) {
				p_life -= g_damage * 0.8;
				Audio::Start(7);//���ʉ�
			}
			else {
				p_life -= g_damage;
				Audio::Start(7);//���ʉ�
			}

			muteki_time = MUTEKITIME;
		}
		if (muteki_time > 0)
		{
			muteki_time--;
		}
		g_damage = 0;

		



		if (p_life > p_maxlife)
			p_life = p_maxlife;
		//HP0�ȉ��ŃQ�[���I�[�o�ֈڍs
		if (p_life <= 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}

		//W�ŃW�����v
		if (Input::GetVKey('W'))
			if (m_hit_down)
				m_vy = -15;


		if (Input::GetVKey(VK_SHIFT))
		{//Shift�ő��x�A�b�v
			m_speed_power = 1.4f;
			m_ani_max_time = 2;
		}
		else
		{//�ʏ푬�x
			m_speed_power = 0.8f;
			m_ani_max_time = 4;
		}

		//�L�[�̓��͕���
		if (Input::GetVKey('S')&&p_life/p_maxlife<1.0 )//���Ⴊ��
		{
			p_life += heal;
			if(heal>0.1)
				heal += 0.001;
			heal+=0.001;
			m_pose = 2.0f;
			m_ani_time += 1;
			if (muteki_time > 0)
				muteki_time += 0.5;
		}
		else
		{
			heal = 0.001f;
			if (Input::GetVKey('D'))//�E�Ɉړ�
			{
				
				
				m_vx += m_speed_power;
				m_posture = 1.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else if (Input::GetVKey('A'))//���Ɉړ�
			{
				

				m_vx -= m_speed_power;
				m_posture = 0.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else
			{
				//m_ani_frame = 1;//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[���ɂ���
				m_ani_time += 1;
				m_pose = 0.0f;
			}
		}

		
		



		//HP
		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}
		if (m_ani_frame == 8)
		{
			if (Input::GetVKey('A') || Input::GetVKey('D'))
			{
				Audio::Start(5);//���ʉ�
			}
			m_ani_frame = 0;
		}



		m_vx += -(m_vx*0.2);//���C
		m_vy += 9.8 / (16.0f);//���R�����^��
		
		//�u���b�N�Ƃ̓����蔻����s
		CObjBlock*pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pd->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

	}
	

	time_a--;
	//�f�o�b�N�p�}�b�v�ύX�R�}���h-----------------------------------------------------------
	if (Input::GetVKey('M'))
	{
		if (time_a<=0)
		{
			time_a = 60;
			CObjBlock*blockM = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
			blockM->SetM_CHG(1);
			blockM->Set_ikkai(true);

			CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
			sceneM->SetMMMMMM(1);
			sceneM->SetASDF(true);
		}
	}




	//�\���ʒu�̍X�V
	m_px += m_vx * sohuran;
	m_py += m_vy * sohuran;

	CObjMessage* obj = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);
	
}



//�h���[
void CObjHero::Draw()
{
	int AniData[8] =
	{
		0,1,2,4,3,2,4,5
	}; 
	int AniData3[8] =
	{
		0,2,4,6,4,5,6,7
	};
	
	//�`��J���[���
	float c[4] = { 0.75f,0.75f,0.75f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	if (p_menuflag == false)
	{

		if (m_pose == 2.0f)
		{
			src.m_top = 0.0f + m_pose * 64;
			src.m_left = 0.0f;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else
		{
			src.m_top = 0.0f + m_pose * 64;
			src.m_left = 0.0f + AniData[m_ani_frame] * 64;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		//�؂���ʒu�̐ݒ�


	   //�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py - 16.0f;
		dst.m_left = (64.0f*m_posture) + m_px;
		dst.m_right = (64 - 64.0f*m_posture) + m_px;
		dst.m_bottom = 64.0f + m_py;

		//�`��
		Draw::Draw(0, &src, &dst, c, 0.0f);




		//�̗̓o�[(�g)
		src.m_top = 128.0f;
		src.m_left = 256.0f;
		src.m_right = 256.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;

		//�\���ʒu�̐ݒ�
		dst.m_top = 8.0f;
		dst.m_left = 8.0f;
		dst.m_right = 256.0f + dst.m_left;
		dst.m_bottom = 64.0f + dst.m_top;

		//�`��
		Draw::Draw(0, &src, &dst, c, 0.0f);


		//�̗̓o�[
		if (p_life / p_maxlife > 0.5)//ao
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 3;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else if (p_life / p_maxlife <= 0.5&& p_life / p_maxlife > 0.2)//ki
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 2;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}
		else if (p_life / p_maxlife <= 0.2)//aka
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f * 1;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;
		}

		//�\���ʒu�̐ݒ�
		dst.m_top = 24.0f;
		dst.m_left = 16.0f;
		dst.m_right = (256.0f - 16.0f)*(p_life / p_maxlife) + dst.m_left;
		dst.m_bottom = 32.0f + dst.m_top;

		//�`��
		if (p_life > 0)
			Draw::Draw(0, &src, &dst, c, 0.0f);



		wepon_have = 5;//���u��


			//�A�N�V����
		if (Message_flag == false)
		{if(Input::GetVKey('S'))
		{ }
		else {
			if (Input::GetVKey(VK_RETURN))
			{
				if (attack_set == false && attack_flag == false&&cooltime<0)
				{
					cooltime = 40;
					if (m_posture == 1.0f)
						m_vx = 12;
					if (m_posture == 0.0f)
						m_vx = -12;
					m_ani_frame = 0;
					attack_set = true;
					attack_flag = true;

					Audio::Start(13);//���ʉ�
				}
			}
			else
			{
				attack_flag = false;
			}
		}
			if (attack_set == true && wepon_have > 0 && wepon_have != 4)
			{
				muteki_time++;
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f + wepon_have * 64;
				src.m_left = 0.0f + AniData3[m_ani_frame] * 64;
				src.m_right = 64.0f + src.m_left;
				src.m_bottom = 64.0f + src.m_top + 46.0f;

				//�\���ʒu�̐ݒ�
				dst.m_top = 0.0f + m_py;
				dst.m_left = (64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
				dst.m_right = (64 - 64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
				dst.m_bottom = 64.0f + m_py;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
				wepon_attack = wepon_have;
			}
			else
			{
				wepon_attack = 0;
			}
		}
		if (m_ani_frame > 2)
		{
			attack_set = false;
		}
	}


	
}