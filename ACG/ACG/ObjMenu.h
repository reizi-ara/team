#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjMenu : public CObj
{
public:
	CObjMenu() {};
	~CObjMenu() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[

	int p_menuflag;		//���j���[�W�J�t���O
private:
	bool m_key_flag;//�L�[�t���O
	int lavel_select;//�I���������o�[�p
	bool lavel_button;//��񔭓��p
	bool lavel_button2;//��񔭓��p

};
