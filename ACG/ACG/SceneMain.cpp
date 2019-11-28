//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGINF (0)

//Game�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h" 
#include "GameL\UserData.h" 
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	OneRead = false;
	m_chg = 0;

	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���j
	//unique_ptr<wchar_t> p;//�X�e�[�W���|�C���^�[
	int size;			 //�X�e�[�W���̑傫��
	p[0] = Save::ExternalDataOpen(L"map_0.csv", &size);//�O���f�[�^�ǂݍ���
	p[1] = Save::ExternalDataOpen(L"map_1.csv", &size);//�O���f�[�^�ǂݍ���
	p[2] = Save::ExternalDataOpen(L"map_2.csv", &size);//�O���f�[�^�ǂݍ���
	p[3] = Save::ExternalDataOpen(L"map_3.csv", &size);//�O���f�[�^�ǂݍ���
	p[4] = Save::ExternalDataOpen(L"map_4.csv", &size);//�O���f�[�^�ǂݍ���

	MapRead(m_chg, map2, p);//�}�b�v���[�h�֐��H

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���t�B�b�N�ǂݍ���

	Draw::LoadImageW(L"���b�Z�[�W�E�C���h�E.png", 3, TEX_SIZE_512);

	Draw::LoadImageW(L"splite0.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"splite1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"splite2.png", 2, TEX_SIZE_512);
	
	
	//910:512*
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite4.png", 4, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite5.png", 5, TEX_SIZE_1024);


	//��l���I�u�W�F�N�g�̍쐬
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock*objb = new CObjBlock(map2);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);


	

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�����ꂽ����.wav", BACK_MUSIC);

	//�{�����[��
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);
}

//���s�����\�b�h
void CSceneMain::Scene()
{


	CObjMapChanger*MapChanger = (CObjMapChanger*)Objs::GetObj(OBJ_MAPCHANGER);

	if (MapChanger == nullptr)
	{
		;
	}
	else
	{
		OneRead = MapChanger->GetONE();
	}

	if (m_chg == 0 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 1 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 2 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;
	}
	if (m_chg == 3 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}
	else if (m_chg == 4 && OneRead == true)
	{
		MapRead(m_chg, map2, p);
		OneRead = false;

	}

}

void CSceneMain::MapRead(int m_chg, int map[MAP_Y][MAP_X], unique_ptr<wchar_t>* p)
{
	int count = 1;
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			int w = 0;
			swscanf_s(&p[m_chg].get()[count], L"%d", &w);

			map[i][j] = w;
			count += 3;
		}
	}

}




