
//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMapChanger.h"

#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjMapChanger::CObjMapChanger(float x, float y,float t)
{
	m_px = x;	//�ʒu
	m_py = y;

	type = t;
}

//�C�j�V�����C�Y
void CObjMapChanger::Init()
{
	//CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	//destroy = sceneM->GetDS();

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

	m_OneChg = false;
	m_change = 1;

	mmmm = false;
}

//�A�N�V����
void CObjMapChanger::Action()
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
		pl_y >= en_y - hit_length
		&& m_OneChg == false)
	{//�ڐG��
		isplayerhit = true;
		m_OneChg = true;

		CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
		obj->SetX(2 * 64);
		obj->SetY(7 * 64);

		CObjBlock*objB = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		objB->SetScroll(0);
		objB->SetM_CHG(mmmm);
		objB->Set_ikkai(m_OneChg);//�u���b�N�̃}�b�v�A�h���X��true�ɂ��镔��

		CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
		sceneM->SetMMMMMM(m_change);
		sceneM->SetASDF(m_OneChg);

		

		this->SetStatus(false);

		

	}
	else
	{
		isplayerhit = false;

		m_OneChg = false;
	}
	//�����蔻�肱���܂�








}

//�h���[
void CObjMapChanger::Draw()
{
	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f*4;
	src.m_left = 64.0f*4;
	src.m_right = 64.0f*5;
	src.m_bottom = 64.0f*6;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = -64.0f*1 + m_py-size;
	dst.m_left = 0.0f + m_px + block->GetScroll() - size;
	dst.m_right = 64.0f + m_px + block->GetScroll()+size;
	dst.m_bottom = 64.0f + m_py + size;

	//�`��
	Draw::Draw(2, &src, &dst, c, 0.0f);
}