
//�g�p����w�b�_�[
#include "GameL/DrawFont.h"
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjCandle.h"
#include "main.h"
#include "GameL/Audio.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjCandle::CObjCandle(float x, float y)
{
	m_px = x;	//�ʒu
	m_py = y;

}

//�C�j�V�����C�Y
void CObjCandle::Init()
{
	m_ani_max_time = 4;		//�A�j���[�V�����Ԋu��

	hit_length = 64.0f;

	size = 0;
	isplayerhit = false;
	menu_flag = false;

	lavel_select = 0;


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
	time = 0;

	Unfold = 0;
}

//�A�N�V����
void CObjCandle::Action()
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

		if (Input::GetVKey('E'))
		{
			p_menuflag = true;

			obj->SetVX(0.0f);
			obj->SetVY(0.0f);
		}


	}
	else
	{
		isplayerhit = false;

	}

	if (isplayerhit && menu_flag == false)
	{
		if (Input::GetVKey(VK_RETURN) == true&&oneET_flag==true)
		{
			menu_flag = true;
			obj->SetMF(menu_flag);	//��l���̓��������p�̃t���O����
			oneET_flag = false;

			Audio::Stop(0);//���C��BGM�X�g�b�v
			Audio::Start(2);//���j���[BGM�X�^�[�g
		}
		else
		{
			oneET_flag = true;
		}
	}

	if (menu_flag == true)	//���j���[�e�X�g
	{
		if (Input::GetVKey('S'))
		{
			if (lavel_button == true)
			{
				lavel_select++;

				lavel_button = false;

				Audio::Start(9);//SE

			}
		}
		else
			lavel_button = true;

		if (Input::GetVKey('W'))
		{
			if (lavel_button2 == true)
			{
				lavel_select--;

				lavel_button2 = false;

				Audio::Start(9);//SE

			}
		}
		else
			lavel_button2 = true;


		if (lavel_select > 5)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 5;


		//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
		if (Input::GetVKey(VK_RETURN) == true && menu_flag )
		{
			if (oneET_flag)
			{
				if (lavel_select == 0)
				{
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;

				}

				else if (lavel_select == 1)
				{
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 2) {
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 3) {
					Audio::Start(8);//SE
					Scene::SetScene(new CSceneGameOver());
					m_key_flag = false;
					oneET_flag = false;
				}

				else if (lavel_select == 4)
				{
					Audio::Start(8);//SE
					Scene::SetScene(nullptr);
					oneET_flag = false;
				}

				else if (lavel_select == 5)
				{
					Audio::Start(8);//SE
					Audio::Stop(2);//���j���[BGM�X�g�b�v
					Audio::Start(0);//���C��BGM�X�^�[�g
					menu_flag = false;
					oneET_flag = false;

					lavel_select = 0;

					obj->SetMF(menu_flag);	//��l���̓��������p�̃t���O����

					

				}
			}

		}
		else
		{
			m_key_flag = true;
			oneET_flag = true;

		}

		obj->SetVX(0);
		obj->SetVY(0);
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
void CObjCandle::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	if (menu_flag == false)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f * 4;
		src.m_left = 64.0f * 5;
		src.m_right = 64.0f * 6;
		src.m_bottom = 64.0f * 5;
		//x��C�g����->o��p�g����
		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top = -16.0f + m_py - size;
		dst.m_left = 0.0f - 16.0f + m_px + block->GetScroll() - size;
		dst.m_right = 64.0f + 16.0f + m_px + block->GetScroll() + size;
		dst.m_bottom = 64.0f + m_py + size;

		//�`��
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (menu_flag)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 910.0f;
		src.m_bottom = 512.0f;

		//�w�i�̈ʒu��ݒ肵�`��
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//�����\���p�o�[
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f * 5;
		src.m_left = 64.0f * 5;
		src.m_right = 64.0f * 5 + 192;
		src.m_bottom = 64.0f * 5 + 64;

		//�o�[�̈ʒu��ݒ肵�`��
		dst.m_top = 100.0f + lavel_select * 50;
		dst.m_left = 250.0f;
		dst.m_right = 30.0f;
		dst.m_bottom = 140.0f + lavel_select * 50;
		Draw::Draw(2, &src, &dst, c, 0.0f);


		Font::StrDraw(L"�A�C�e��", 50, 100, 32, c);
		Font::StrDraw(L"����", 50, 150, 32, c);
		Font::StrDraw(L"�L�����N�^�[", 50, 200, 32, c);
		Font::StrDraw(L"�Z�[�u", 50, 250, 32, c);
		Font::StrDraw(L"�Q�[���I��", 50, 300, 32, c);
		Font::StrDraw(L"�߂�", 50, 350, 32, c);
	
	}
}