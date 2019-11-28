#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero :public CObj
{
	public:
		CObjHero() {};
		~CObjHero() {};
		void Init();	//�C�j�V�����C�Y
		void Action();  //�A�N�V����
		void Draw();	//�h���[

		float GetX() { return m_px; }
		float GetY() { return m_py; }
		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		int GetBT() { return m_block_type; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t) { m_block_type=t; }

		void SetUp(bool b) { m_hit_up = b; }
		void SetDown(bool b) { m_hit_down = b; }
		void SetLeft(bool b) { m_hit_left = b; }
		void SetRight(bool b) { m_hit_right = b; }

		void GiveDamageToPlayer(float damage) { g_damage= damage;  }

		int Getwepon() { return wepon_have; }
		int Getposture() { return m_posture; }
		int Getpose() { return m_pose; }
		int Getattack() { return wepon_attack; }
		void GiveSpeed(float speed) { sohuran = speed; }
		void SetMessageflag(bool att) { Message_flag = att; }

	private:
		float m_px;	//�ʒu
		float m_py;
		float m_vx; //�ړ��x�N�g��
		float m_vy;
		float m_posture; //�p��(���E)
		float m_pose;//���


		int m_ani_time;//�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;//�`��t���[��

		float m_speed_power;//�X�s�[�h�p���[
		float m_ani_max_time;//�A�j���[�V��������Ԋu

		//block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//����ł���block�̎�ނ��m�F�p
		int m_block_type;

		//�e�X�g�p
		float px, py;

		float p_life;
		float p_maxlife;

		bool flg_j;

		//04:�Ȃ��@123:����3�� 567:���3��
		int wepon_have;
		int wepon_attack;

		//���j���[
		int lavel_select;	//�㉺�{�^���Z���N�g�p
		bool lavel_button;//��񔭓��p
		bool lavel_button2;//��񔭓��p
		/*bool lavel_button3;//��񔭓��p
		bool lavel_button4;//��񔭓��p
		bool lavel_button5;//��񔭓��p*/
		bool m_key_flag;

		//���j���[�W�J���̑���t���O
		bool p_menuflag;
		bool p_menu_close;

		bool attack_set;
		bool attack_flag;

		float muteki_time;
		float overplayerlife;
		float g_damage;

		float sohuran;
		bool Message_flag;
};