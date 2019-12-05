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
	
	int count = 0;//1000�񐔂���悤

	if (m_chg == 0 && One_chg == true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		One_chg = false;

	}
	else if (m_chg == 1&&One_chg==true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;

	}
	else if (m_chg == 2 && One_chg == true)
	{
		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));
		
		One_chg = false;


	}
	else if (m_chg == 3 && One_chg == true)
	{

		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}
	else if (m_chg == 4 && One_chg == true)
	{

		Transfer(map, map2);
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, map, sizeof(int)*(MAP_Y * MAP_X));

		One_chg = false;


	}

	//��l���̈ʒu���擾
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < WINDOW_SIZE_W /7*1.6f)
	{
		hero->SetX(WINDOW_SIZE_W / 7 * 1.6f);				//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();  //��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[��
	if (hx > WINDOW_SIZE_W / 7 * 4.0f)
	{
		hero->SetX(WINDOW_SIZE_W / 7 * 4.0f);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	
	//�G�o�����C���̗������
	for (int ex = 0; ex < MAP_X; ex++) {
		for (int i = 0; i < MAP_Y; i++)
		{
			if (m_map[i][ex] == 0) {
				;
			}
			else if (m_map[i][ex] == 20) {//�G1(PJ
				CObjEnemy* obj20 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 1);
				Objs::InsertObj(obj20, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 21) {//�G2(Jump
				CObjEnemy* obj21 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 2);
				Objs::InsertObj(obj21, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 22) {//�G3
				CObjEnemy* obj22 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 3);
				Objs::InsertObj(obj22, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 23) {//�G4
				CObjEnemy* obj23 = new CObjEnemy(ex * 64.0f, i * 64.0f, 170, 30, 4);
				Objs::InsertObj(obj23, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 27) {//boss
				CObjBoss* obj27 = new CObjBoss(ex * 64.0f, i * 64.0f, 900, 50);
				Objs::InsertObj(obj27, OBJ_ENEMY, 10);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == 30) {//�G�r
				CObjhand* obj30 = new CObjhand(ex * 64.0f, i * 64.0f, 0, 15);
				Objs::InsertObj(obj30, OBJ_HAND, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 33) {//��3
				CObjThorn* obj33 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 3);
				Objs::InsertObj(obj33, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 37) {//��7
				CObjThorn* obj37 = new CObjThorn(ex * 64.0f, i * 64.0f, 0.0f, 0.1f, 7);
				Objs::InsertObj(obj37, OBJ_THORN, 10);
				m_map[i][ex] = 0;
			}

			else if (m_map[i][ex] == 40) {//���}�b�v�ړ���
				CObjMapChanger* obj40 = new CObjMapChanger(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj40, OBJ_MAPCHANGER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 41) {//���}�b�v�ړ���
				CObjMapBacker* obj41 = new CObjMapBacker(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obj41, OBJ_MAPBACKER, 10);
				m_map[i][ex] = 0;
			}
			else if (m_map[i][ex] == 50) {//�{�I�P
				CObjMessage* obje = new CObjMessage(ex * 64.0f, i * 64.0f, 0);
				Objs::InsertObj(obje, OBJ_MESSAGE, 10);
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
	float c[4]  = { 1.0f,1.0f,1.0f,1.0f };
	float cr[4] = { 0.7f,0.7f,0.7f,1.0f };

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




	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
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




