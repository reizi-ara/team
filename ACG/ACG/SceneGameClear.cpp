//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GamrL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameClear::CSceneGameClear()

{

}

//�f�X�g���N�^
CSceneGameClear::~CSceneGameClear()
{

}

//�Q�[���I�[�o�[���������]�b�g
void CSceneGameClear::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	//Font::SetStrTex(L"��������Ă����͉̂��������̂��낤");
	//Font::SetStrTex(L"��ł���");
	//Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameClear*obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

	//�w�i�ǂݍ���
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�J.wav", BACK_MUSIC);

	//�{�����[��
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

}

//�Q�[���I�[�o�[���s�����]�b�g
void CSceneGameClear::Scene()
{

}