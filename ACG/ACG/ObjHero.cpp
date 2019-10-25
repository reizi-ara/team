//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjMenu.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define PLAYERLIFE 100

//�C�j�V�����C�Y
void CObjHero::Init()
{
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

	//�����蔻��p��HitBox���쐬
	//Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	if (Input::GetVKey('E'))
	{
		p_menuflag = true;
	}

	

	if (p_menuflag == false)
	{


		//Ct+R�V�[�����Z�b�g
		if (Input::GetVKey('R') && Input::GetVKey(VK_CONTROL))
		{
			//��O�ɏo���烊�X�^�[�g
			Scene::SetScene(new CSceneMain());
		}
		if (Input::GetVKey('T') && Input::GetVKey(VK_CONTROL))
		{//�_���[�W�t�^
			GiveDamageToPlayer(6.0f);

		}

		//HP0�ȉ��ŃQ�[���I�[�o�ֈڍs
		if (p_life <= 0)
		{
			Scene::SetScene(new CSceneGameOver());
		}

		//W�ŃW�����v
		if (Input::GetVKey('W'))
			if (m_hit_down)
				m_vy = -20;

		//�U�����I�u�W�F�N�g����
		//if (Input::GetVKey('1'))



		if (Input::GetVKey(VK_SHIFT))
		{//Shift�ő��x�A�b�v
			m_speed_power = 1.1f;
			m_ani_max_time = 2;
		}
		else
		{//�ʏ푬�x
			m_speed_power = 0.5f;
			m_ani_max_time = 4;
		}

		//�L�[�̓��͕���
		if (Input::GetVKey('S'))//���Ⴊ��
			m_pose = 2.0f;
		else
		{
			if (Input::GetVKey('D'))
			{
				m_vx += m_speed_power;
				m_posture = 1.0f;
				m_pose = 1.0f;
				m_ani_time += 1;
			}
			else if (Input::GetVKey('A'))
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
			m_ani_frame = 0;

		m_vx += -(m_vx*0.098);//���C
		m_vy += 9.8 / (16.0f);//���R�����^��

		//�����ړ��p�ɂ��Block����
		bool b;
		float pxx, pyy, r;
		CObjBlock*pbb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		if (pbb->GetScroll() > 0)
			pbb->SetScroll(0);

		//�ړ������Ƀ��C���΂�
		float vx;
		if (m_vx > 0)
			vx = 500;
		else
			vx = -500;

		//���C����
		b = pbb->HeroBlockCrossPoint(m_px - pbb->GetScroll() + 32, m_py + 32, vx, 0.0f, &pxx, &pyy, &r);

		if (b == true)
		{
			//��_�擾
			px = pxx + pbb->GetScroll();
			py = pyy;

			float aa = (m_px)-px;//A(��_����l���̈ʒu)�x�N�g��
			float bb = (m_px + m_vx) - px;//B(��_����l���̈ړ���ʒu)�x�N�g��

										  //��l���̕����̃I�t�Z�b�g
			if (vx > 0)
				px += -64;
			else
				px += +2;

			//A��B���t�������Ă�(��l�����ړ��悪�ǂ��z���Ă���)
			if (aa*bb < 0)
			{
				//�ړ��x�N�g����(��_����l���̈ʒu)�x�N�g���ɂ���
				m_vx = px - m_px;
			}

		}
		else
		{
			px = 0.0f;
			py = 0.0f;
		}

		//�u���b�N�Ƃ̓����蔻����s
		CObjBlock*pd = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pd->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

		/*	//���g��HitBox�������Ă���
			CHitBox*hit = Hits::GetHitBox(this);
			//�G�Ɠ������Ă��邩�m�F
			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{
				//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
				HIT_DATA**hit_data;
				hit_data = hit->SearchObjNameHit(OBJ_ENEMY);

				for (int i = 0; i < hit->GetCount(); i++)
				{
					//�G�Ƃ̍��E�ɓ���������
					float r = hit_data[i]->r;
					if ((r < 45 && r >= 0) || r > 315)
					{
						m_vx = -5.0f;
						p_life -= 10;
					}
					if (r > 135 && r < 225)
					{
						m_vx = +5.0f;
					}
					if (r >= 225 && r < 315)
					{
						//�G�̈ړ���������l���̈ʒu�ɉ��Z
						m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();

						CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
						//���ɂ̂��鏈��
						if (m_vy <- 1.0f)
						{
							//�W�����v���Ă���ꍇ�͉��L�̉e�����o�Ȃ��悤�ɂ���
						}
						else
						{
							//��l�����G�̓��ɏ���Ă���̂ŁAYvec��0�ɂ��ė��������Ȃ�
							//�܂��A�n�ʂɓ������Ă��锻��ɂ���
							m_vy = 0.0f;
							m_hit_down = true;
						}
					}
				}
			}*/


			//�\���ʒu�̍X�V
		m_px += m_vx;
		m_py += m_vy;

		/*	//HitBox�̈ʒu�ύX
			hit->SetPos(m_px, m_py);*/

	}
	else if (p_menuflag == true)
	{

	}
}

//�h���[
void CObjHero::Draw()
{
	int AniData[8] =
	{
		0,1,2,3,0,4,5,6
	}; 
	int AniData2[8] =
	{
		0,1,2,3,4,5,6,7
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	 //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f+m_pose * 64;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + src.m_left;
	src.m_bottom = 64.0f + src.m_top;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px;
	dst.m_right = (64 - 64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);




	//�̗̓o�[(�g)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f + src.m_left;
	src.m_bottom = 64.0f + src.m_top;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 16.0f;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);


	//�̗̓o�[
	if (p_life / p_maxlife > 0.5)
	{
		src.m_top = 0.0f;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}
	else if (p_life / p_maxlife <= 0.5&& p_life / p_maxlife > 0.25)
	{
		src.m_top = 64.0f;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}
	else if (p_life / p_maxlife <= 0.25)
	{
		src.m_top = 64.0f*2;
		src.m_left = 64.0f * 7;
		src.m_right = 64.0f + src.m_left;
		src.m_bottom = 64.0f + src.m_top;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 256.0f*(p_life/p_maxlife);
	dst.m_bottom = 16.0f;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
	wepon_have = 6;//���u��

	if (p_menuflag==false)
	{
		//�A�N�V����
		if (Input::GetVKey(VK_RETURN) && wepon_have > 0 && wepon_have != 4)
		{
			//�؂���ʒu�̐ݒ�
			src.m_top = 0.0f + (wepon_have % 4 + 4) * 64;
			src.m_left = 0.0f + AniData2[m_ani_frame] * 64;
			src.m_right = 64.0f + src.m_left;
			src.m_bottom = 64.0f + src.m_top;

			//�\���ʒu�̐ݒ�
			dst.m_top = 0.0f + m_py;
			dst.m_left = (64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
			dst.m_right = (64 - 64.0f*m_posture) + m_px + (m_posture * 2 - 1) * 48;
			dst.m_bottom = 64.0f + m_py;

			//�`��
			Draw::Draw(1, &src, &dst, c, 0.0f);
			wepon_attack = wepon_have;
		}
		else
		{
			wepon_attack = 0;
		}
	}
}