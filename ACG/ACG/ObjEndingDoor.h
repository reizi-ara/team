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
	CObjEndingDoor(float x, float y);
	~CObjEndingDoor() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[

	void DoorSystemPG(int dead) { DoorSystem = dead; }

private:
	float m_px;	//�ʒu
	float m_py;

	int DoorSystem;//�h�A�J�p�ϐ�:2�J���A1����

	int hit_length;//���S����̋���

	int size;
	bool isplayerhit;

	//�폜�p
	int destryNum;	//�������̃}�b�v�ԍ�
	int MdestryNum;	//���݂̃}�b�v�ԍ�

};
