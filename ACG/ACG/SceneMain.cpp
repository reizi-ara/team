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
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���j
	unique_ptr<wchar_t> p;//�X�e�[�W���|�C���^�[
	int size;			 //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"�}�b�v.csv", &size);//�O���f�[�^�ǂݍ���

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

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
	CObjBlock*objb = new CObjBlock(map);
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

}