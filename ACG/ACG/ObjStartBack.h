#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�w�i
class CObjStartBack : public CObj
{
public:
	CObjStartBack() {};
	~CObjStartBack() {};
	void Init();     //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�w�i1�̈ʒu���
};
