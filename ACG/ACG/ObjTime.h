#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C��
class CObjTime :public CObj
{
	public:
		CObjTime() {};
		~CObjTime() {};
		void Init();	//�C�j�V�����C�Y
		void Action();  //�A�N�V����
		void Draw();	//�h���[

		void SetTimeFlag(bool b) { m_flag_time = b; }
	private:
		int m_time;//����
		bool m_flag_time;//���Ԍv���X�^�[�g�t���O
};