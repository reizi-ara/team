#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G
class CObjEffect :public CObj
{
public:
	CObjEffect(float x, float y, float t);
	~CObjEffect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();	//�h���[


private:
	float m_px;
	float m_py;
	int type;
	int time;

};
