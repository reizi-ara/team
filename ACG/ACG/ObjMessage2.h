#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjMessage2 : public CObj
{
public:
	CObjMessage2(float x, float y, float t);
	~CObjMessage2() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	float GetVx() { return m_vx; }

private:
	float m_px;	//�ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��

	float p_x;
	float p_y;

	int m_ani_time;//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������Ԋu

	 //block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�ړ��̌�������
	bool m_move;

	float en_life;

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool book_isplayerhit;
	bool Message_flag;
};

