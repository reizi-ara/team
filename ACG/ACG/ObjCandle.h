#pragma once
#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjCandle : public CObj
{
public:
	CObjCandle(float x, float y);
	~CObjCandle() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	

private:
	float m_px;	//�ʒu
	float m_py;

	float m_ani_max_time;//�A�j���[�V��������Ԋu

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool isplayerhit;
	bool menu_flag;

	//���j���[
	int lavel_select;	//�㉺�{�^���Z���N�g�p
	bool lavel_button;//��񔭓��p
	bool lavel_button2;//��񔭓��p

	//���j���[�W�J���̑���t���O
	bool p_menuflag;
	bool p_menu_close;




	//�폜�p
	int destryNum;
	int MdestryNum;

	int time, times;
	int Unfold;

};

