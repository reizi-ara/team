//STG�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
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

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGameStart*obj = new CObjGameStart(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAME_START, 10);//�^�C�g���I�u�W�F�N�g�o�^

}

//�Q�[���X�^�[�g���s�����\�b�h
void CSceneGameStart::Scene()
{

}