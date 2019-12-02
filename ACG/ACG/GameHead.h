#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_HERO,
	OBJ_BLOCK,
	OBJ_TIME,
	OBJ_ENEMY,

	OBJ_GAME_START,
	OBJ_GAME_OVER,
	OBJ_GAME_OPTION,

	OBJ_MENU,

	OBJ_TUTA,

	OBJ_MAPCHANGER,
	OBJ_MAPBACKER,

	OBJ_HAND,
	OBJ_THORN,
	OBJ_MESSAGE,
	OBJ_MESSAGE2,
	OBJ_BOSS
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjHero.h"
#include "ObjBlock.h"
#include "ObjTime.h"
#include "ObjEnemy.h"
#include "ObjGameStart.h"
#include "ObjGameOver.h"
#include "ObjGameOption.h"
#include "ObjTuta.h"
#include "ObjMapChanger.h"
#include "Objhand.h"
#include "ObjThorn.h"
#include "Objmessage.h"
#include "ObjMessage2.h"
#include "ObjMapBacker.h"
#include "ObjBoss.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include "SceneGameStart.h"
#include "SceneGameOver.h"
#include "SceneGameOption.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneGameStart
//-----------------------------------------------