#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G
class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y, float l, float a);
	~CObjBoss() {};
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


	//�ړ��̌�������
	bool m_move;

	float en_life;
	float atk;

	int muteki_time;

	bool awake;

	bool dir_act;//�����]���m�F

	int destryNum;//�폜�p
	int MdestryNum;

	bool atk_kb;


	int time_1;
};

