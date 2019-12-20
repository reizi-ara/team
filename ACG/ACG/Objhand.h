#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class CObjhand : public CObj
{
public:
	CObjhand(float x, float y, float t,float d);
	~CObjhand() {};
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
	float m_ani_max_time;//アニメーション動作間隔

	 //blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//移動の向き制御
	bool m_move;

	float en_life;

	int hit_length;
	int sarch_length;

	int size;
	int awake;
	int type;
	bool isplayerhit;

	float Damage;
	int time;
	int times;

	//削除用
	int destryNum;
	int MdestryNum;

};
