#pragma once

//�V�[�����C���}�N���S----------------------------------
//�}�b�v�ԍ�
#define MAP_NUMBER_1 0
#define MAP_NUMBER_2 1
#define MAP_NUMBER_3 2
#define MAP_NUMBER_4 3
#define MAP_NUMBER_5 4

//�O���t�B�b�N�ǂݍ��ݔԍ�
#define SPLITE_NUMBER_1
#define SPLITE_NUMBER_2
#define SPLITE_NUMBER_6
#define SPLITE_NUMBER_3
#define SPLITE_NUMBER_4
#define SPLITE_NUMBER_5
#define SPLITE_NUMBER_7
#define SPLITE_NUMBER_8
#define SPLITE_NUMBER_9


//BGM
#define SCENE_MAIN_BGM_MAINSTAGE	0	//���C��BGM
#define SCENE_MAIN_BGM_BOSS			1	//�{�XBGM
#define SCENE_MAIN_BGM_MENU			2	//���j���[BGM

#define SCENE_MAIN_SE_WALK			5	//�����A����SE
#define SCENE_MAIN_SE_DOOR			6	//�h�ASE
#define SCENE_MAIN_SE_DAMEGE		7	//�_���[�WSE
#define SCENE_MAIN_SE_DECIDE		8	//����SE
#define SCENE_MAIN_SE_SELECT		9	//�Z���N�gSE
#define SCENE_MAIN_SE_BOOK_OPEN		10	//�{�I�J��SE
#define SCENE_MAIN_SE_BOOK_CLOSE	11	//�{�I��SE
#define SCENE_MAIN_SE_HAND			12	//��SE�ƃ_���[�W
#define SCENE_MAIN_SE_ATTACK		13	//�U��SE




//�G�}�N��-------------------------------------
#define TIME_SLOW_EE 120	//�ڋʂ̑ҋ@����
#define TIME_RUSH_EE 360	//�ڋʂ̓ˌ�����


//���E�\�N-------------------------
#define CANDLE_CUT_TOP		64.0f * 4	//���E�\�N�؂����
#define CANDLE_CUT_LEFT		64.0f * 5	//���E�\�N�؂��荶
#define CANDLE_CUT_RIGHT	64.0f * 6	//���E�\�N�؂���E
#define CANDLE_CUT_BOTTOM	64.0f * 5	//���E�\�N�؂��艺

//�^�C�g��and���j���[�֘A-----------------------
#define LAVEL_TOP   0		//���x���̈�ԏ�(�N���W�b�gor�X�^�[�g)

#define LAVEL_MID_MENU  1		//���j���[���x���̐^��(�^�C�g����)
#define LAVEL_BOT_MENU  2		//���j���[���x���̈�ԉ�(�߂�)

#define LAVEL_BOT_TITLE 1		//�^�C�g�����x���̈�ԉ�(�Q�[���I��)

#define START_BACK_CUT_TOP		0.0f	//�^�C�g���摜�؂����
#define START_BACK_CUT_LEFT		0.0f	//�^�C�g���摜�؂��荶
#define START_BACK_CUT_RIGHT	910.0f  //�^�C�g���摜�؂���E
#define START_BACK_CUT_BOTTOM	512.0f	//�^�C�g���摜�؂��艺

#define START_BUTTON_CUT_TOP	0.0f	//�{�^���؂����
#define START_BUTTON_CUT_LEFT	64.0f	//�{�^���؂��荶
#define START_BUTTON_CUT_RIGHT	64.0f	//�{�^���؂���E
#define START_BUTTON_CUT_BOTTOM	64.0f	//�{�^���؂��艺

#define END_BUTTON_CUT_TOP		0.0f	//�{�^���؂����
#define END_BUTTON_CUT_LEFT		0.0f	//�{�^���؂��荶
#define END_BUTTON_CUT_RIGHT	64.0f	//�{�^���؂���E
#define END_BUTTON_CUT_BOTTOM	64.0f	//�{�^���؂��艺

#define START_BUTTON_LEFT_EXP	4		//start���g��
#define START_BUTTON_RIGHT_EXP	8		//start�E�g��

#define END_BUTTOM_RIGHT_EXP	4		//end�E�g��

#define START_POS_PUT_TOP		 80		//�{�^���`��㒲��
#define START_POS_PUT_LEFT		150		//�{�^���`�捶����
#define START_POS_PUT_RIGHT		150		//�{�^���`��E����
#define START_POS_PUT_BOTTOM	160		//�{�^���`�扺����
#define END_POS_PUT_TOP			160		//�G���h�{�^���`��㒲��
#define END_POS_PUT_LEFT		150		//�G���h�{�^���`�捶����
#define END_POS_PUT_RIGHT		150		//�G���h�{�^���`��E����
#define END_POS_PUT_BOTTOM		240		//�G���h�{�^���`�扺����

