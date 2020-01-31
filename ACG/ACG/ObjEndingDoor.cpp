//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEndingDoor.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjEndingDoor::CObjEndingDoor(float x, float y, float t)
{
	m_px = x;	//�ʒu
	m_py = y;

	type = t;
}

//�C�j�V�����C�Y
void CObjEndingDoor::Init()
{
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	//block�Ƃ̏Փˊm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	float p_x = 0;
	float p_y = 0;

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;

	DoorSystem = 1;

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
void CObjEndingDoor::Action()
{

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
	}
	else
	{
		isplayerhit = false;
	}
	//�����蔻�肱���܂�



	//�{�X�����Ńh�A�ɓ�����ƃN���A��ʂցB
	if (isplayerhit == true && DoorSystem == 2)
	{
		Scene::SetScene(new CSceneGameClear());
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
void CObjEndingDoor::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//����
	if (DoorSystem == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 128.0f;
		src.m_bottom = 128.0f;

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top = -64.0f + m_py - size;
		dst.m_left = -64.0f + m_px + block->GetScroll() - size;
		dst.m_right = 64.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = 64.0f + m_py + size;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	//�J��
	if (DoorSystem == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 128.0f * 2;
		src.m_bottom = 128.0f;

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top = -64.0f + m_py - size;
		dst.m_left = -64.0f + m_px + block->GetScroll() - size;
		dst.m_right = 64.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = 64.0f + m_py + size;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}


}