#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjGameStart : public CObj
{
public:
	CObjGameStart() {};
	~CObjGameStart() {};
	void Init();		//�C�j�V�����C�Y
	void Action();		//�A�N�V����
	void Draw();		//�h���[
private:
	bool m_key_flag;//�L�[�t���O
	int lavel_select;//�I���������o�[�p
	bool lavel_button;//��񔭓��p
	bool lavel_button2;//��񔭓��p

};
