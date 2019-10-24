#include "GameL\DrawTexTure.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMenu.h"

const static int GAME_Y = 240;    //�u�Q�[���v������y�ʒu
const static int CONFIG_Y = 270;    //�u�ݒ�v������y�ʒu

typedef enum {
	eMenu_Game,        //�Q�[��
	eMenu_Config,    //�ݒ�

	eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

//�X�V
/*void Menu_Update() {
	if (Input::GetVKey('S')==1) {//���L�[��������Ă�����
		NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
	}
	if (Input::GetVKey('W') == 1) {//��L�[��������Ă�����
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
	}
	if (Input::GetVKey(VK_RETURN) == 1) {//�G���^�[�L�[�������ꂽ��
		switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_Game://�Q�[���I�𒆂Ȃ�
			CObjMenu(eScene_Game);//�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_Config://�ݒ�I�𒆂Ȃ�
			SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		}
	}
}*/

//�h���[
void Menu_Draw() {
	
}
//�h���[
void CObjGameStart::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 960.0f;
	src.m_bottom = 450.0f;

	//�w�i1�̈ʒu��ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	Font::StrDraw(L"���j���[���", 200, 150, 32, c);
	Font::StrDraw(L"�㉺k�|�������A�G���^�[�L�[�������Ă��������B", 200, 170, 32, c);
	Font::StrDraw(L"�Q�[��", 280, GAME_Y, 32, c);
	Font::StrDraw(L"�ݒ�", 280, CONFIG_Y, 32, c);

	int y = 0;
	switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Game://�Q�[���I�𒆂Ȃ�
		y = GAME_Y;    //�Q�[���̍��W���i�[
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		y = CONFIG_Y;    //�ݒ�̍��W���i�[
		break;
	}
	Font::StrDraw(L"��", 250,y,32,c);
}