
//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"

#include "GameHead.h"
#include "Objmessage2.h"
#include "main.h"
#include "GameL/Audio.h"

#define LIFE 80;
//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjMessage2::CObjMessage2(float x, float y, float t)
{
	m_px = x;	//�ʒu
	m_py = y;

	type = t;
}

//�C�j�V�����C�Y
void CObjMessage2::Init()
{
	Audio::Start(10);//�{�J��SE

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
	time = 0;
}

//�A�N�V����
void CObjMessage2::Action()
{
	if (time < 30)
		time++;
	if (Input::GetVKey(VK_RETURN)&& time >= 30 ||
		Input::GetVKey('W')||
		Input::GetVKey('A')||
		Input::GetVKey('D'))
	{
			CObjMessage* objM = (CObjMessage*)Objs::GetObj(OBJ_MESSAGE);

			objM->Toarrivewindow(0);

			Audio::Start(11);//�{��SE
			
			this->SetStatus(false);
			
	}
}

//�h���[
void CObjMessage2::Draw()
{
	
		float c[4] = { 0.7f,0.7f,0.7f,1.0f };

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f * 6;
		src.m_left = 64.0f * 0;
		src.m_right = 64.0f * 8;
		src.m_bottom = 64.0f * 8;

		//�w�i�̈ʒu��ݒ肵�`��
		dst.m_top = WINDOW_SIZE_H * 0.7;
		dst.m_left = 0.0f;
		dst.m_right = WINDOW_SIZE_W;
		dst.m_bottom = WINDOW_SIZE_H;
		Draw::Draw(2, &src, &dst, c, 0.0f);

		if (type == 0) {
			Font::StrDraw(L"���̕s�C���ȗm�قɖ�������Ő������o�����B", 150, 550, 25, c);
			Font::StrDraw(L"����������Ǝ��ȊO�ɖ������񂾐l�Ԃ����邩������Ȃ��B", 150, 575, 25, c);
			Font::StrDraw(L"���������������Ƃ�����΂��̃����ɋL�����Ǝv���B", 150, 600, 25, c);
			Font::StrDraw(L"���ҁF�c��", 750, 675, 20, c);
		}
		else if (type == 1) {
			Font::StrDraw(L"aaaaaaaaaaaaaaaaaaaaaaaaa", 150, 550, 25, c);
			Font::StrDraw(L"����������Ǝ��ȊO�ɖ������񂾐l�Ԃ����邩������Ȃ��B", 150, 575, 25, c);
			Font::StrDraw(L"���������������Ƃ�����΂��̃����ɋL�����Ǝv���B", 150, 600, 25, c);
			Font::StrDraw(L"���ҁF�c��", 750, 675, 20, c);
		}
	
}