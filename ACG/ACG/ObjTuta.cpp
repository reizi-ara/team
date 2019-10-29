//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjTuta.h"
#include "main.h"
#include "GameL\DrawFont.h"
#include "GameL/DrawTexture.h"

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjTuta::CObjTuta(float x, float y)
{
	m_x = x;	//�ʒu
	m_y = y;
}

//�C�j�V�����C�Y
void CObjTuta::Init()
{

	float p_x = 0;
	float p_y = 0;
}

//�A�N�V����
void CObjTuta::Action()
{
	
	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//���b�Z�[�W�E�C���h�E
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	pl_x += 32.0f;
	pl_y += 32.0f;
	CObjBlock* block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	float sl = block3->GetScroll();
	float en_x = word_x + 32.0f;
	float en_y = word_y + 32.0f;
	if (pl_x - sl <= en_x + 48.0f + 16.0f&&
		pl_x - sl >= en_x - 48.0f - 16.0f &&
		pl_y <= en_y + 48.0f&&
		pl_y >= en_y - 48.0f&&
		Input::GetVKey('E'))
	{
		window_flag = 1;
	}
   
}

//�h���[
void CObjTuta::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 78.0f;
	src.m_bottom = 193.0f;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (window_flag == 1)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = (WINDOW_SIZE_H/3);
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Font::StrDraw(L"���b�Z�[�W�E�C���h�E�����", (WINDOW_SIZE_H/3)*1, (WINDOW_SIZE_W/3)*2, 32, c);
	}

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
