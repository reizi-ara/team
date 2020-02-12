//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjEndingDoor.h"
#include "MacroManagement.h"

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjEndingDoor::CObjEndingDoor(float x, float y)
{
	m_px = x;	//�ʒu
	m_py = y;
}

//�C�j�V�����C�Y
void CObjEndingDoor::Init()
{
	hit_length = END_DOOR_HIT_LENGTH;

	size = 0;
	isplayerhit = false;

	DoorSystem = END_DOOR_SISTEM_CLOSE;

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
	if (isplayerhit == true && DoorSystem == END_DOOR_SISTEM_OPEN)
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
		src.m_top = END_DOOR_CLOSE_CUT_TOP;
		src.m_left = END_DOOR_CLOSE_CUT_LEFT;
		src.m_right = END_DOOR_CLOSE_CUT_RIGHT;
		src.m_bottom = END_DOOR_CLOSE_CUT_BOTTOM;

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top = END_DOOR_PUT_TOP + m_py - size;
		dst.m_left = END_DOOR_PUT_LEFT + m_px + block->GetScroll() - size;
		dst.m_right = END_DOOR_PUT_RIGHT + m_px + block->GetScroll() + size;
		dst.m_bottom = END_DOOR_PUT_BOTTOM + m_py + size;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	//�J��
	if (DoorSystem == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = END_DOOR_OPEN_CUT_TOP;
		src.m_left = END_DOOR_OPEN_CUT_LEFT;
		src.m_right = END_DOOR_OPEN_CUT_RIGHT;
		src.m_bottom = END_DOOR_OPEN_CUT_BOTTOM;

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top = -END_DOOR_PUT_TOP + m_py - size;
		dst.m_left = -END_DOOR_PUT_LEFT + m_px + block->GetScroll() - size;
		dst.m_right = END_DOOR_PUT_RIGHT + m_px + block->GetScroll() + size;
		dst.m_bottom = END_DOOR_PUT_BOTTOM + m_py + size;

		//�`��
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}


}