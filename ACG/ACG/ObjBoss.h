#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：敵
class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y, float l, float a);
	~CObjBoss() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー

	float GetVx() { return m_vx; }


private:
	float m_px;	//位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
	float m_posture; //姿勢

	float p_x;
	float p_y;

	int m_ani_time;//アニメーションフレーム動作間隔
	int m_ani_frame;//描画フレーム

	float m_speed_power;//スピードパワー


	//移動の向き制御
	bool m_move;

	float en_life;
	float atk;

	int muteki_time;

	bool awake;

	bool dir_act;//方向転換確認

	int destryNum;//削除用
	int MdestryNum;

	bool atk_kb;


	int time_1;
};

