
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
#include "MacroManagement.h"

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

	lavel_select = LAVEL_TOP;

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
	time = TIME_INI;

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


		if (lavel_select > LAVEL_BOT_MENU)
			lavel_select = LAVEL_TOP;
		if (lavel_select < LAVEL_TOP)
			lavel_select = LAVEL_BOT_MENU;


		//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉڍs����
		if (menu_flag)
		{
			time++;
			if (time >= TIME_DELAY)
			{
				if (Input::GetVKey(VK_RETURN))
				{
					p_menu_close = true;
				}
				else if(p_menu_close)
				{
					if (lavel_select == LAVEL_TOP) {
						p_menu_close = false;
						Audio::Start(8);//SE
					}
					else if (lavel_select == LAVEL_MID_MENU) {
						p_menu_close = false;
						Audio::Start(8);//SE
						Scene::SetScene(new CSceneGameStart());
					}
					else if (lavel_select == LAVEL_BOT_MENU) {
						p_menu_close = false;
						time = 0;
						Audio::Start(8);//SE
						Audio::Stop(2);//���j���[BGM�X�g�b�v
						Audio::Start(0);//���C��BGM�X�^�[�g
						stopD = true;


						lavel_select = LAVEL_TOP;

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
		src.m_top	= CANDLE_CUT_TOP;
		src.m_left	= CANDLE_CUT_LEFT;
		src.m_right = CANDLE_CUT_RIGHT;
		src.m_bottom= CANDLE_CUT_BOTTOM;
		//x��C�g����->o��p�g����
		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//�\���ʒu�̐ݒ�
		dst.m_top	= CANDLE_PUT_TOP	+ m_py - size;
		dst.m_left	= CANDLE_PUT_LEFT	+ m_px + block->GetScroll() - size;
		dst.m_right = CANDLE_PUT_RIGHT	+ m_px + block->GetScroll() + size;
		dst.m_bottom= CANDLE_PUT_BOTTOM + m_py + size;

		//�`��
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (menu_flag)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top	= MENU_BACK_CUT_TOP;
		src.m_left	= MENU_BACK_CUT_LEFT;
		src.m_right = MENU_BACK_CUT_RIGHT;
		src.m_bottom= MENU_BACK_CUT_BOTTOM;

		//�w�i�̈ʒu��ݒ肵�`��
		dst.m_top	= MENU_BACK_PUT_TOP;
		dst.m_left	= MENU_BACK_PUT_LEFT;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom= WINDOW_SIZE_H;
		Draw::Draw(4, &src, &dst, c, 0.0f);

		//�����\���p�o�[
		//�؂���ʒu�̐ݒ�
		/*src.m_top	= 64.0f * 5;
		src.m_left	= 64.0f * 5;
		src.m_right = 64.0f * 5 + 192;
		src.m_bottom= 64.0f * 5 + 64;

		//�o�[�̈ʒu��ݒ肵�`��
		dst.m_top	= MENU_BAR_PUT_TOP + lavel_select * 188;
		dst.m_left	= MENU_BAR_PUT_LEFT;
		dst.m_right = MENU_BAR_PUT_RIGHT;
		dst.m_bottom= MENU_BAR_PUT_BOTTOM + lavel_select * 50;
		Draw::Draw(2, &src, &dst, c, 0.0f); */

		//���j���[�o�[
		Font::StrDraw(L"��", MENU_BAR_W, MENU_BAR_H + lavel_select * MENU_BAR_MOVE,MENU_BAR_SIZE,c);


		Font::StrDraw(L"�N���W�b�g", MENU_LAVEL_W, MENU_LAVEL_CREDIT_H, MENU_LAVEL_SIZE, c);
		Font::StrDraw(L"�^�C�g����", MENU_LAVEL_W, MENU_LAVEL_ESC_H, MENU_LAVEL_SIZE, c);
		Font::StrDraw(L"�߂�",		 MENU_LAVEL_W, MENU_LAVEL_BACK_H, MENU_LAVEL_SIZE, c);
		//Font::StrDraw(L"", 50, 250, 32, c);
	

		if (lavel_select == LAVEL_TOP) {
			Font::StrDraw(L"�N���W�b�g�ꗗ",				MENU_CREDIT_CON_HEAD_W, MENU_CREDIT_CON_HEAD_H, MENU_CREDIT_CON_HEAD_SIZE, c);
			Font::StrDraw(L"�����",						MENU_CREDIT_CON_W, MENU_CREATOR_H, MENU_CON_GENRE_SIZE, c);
			Font::StrDraw(L"�����f�B���N�^�[:�i�� ���",	MENU_CREDIT_CON_W, MENU_MEMBER1_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�Q�[���v�����i�[:�� ���m",		MENU_CREDIT_CON_W, MENU_MEMBER2_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�Q�[���v���O���}�[:�r�� �C�^",	MENU_CREDIT_CON_W, MENU_MEMBER3_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�Q�[���f�U�C�i�[:�c�� �r�K",	MENU_CREDIT_CON_W, MENU_MEMBER4_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�A�V�X�^���g:���c �I��",		MENU_CREDIT_CON_W, MENU_MEMBER5_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"BGM�E���ʉ�",					MENU_CREDIT_CON_W, MENU_OFFER_H, MENU_CON_GENRE_SIZE, c);
			Font::StrDraw(L"���ʉ����{��https://soundeffect-lab.info/",				MENU_CREDIT_CON_W, MENU_URL1_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"Wingless Seraph��https://wingless-seraph.net/",			MENU_CREDIT_CON_W, MENU_URL2_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�������ʉ���https://taira-komori.jpn.org/index.html",	MENU_CREDIT_CON_W, MENU_URL3_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"��������https://maoudamashii.jokersounds.com/",			MENU_CREDIT_CON_W, MENU_URL4_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"���ʉ����T��https://sounddictionary.info/",				MENU_CREDIT_CON_W, MENU_URL5_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"G-Sound��https://g-miya.net/index.html",				MENU_CREDIT_CON_W, MENU_URL6_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"���炰�H����http://www.kurage-kosho.info/index.html",	MENU_CREDIT_CON_W, MENU_URL7_H, MENU_CREDIT_CON_SIZE, c);
			Font::StrDraw(L"�m�X�^���W�A��http://nostalgiamusic.info/index.html",	MENU_CREDIT_CON_W, MENU_URL8_H, MENU_CREDIT_CON_SIZE, c);
		}
		if (lavel_select == LAVEL_MID_MENU) {
			Font::StrDraw(L"�Q�[�����I�����ă^�C�g���ɖ߂�܂��B",	MENU_CON_TXT_W, MENU_CON_TXT_H, MENU_CON_TXT_SIZE, c);
		}
		if (lavel_select == LAVEL_BOT_MENU) {
			Font::StrDraw(L"�Q�[����ʂ֖߂�܂��B",				MENU_CON_TXT_W, MENU_CON_TXT_H, MENU_CON_TXT_SIZE, c);
		}
	}

}