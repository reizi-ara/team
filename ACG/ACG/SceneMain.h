#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define MAP_X (100)
#define MAP_Y (10)

//�V�[���F���C��
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//���������\�b�h
		void Scene();		//���s�����\�b�h

		int* GetM1() { return &map2[0][0]; }//�}�b�v���Q�𑗂�֐��H

		int GetDS() { return m_chg; }

		int GetONEs() { return One_chg; }
	
	private:
		int m_chg;	//�}�b�v�`�F���W
		int One_chg;//��񏈗��p

		int map2[10][100];	//�}�b�v���Q



		unique_ptr<wchar_t> p[5];//�X�e�[�W���|�C���^�[

};
