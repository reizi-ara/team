#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"
#include "MacroManagement.h"

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

		//�}�b�v�ύX�p�̊֐��Q
		int* GetM1() { return &map2[0][0]; }//�}�b�v���Q�𑗂�֐��H
		int GetDS() { return m_chg; }
		int GetONEs() { return One_chg; }

		//�}�b�v�ύX�p�����𑫂��֐�
		void SetMMMMMM (int a) { m_chg += a; }	
		//�}�b�v��ǂݍ��ރt���O
		void SetASDF(bool h) { OneRead = h; }	
	
		void MassageActivate() { map_score = m_chg; }
		bool CheckMassageActivate() { if (m_chg <= map_score) { return true; } else { return false; } }
	private:
		int m_chg;	//�}�b�v�`�F���W
		int One_chg;//��񏈗��p

		int map2[10][100];	//�}�b�v���Q

		bool OneRead;

		int map_score;

		unique_ptr<wchar_t> p[10];//�X�e�[�W���|�C���^�[

		void MapRead(int m_chg, int map[MAP_Y][MAP_X], unique_ptr<wchar_t>* p);

};

