//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameStart.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}
//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[���^�C�g���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneGameStart());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOSE", 340, 150, 32, c);
	Font::StrDraw(L"GAME OVER", 330, 225, 32, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 220, 350, 32, c);

}

