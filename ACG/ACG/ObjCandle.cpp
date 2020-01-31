
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
	hit_length = 64.0f;
	size = 0;

	isplayerhit = false;
	menu_flag = false;
	p_menuflag = false;

	p_menu_close = false;

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
	stopD = true;
}

//�A�N�V����
void CObjCandle::Action()
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
			obj->PlayerHeal();
		
		if (Input::GetVKey(VK_RETURN) == true && menu_flag == false)
		{
			menu_flag = true;
			obj->SetMF(menu_flag);	//��l���̓��������p�̃t���O����			

			Audio::Stop(0);//���C��BGM�X�g�b�v
			Audio::Start(2);//���j���[BGM�X�^�[�g
			stopD = false;
			
		}
		

	}
	else
	{
		isplayerhit = false;

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


		if (lavel_select > 3)
			lavel_select = 0;
		if (lavel_select < 0)
			lavel_select = 3;


		//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
		if (menu_flag)
		{
			time++;
			if (time >= 30)
			{
				if (Input::GetVKey(VK_RETURN))
				{
					p_menu_close = true;
				}
				else if(p_menu_close)
				{
					if (lavel_select == 0) {
						p_menu_close = false;
						Audio::Start(8);//SE
					}
					else if (lavel_select == 1) {
						p_menu_close = false;
						Audio::Start(8);//SE
						//Scene::SetScene(new CSceneGameOver());
					}
					else if (lavel_select == 2) {
						p_menu_close = false;
						Audio::Start(8);//SE
						Scene::SetScene(nullptr);
					}
					else if (lavel_select == 3) {
						p_menu_close = false;
						time = 0;
						Audio::Start(8);//SE
						Audio::Stop(2);//���j���[BGM�X�g�b�v
						Audio::Start(0);//���C��BGM�X�^�[�g
						stopD = true;


						lavel_select = 0;

						menu_flag = false;
						obj->SetMF(menu_flag);	//��l���̓��������p�̃t���O����
						

					}
				}
				


			}

		}
		obj->SetVX(0);
		obj->SetVY(0);

	}
	else
	{

	}

	//�폜�p����
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();

	if (destryNum != MdestryNum){
		this->SetStatus(false);
	}




}

//�h���[
void CObjCandle::Draw()
{

	float c[4] = { 0.8f,0.8f,0.8f,1.0f };

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
		//Draw::Draw(2, &src, &dst, c, 0.0f); 
		Font::StrDraw(L"��", 220, 90 + lavel_select * 50,50,c);


		Font::StrDraw(L"�N���W�b�g", 50, 100, 32, c);
		Font::StrDraw(L"�I�v�V����", 50, 150, 32, c);
		Font::StrDraw(L"�Q�[���I��", 50, 200, 32, c);
		Font::StrDraw(L"�߂�", 50, 250, 32, c);
	

		if (lavel_select == 0) {
			Font::StrDraw(L"�N���W�b�g�ꗗ", 690, 40, 32, c);
			Font::StrDraw(L"�����", 350, 70, 20, c);
			Font::StrDraw(L"�����f�B���N�^�[:�i�� ���", 350, 100, 27, c);
			Font::StrDraw(L"�Q�[���v�����i�[:�� ���m", 350, 135, 27, c);
			Font::StrDraw(L"�Q�[���v���O���}�[:�r�� �C�^", 350, 170, 27, c);
			Font::StrDraw(L"�Q�[���f�U�C�i�[:�c�� �r�K", 350, 205, 27, c);
			Font::StrDraw(L"�A�V�X�^���g:���c �I��", 350, 240, 27, c);
			Font::StrDraw(L"BGM�E���ʉ�", 350, 300, 20, c);
			Font::StrDraw(L"���ʉ����{��https://soundeffect-lab.info/", 350, 330, 27, c);
			Font::StrDraw(L"Wingless Seraph��https://wingless-seraph.net/", 350, 365, 27, c);
			Font::StrDraw(L"�������ʉ���https://taira-komori.jpn.org/index.html", 350, 400, 27, c);
			Font::StrDraw(L"��������https://maoudamashii.jokersounds.com/", 350, 435, 27, c);
			Font::StrDraw(L"���ʉ����T��https://sounddictionary.info/", 350, 470, 27, c);
			Font::StrDraw(L"G-Sound��https://g-miya.net/index.html", 350, 505, 27, c);
			Font::StrDraw(L"���炰�H����http://www.kurage-kosho.info/index.html", 350, 540, 27, c);
			Font::StrDraw(L"�m�X�^���W�A��http://nostalgiamusic.info/index.html", 350, 575, 27, c);
		}
		if (lavel_select == 1) {
			Font::StrDraw(L" �I�v�V����", 690, 40, 32, c);
		}
		if (lavel_select == 2) {
			Font::StrDraw(L" �Q�[���I��", 690, 40, 32, c);
			Font::StrDraw(L"�Q�[�����I�����ă^�u����܂��B", 450, 300, 45, c);
		}
	}
}