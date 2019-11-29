
//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objmessage.h"
#include "main.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjMessage::CObjMessage(float x, float y, float t)
{
	m_px = x;	//�ʒu
	m_py = y;

	type = t;
}

//�C�j�V�����C�Y
void CObjMessage::Init()
{
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.0f;	//�ʏ푬�x
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	m_move = true;

	//block�Ƃ̏Փˊm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	en_life = LIFE;

	float p_x = 0;
	float p_y = 0;

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;
	Message_flag = false;

	//�폜�p
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr)
	{
		;
	}
	else
	{
		destryNum = sceneM->GetDS();

	}

}

//�A�N�V����
void CObjMessage::Action()
{

	//�ʏ푬�x
	m_ani_max_time = 8;//�A�j���[�V�����Ԋu��



	//�����蔻��
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;

	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;

	if (pl_x - sl <= en_x + hit_length &&
		pl_x - sl >= en_x - hit_length &&
		pl_y <= en_y + hit_length &&
		pl_y >= en_y - hit_length)
	{//�ڐG��
		isplayerhit = true;
		obj->SetMessageflag(isplayerhit);
	}
	else
	{
		isplayerhit = false;
		obj->SetMessageflag(isplayerhit);
	}
	//�����蔻�肱���܂�

	if (isplayerhit == true)
	{
		if (Input::GetVKey('Q') == true)
		{
			CObjMessage2* obje = new CObjMessage2(64.0f, 64.0f, 0);
			Objs::InsertObj(obje, OBJ_MESSAGE2, 15);
			obj->SetVX(0.0f);
			obj->SetVY(0.0f);
		}
		
	}

	if (Message_flag == true)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			Message_flag = false;

		}
	}









	//�폜�p����
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum)
	{
		this->SetStatus(false);
	}




}

//�h���[
void CObjMessage::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f*4;
	src.m_left = 64.0f*2;
	src.m_right = 64.0f*4;
	src.m_bottom = 64.0f*6;
	//x��C�g����->o��p�g����
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py - size;
	dst.m_left = 0.0f + m_px + block->GetScroll() - size-32;
	dst.m_right = 64.0f + m_px + block->GetScroll() + size+32;
	dst.m_bottom = 64.0f + m_py + size;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);


}