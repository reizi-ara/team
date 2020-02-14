//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

#include "main.h"
#include "ObjMapChanger.h"
#include "ObjMapBacker.h"
#include "MacroManagement.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


CObjBlock::CObjBlock(int map[MAP_Y][MAP_X])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	mmmm = false;
	m_scroll = 0.0f;
	ikkai = true;
}

//�A�N�V����
void CObjBlock::Action()
{

	if (ikkai == true)
	{
		//���C������}�b�v2�̃A�h���X�������Ă���
		CSceneMain*sceneM = (CSceneMain*)Scene::GetScene();
		map2 = sceneM->GetM1();
		One_chg = sceneM->GetONEs();
		ikkai = false;

	}

	if (m_chg > MAP_NULL_NUMBER)
	{
		m_chg = MAP_NUMBER_5;
	}
	
	int count = 0;//1000�񐔂���悤

	if (m_chg == MAP_NUMBER_1 && One_chg == true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;

	}
	else if (m_chg == MAP_NUMBER_2 &&One_chg==true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;

	}
	else if (m_chg == MAP_NUMBER_3 && One_chg == true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;


	}
	else if (m_chg == MAP_NUMBER_4 && One_chg == true)
	{

		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}
	else if (m_chg == MAP_NUMBER_5 && One_chg == true)	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;
	}
	/*else if (m_chg == 5 && One_chg == true) {
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int) * (MAP_Y * MAP_X));
		One_chg = false;
	}*/

	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < WINDOW_SIZE_W / BLOOK_BACK_SCROLL_LINE)
	{
		hero->SetX(WINDOW_SIZE_W / BLOOK_BACK_SCROLL_LINE);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();  //��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[��
	if (hx > WINDOW_SIZE_W / BLOOK_PREVIOUS_SCROLL_LINE)
	{
		hero->SetX(WINDOW_SIZE_W / BLOOK_PREVIOUS_SCROLL_LINE);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	
	//�G�o�����C���̗������
	for (int ex = SCENE_MAIN_MAP_READ_INITIAL_X; ex < MAP_X; ex++) {
		for (int i = SCENE_MAIN_MAP_READ_INITIAL_Y; i < MAP_Y; i++)
		{
			if (m_map[i][ex] == BLOOK_NULL_NUMBER) {
				;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_PJ_NUMBER) {//�G1(PJ-xyhat
				CObjEnemy* obj20 = new CObjEnemy(ex * 64.0f, i * 64.0f, 30, 20, ENEMY_PJ_TYPE);
				Objs::InsertObj(obj20, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_EYE_NUMBER) {//�G2��
				CObjEnemy* obj21 = new CObjEnemy(ex * 64.0f, i * 64.0f, 30, 20, ENEMY_EYE_TYPE);
				Objs::InsertObj(obj21, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_DOC_NUMBER) {//�G3(inu
				CObjEnemy* obj22 = new CObjEnemy(ex * 64.0f, i * 64.0f, 50, 45, ENEMY_DOG_TYPE);
				Objs::InsertObj(obj22, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_CACTUS_NUMBER) {//�΂�
				CObjEnemy* obj23 = new CObjEnemy(ex * 64.0f, i * 64.0f, 60, 35, ENEMY_GREEN_TYPE);
				Objs::InsertObj(obj23, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ITEM_HEAL_NUMBER) {//item:hp*0.5
				CObjEnemy* obj25 = new CObjEnemy(ex * 64.0f, i * 64.0f, 60, 10, ENEMY_HEAL_TYPE);
				Objs::InsertObj(obj25, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ITEM_BIGHEAL_NUMBER) {//item
				CObjEnemy* obj26 = new CObjEnemy(ex * 64.0f, i * 64.0f, 200, 10, ENEMY_HEAL_TYPE);
				Objs::InsertObj(obj26, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOOK_ENEMY_BOSS_NUMBER) {//boss
				CObjBoss* obj27 = new CObjBoss(ex * 64.0f, i * 64.0f, 200, 50);
				Objs::InsertObj(obj27, OBJ_ENEMY, 11);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_HAND_NUMBER) {//�G�r
				CObjhand* obj30 = new CObjhand(ex * 64.0f, i * 64.0f, 0, 7);
				Objs::InsertObj(obj30, OBJ_HAND, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_THORN3_NUMBER) {//��3
				CObjThorn* obj33 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 3);
				Objs::InsertObj(obj33, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_TRAP_THORN7_NUMBER) {//��7
				CObjThorn* obj37 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 7);
				Objs::InsertObj(obj37, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_CANDLE_NUMBER) {//�X�C
				CObjCandle* obj39 = new CObjCandle(ex * 64.0f, i * 64.0f);
				Objs::InsertObj(obj39, OBJ_CANDLE, 99);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == BLOCK_OBJ_NEXT_DOOR_NUMBER) {//���}�b�v�ړ���
				CObjMapChanger* obj40 = new CObjMapChanger(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj40, OBJ_MAPCHANGER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BACK_DOOR_NUMBER) {//���}�b�v�ړ���
				CObjMapBacker* obj41 = new CObjMapBacker(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj41, OBJ_MAPBACKER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_END_DOOR_NUMBER) {//�G���f�B���O��
				CObjEndingDoor* obj42 = new CObjEndingDoor(ex * 64.0f, i * 64.0f);
				Objs::InsertObj(obj42, OBJ_ENDING_DOOR, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK1_NUMBER) {//�{�I1
				CObjMessage* obj50 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE1);
				Objs::InsertObj(obj50, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK2_NUMBER) {//�{�I2				
				CObjMessage* obj51 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE2);
				Objs::InsertObj(obj51, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK3_NUMBER) {//�{�I3
				CObjMessage* obj52 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE3);
				Objs::InsertObj(obj52, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK4_NUMBER) {//�{�I4
				CObjMessage* obj53 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE4);
				Objs::InsertObj(obj53, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == BLOCK_OBJ_BOOK5_NUMBER) {//�{�I5
				CObjMessage* obj54 = new CObjMessage(ex * 64.0f, i * 64.0f, BLOCK_BOOK_TYPE5);
				Objs::InsertObj(obj54, OBJ_MESSAGE, 10);
				m_map[i][ex] = 0;
			}
		}
	}
}

//BlockHit�֐�
//����1�@float*�@���@�F������s��object��X�ʒu
//����2�@float*�@���@�F������s��object��Y�ʒu
//����3�@bool�@scroll_on�@�F������s��object�̓X�N���[���ɉe����^���邩�ǂ����itrue���^����@false���^���Ȃ��j
//����4�@bool*�@up�@�F�㉺���E����̏㕔���ɓ������Ă邩�ǂ�����Ԃ�
//����5�@bool*�@down�@�F�㉺���E����̉������ɓ������Ă邩�ǂ�����Ԃ�
//����6�@bool*�@left�@�F�㉺���E����̍������ɓ������Ă邩�ǂ�����Ԃ�
//����7�@bool*�@right�@�F�㉺���E����̉E�����ɓ������Ă邩�ǂ�����Ԃ�
//����8�@float*�@�����@�F���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9�@float*�@�����@�F�㉺���莞�ɂ�鎩�R�����^���ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����10�@int*�@�����@�F���������莞�A����ȃu���b�N�̃^�C�v�Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool* down, bool* left, bool *right,
	float* vx, float*vy, int* bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (m_map[i][j] > 0&&m_map[i][j]<=9)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll: 0;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f>bx) && (*x + (-scroll)<bx + 64.0f) && (*y + 64.0f>by) && (*y<by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 86.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r<45 && r>0) || r>315)
						{
							//�E
							*right=true;//��l���̍��̕������Փ˂��Ă���
							*x=bx+64.0f+(scroll);//�u���b�N�̈ʒu+��l���̕�
							*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r>45 && r<135)
						{
							//��
							*down=true;//��l���̉��̕������Փ˂��Ă���
							*y=by-64.0f;//�u���b�N�̈ʒu�[��l���̕�
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];
							*vy = 0.0f;
						}
						if (r>135 && r<225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 64.0f + (scroll);//�u���b�N�̈ʒu�[��l���̕�
							*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r>225 && r<315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 64.0f;//�u���b�N�̈ʒu+��l���̕�
							if(*vy<0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}

//BlockDrawMethod�֐�
//����1�@float�@���F���\�[�X�؂���ʒuX
//����2�@float�@���F���\�[�X�؂���ʒuY
//����3�@RECT�QF*�������F�`��ʒu
//����4�@float�@��[]�F�J���[���
//����5�@int �X�v���C�g�i���o�[
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�݂̂��E����
//�ݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[],int s)
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(s, &src, dst, c, 0.0f);
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4]  = { 0.7f,0.7f,0.7f,1.0f };
	float cr[4] = { 0.4f,0.4f,0.4f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��!n
	src.m_top = 512.0f*0;
	src.m_left = 0.0f;
	src.m_right = 910.0f;
	src.m_bottom = 512.0f+ src.m_top;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = WINDOW_SIZE_W;
	dst.m_bottom = WINDOW_SIZE_H;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f+m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j] == 1)
				{
					BlockDraw(0.0f, 128.0f, &dst, c,2);
				}
				else if (m_map[i][j] == 2)
				{
					BlockDraw(64.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 3)
				{
					BlockDraw(128.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 4)
				{
					BlockDraw(192.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 5)
				{
					BlockDraw(256.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 6)
				{
					BlockDraw(320.0f, 128.0f, &dst, c, 2);
				}
				else if (m_map[i][j] == 13)
				{
					BlockDraw(128.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 14)
				{
					BlockDraw(192.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 15)
				{
					BlockDraw(256.0f, 128.0f, &dst, cr, 2);
				}
				else if (m_map[i][j] == 16)
				{
					BlockDraw(320.0f, 128.0f, &dst, cr, 2);
				}
				else
				{

				}
			}
		}
	}
}





void CObjBlock::Transfer(int map[MAP_Y][MAP_X],int* map2)
{
	int count = 0;
	//�}�b�v�����ڂ�
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{

			map[i][j] = *(map2 + count);
			count++;

		}

	}
}




