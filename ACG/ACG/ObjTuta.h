#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class CObjTuta : public CObj
{
	public:
		CObjTuta(float x,float y) ;
		~CObjTuta() {};
		void Init();		//�C�j�V�����C�Y
		void Action();		//�A�N�V����
		void Draw();		//�h���[
	private:
		float word_x; //��l����x���W
		float word_y; //��l����y���W

		int window_flag;

		float m_x;//���b�Z�[�W���W
		float m_y;
};
