#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "SceneMain.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock :public CObj
{
	public:
		CObjBlock(int map[10][100]);
		~CObjBlock() {};
		void Init();	//�C�j�V�����C�Y
		void Action();  //�A�N�V����
		void Draw();	//�h���[


		void SetScroll(float s) { m_scroll = s; }
		float GetScroll() { return m_scroll; }

		//�}�b�v�p
		void SetM_CHG(bool mmmm) { m_chg = mmmm; }
		void Set_ikkai(bool oneIkkai) { ikkai = oneIkkai; }



		//�u���b�N�Ɠ����蔻��
		void BlockHit(
			float *x, float *y, bool scroll_on,
			bool*up, bool* down, bool* left, bool *right,
			float* vx, float*vy, int* bt
		);

		//���C���̏����u���b�N�̃}�b�v�Ɉڂ��ւ���֐�
		void Transfer(int map[MAP_Y][MAP_X], int * map2);
		

	private:
		void BlockDraw(float x, float y, RECT_F*dst, float c[],int s);
		int m_map[10][100];//�}�b�v���i���j

		float m_scroll; //���E�X�N���[���p

		//map�p
		int* map2;					//���C������}�b�v���̃A�h���X�����炤���
		int map[10][100];			//�����������ڂ��ւ���}�b�v���p�z��

		int m_chg;					//�}�b�v�ύX���邨�����Ƃ̕ϐ�

		bool mmmm;					//�A�N�V����������1���m_chgr�ڐG���̂�
		bool One_chg;				//�}�b�v��1�x�����ǂݍ��ރt���O
		bool ikkai;					//�}�b�v�̃A�h���X����񂾂������Ă���t���O

		//unique_ptr<wchar_t> p[5];

		

};