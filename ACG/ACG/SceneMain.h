#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F���C��
class CSceneMain :public CScene
{
	public:
		CSceneMain();
		~CSceneMain();
		void InitScene();	//���������\�b�h
		void Scene();		//���s�����\�b�h

		int* GetM1() { return &map2[0][0]; }//�}�b�v���Q�𑗂�֐��H
	
	private:
		int m_chg;	//�}�b�v�`�F���W

		int map2[10][100];	//�}�b�v���Q
};