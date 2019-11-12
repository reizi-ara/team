//STG�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"	

//�R���X�g���N�^
CSceneGameStart::CSceneGameStart()
{

}

//�f�X�g���N�^
CSceneGameStart::~CSceneGameStart()
{

}

//�Q�[���X�^�[�g���������\�b�h
void CSceneGameStart::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���ڂ���̊�");

	//�w�i�ǂݍ���
	Draw::LoadImageW(L"splite3.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);

	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGameStart*obj = new CObjGameStart(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAME_START, 10);//�^�C�g���I�u�W�F�N�g�o�^


	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�^�C�g��.wav", BACK_MUSIC);

	//�{�����[��
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

}

//�Q�[���X�^�[�g���s�����\�b�h
void CSceneGameStart::Scene()
{

}