#define MENU_BACK_CUT_TOP		0.0f	//���j���[�摜�؂����
#define MENU_BACK_CUT_LEFT		0.0f	//���j���[�摜�؂��荶
#define MENU_BACK_CUT_RIGHT		910.0f  //���j���[�摜�؂���E
#define MENU_BACK_CUT_BOTTOM	512.0f	//���j���[�摜�؂��艺

#define MENU_BACK_PUT_TOP		0.0f	//���j���[�w�i�`���
#define MENU_BACK_PUT_LEFT		0.0f	//���j���[�w�i�`�捶

#define MENU_BAR_W				220		//���j���[��󉡎�
#define MENU_BAR_H				90		//���j���[���c��

#define MENU_BAR_MOVE			50		//���j���[�o�[�ړ���
#define MENU_BAR_SIZE			50		//���j���[�o�[�T�C�Y

#define MENU_LAVEL_W			50		//���j���[���x���s������
#define MENU_LAVEL_CREDIT_H		100		//�u�N���W�b�g�v�c��
#define MENU_LAVEL_ESC_H		150		//�u�^�C�g���ցv�c��
#define MENU_LAVEL_BACK_H		200		//�u�߂�v�c��
#define MENU_LAVEL_SIZE			32		//���j���[���x���T�C�Y

#define MENU_CREDIT_CON_HEAD_W	690		//�u�N���W�b�g�ꗗ�v����
#define MENU_CREDIT_CON_HEAD_H	40		//�u�N���W�b�g�ꗗ�v�c��
#define MENU_CREDIT_CON_HEAD_SIZE	32	//�u�N���W�b�g�ꗗ�v�T�C�Y

#define MENU_CREDIT_CON_W		350		//�N���W�b�g���g�s������
#define MENU_CREATOR_H			70		//�u����ҁv�c��
#define MENU_MEMBER1_H			100		//�����o�[�c��
#define MENU_MEMBER2_H			135		//�����o�[�c��
#define MENU_MEMBER3_H			170		//�����o�[�c��
#define MENU_MEMBER4_H			205		//�����o�[�c��
#define MENU_MEMBER5_H			240		//�����o�[�c��

#define MENU_OFFER_H			300		//�uBGM�E���ʉ��v�c��
#define MENU_URL1_H				330		//url�c��
#define MENU_URL2_H				365		//url�c��
#define MENU_URL3_H				400		//url�c��
#define MENU_URL4_H				435		//url�c��
#define MENU_URL5_H				470		//url�c��
#define MENU_URL6_H				505		//url�c��
#define MENU_URL7_H				540		//url�c��
#define MENU_URL8_H				575		//url�c��
#define MENU_URL9_H				330		//url�c��

#define MENU_CON_GENRE_SIZE		20		//�N���W�b�g���g�W�������T�C�Y
#define MENU_CREDIT_CON_SIZE	27		//�N���W�b�g���g�T�C�Y

#define MENU_CON_TXT_W			400		//���j���[�e�L�X�g�c��
#define MENU_CON_TXT_H			300		//���j���[�e�L�X�g����
#define MENU_CON_TXT_SIZE		45		//���j���[�e�L�X�g�T�C�Y


//�x�������}�N��--------------------------------
#define TIME_INI     0		//�����l 0
#define TIME_INI_HM  0		//HERO�}�b�v�f�o�b�O�����l

#define TIME_DELAY 30		//�x������(���ENTER�L�[�x��)
#define TIME_DELAY_GO 120   //GAMEOVER�x��


#define MAP_X (100)			//�}�b�v��
#define MAP_Y (10)			//�}�b�v�c



//�G���h�h�A�@�}�N���Q-----------------------------------
#define END_DOOR_HIT_LENGTH 64.0
#define END_DOOR_SISTEM_CLOSE 1
#define END_DOOR_SISTEM_OPEN 2

//END�����؂���ʒu
#define END_DOOR_CLOSE_CUT_TOP 0.0f
#define END_DOOR_CLOSE_CUT_LEFT 0.0f
#define END_DOOR_CLOSE_CUT_RIGHT 128.0f
#define END_DOOR_CLOSE_CUT_BOTTOM 128.0f

//END���J���؂���ʒu
#define END_DOOR_OPEN_CUT_TOP 0.0f
#define END_DOOR_OPEN_CUT_LEFT 128.0f
#define END_DOOR_OPEN_CUT_RIGHT 128.0f*2
#define END_DOOR_OPEN_CUT_BOTTOM 128.0f

//END���\���ʒu
#define END_DOOR_PUT_TOP -64.0f
#define END_DOOR_PUT_LEFT -64.0f
#define END_DOOR_PUT_RIGHT 64.0f
#define END_DOOR_PUT_BOTTOM 64.0f

//Boss_____________________________________________

#define BOSSMUTEKI 10;//��U�������G����
#define PASSIVE_DAMAGE 10;//���ʔ�_���[�W
#define SARCH 400//���m�͈́A�N��

#define OBJ64OFSET_CENTER 32.0f//�U�S�T�C�Y�I�u�W�F�N�g���S




//_____________________________________________








