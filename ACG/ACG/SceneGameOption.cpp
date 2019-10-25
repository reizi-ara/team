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
CSceneGameOption::CSceneGameOption()
{

}

//�f�X�g���N�^
CSceneGameOption::~CSceneGameOption()
{

}

//�Q�[���X�^�[�g���������\�b�h
void CSceneGameOption::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"�߂�");
	Font::SetStrTex(L"�܂�����Ă܂���B");
	Font::SetStrTex(L"���߂�Ȃ���");

	//�w�i�ǂݍ���
	Draw::LoadImageW(L"�X�^�[�g��ʉ��u��.jpg", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);

	//�I�v�V�����I�u�W�F�N�g�쐬
	CObjGameOption*obj = new CObjGameOption(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAME_OPTION, 10);//�^�C�g���I�u�W�F�N�g�o�^

}

//�Q�[���X�^�[�g���s�����\�b�h
void CSceneGameOption::Scene()
{

}