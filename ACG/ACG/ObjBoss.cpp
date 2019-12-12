//�g�p����w�b�_�[
#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjHero.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBoss.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "GameL/Audio.h"

#define MUTEKI 8;
#define DE_MAGE 10;//hidame
#define SARCH 400

//�g�p����l�[���X�y�[�Xdayo
using namespace GameL;

CObjBoss::CObjBoss(float x, float y, float l, float a)
{
	m_px = x;	//�ʒu
	m_py = y-300;
	en_life = l;
	atk = a;
}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	Audio::Stop(0);//���ʉ��X�g�b�v
	Audio::Start(1);//���ʉ��X�^�[�g

	awake = false;
	m_vx = 0.0f;	//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.0f;	//�ʏ푬�x

	m_move = true;
	dir_act = m_move;

	float p_x = 0;
	float p_y = 0;

	muteki_time = MUTEKI;

	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	if (sceneM == nullptr) {}
	else destryNum = sceneM->GetDS();

	time_1 = 0;
}

//�A�N�V����
void CObjBoss::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float pl_x = obj->GetX();
	float pl_y = obj->GetY();
	float sl = block->GetScroll();
	pl_x += 32.0f;
	pl_y += 32.0f;
	float en_x = m_px + 32.0f;
	float en_y = m_py + 32.0f;

	//�����^��
	m_vx += -(m_vx * 0.1);
	m_vx += -(m_vx * 0.1);

	//�N��
	if (pl_x - sl <= en_x + SARCH &&
		pl_x - sl >= en_x - SARCH &&
		awake == false)
		awake = true;

	//��U��
	if (pl_x - sl <= en_x + 24 - (32 * (obj->Getposture() * 2 - 1)) &&
		pl_x - sl >= en_x - 88 - (32 * (obj->Getposture() * 2 - 1)) &&
		pl_y <= en_y -96.0f &&
		pl_y >= en_y - 220.0f &&
		obj->Getattack() > 0 &&
		obj->Getattack() != 4 &&
		muteki_time <= 0) {
		muteki_time = MUTEKI;
		en_life -= DE_MAGE;
	}

	//�^�U��
	if (pl_x - sl <= en_x + 24.0f &&
		pl_x - sl >= en_x - 88.0f &&
		pl_y <= en_y -96.0f &&
		pl_y >= en_y - 224.0f ) {
		obj->GiveDamageToPlayer(atk/100);
		if (atk_kb == false) {
			if (pl_x - sl <= en_x) {
				obj->SetVX(-50);
			}
			else if (pl_x - sl > en_x) {
				obj->SetVX(50);
			}
		}
		atk_kb = true;
	}
	else {
		atk_kb = false;
	}

	//�u���b�N�Ƃ̓����蔻����s���Ȃ�
	//�V�[���ړ��폜����
	CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
	MdestryNum = sceneM->GetDS();
	if (destryNum != MdestryNum){
		this->SetStatus(false);
	}

	//�v���C���[����
	if (en_life <= 0)
	{
		this->SetStatus(false);
	}
	if (en_life <= 0) 
		Scene::SetScene(new CSceneGameClear());
	
	//�\���ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;


	//�����ύX
	if (pl_x - sl <= en_x)
		m_move = true;
	if (pl_x - sl > en_x)
		m_move = false;
	if (dir_act != m_move) {
		dir_act = m_move;
		m_speed_power = 0.0f;
	}

	//�A�j���[�V����
	if (m_move == false) {//����
		m_posture = 1.0f;
		m_ani_time += 2;
	}
	else if (m_move == true) {
		m_posture = 0.0f;
		m_ani_time += 2;
	}
	if (m_ani_time > 8) {
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 8) {//���[�v����
		m_ani_frame = 0;
	}

	//�m�b�N�o�b�N
	muteki_time--;
	if (muteki_time > 0 && awake == true) {
		if (pl_x - sl <= en_x) {
			m_vx = (5+m_speed_power) * 0.8f;
		}
		else if (pl_x - sl > en_x) {
			m_vx = (-5-m_speed_power)*0.8f;
		}
	}
	if (muteki_time == 0)
		m_speed_power *= 0.7f;
	//-------------------------------------------------------------
	if (muteki_time <= 0 && awake == true) {
		time_1++;

		if (10 <= time_1 && time_1 < 150) {
			m_py += 1;
		}
		if (150 <= time_1 && time_1 < 160) {
			m_px += 5;
		}
















	}
}

//�h���[
void CObjBoss::Draw()
{
	int AniData[4]=
	{//���E�c
		0,1,2,3
	};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0.0f;
	src.m_left = AniData[m_ani_frame/2] * 256.0f;
	src.m_right = src.m_left + 256.0f;
	src.m_bottom = src.m_top + 256.0f;
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	dst.m_top = -192.0f + m_py;
	dst.m_left = (256.0f * m_posture) + m_px + block->GetScroll() - 128.0f;
	dst.m_right = (256.0f - 256.0f * m_posture) + m_px + block->GetScroll() - 128.0f;
	dst.m_bottom = 64.0f + m_py;
	Draw::Draw(7, &src, &dst, c, 0.0f);
}