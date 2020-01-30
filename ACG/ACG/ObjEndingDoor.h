#pragma once
#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjEndingDoor : public CObj
{
public:
	CObjEndingDoor(float x, float y, float t);
	~CObjEndingDoor() {};
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

	 //block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool isplayerhit;

	//�폜�p
	int destryNum;
	int MdestryNum;

};
