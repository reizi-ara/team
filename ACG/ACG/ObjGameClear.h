#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:��l��
class CObjGameClear : public CObj
{
public:
	CObjGameClear() {};
	~CObjGameClear() {};
	void Init();     //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();//�h���[

private:
	bool m_key_flag;
	bool ReturnKey_flag;
	int time;
	int Endnum;
	bool one_flag;
};

