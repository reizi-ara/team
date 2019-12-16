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
CScenePrologue::CScenePrologue()

{

}

//�f�X�g���N�^
CScenePrologue::~CScenePrologue()
{

}

//�Q�[���I�[�o�[���������]�b�g
void CScenePrologue::InitScene()
{

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjPrologue*obj = new CObjPrologue();
	Objs::InsertObj(obj, OBJ_PROLOGUE, 10);

	//�w�i�ǂݍ���
	Draw::LoadImageW(L"splite3.png", 3, TEX_SIZE_1024);
	Draw::LoadImageW(L"splite2.png", 2, TEX_SIZE_512);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"s_end.wav", BACK_MUSIC);

	//SE
	//Audio::LoadAudio(1, L"s_select.wav", EFFECT);
	Audio::LoadAudio(2, L"s_ok.wav", EFFECT);

	//�{�����[��
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

}

//�Q�[���I�[�o�[���s�����]�b�g
void CScenePrologue::Scene()
{

}