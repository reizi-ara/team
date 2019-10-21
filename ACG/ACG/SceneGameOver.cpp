//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GamrL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()

{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������]�b�g
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"YOU LOSE");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver*obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);


}

//�Q�[�����C�����s�����]�b�g
void CSceneGameOver::Scene()
{

}