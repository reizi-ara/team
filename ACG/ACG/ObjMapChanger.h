#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�V�[���F�Q�[���^�C�g��
class CObjMapChanger : public CObj
{
public:
	CObjMapChanger(float x, float y, float t);
	~CObjMapChanger() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	int GetTT() { return m_change; }
	int GetONE() { return m_OneChg; }

	//void MapChanger(int m, int m_map[MAP_Y][MAP_X], unique_ptr<wchar_t>* a);

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

	bool m_OneChg;

	int m_change;



};
