#pragma once
#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�V�[���F�Q�[���^�C�g��
class CObjMapBacker : public CObj
{
public:
	CObjMapBacker(float x, float y, float t);
	~CObjMapBacker() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	//int GetTT() { return m_change; }
	//int GetONE() { return m_OneChg; }

private:
	float m_px;	//�ʒu
	float m_py;

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

	//�}�b�v�ύX�p�ϐ��Q
	bool m_OneChg;
	bool mmmm;

	int m_change;


};
