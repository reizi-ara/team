#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero :public CObj
{
	public:
		CObjHero() {};
		~CObjHero() {};
		void Init();	//イニシャライズ
		void Action();  //アクション
		void Draw();	//ドロー

		float GetX() { return m_px; }
		float GetY() { return m_py; }
		float GetVY() { return m_vy; }
		float GetVX() { return m_vx; }
		int GetBT() { return m_block_type; }

		void SetX(float x) { m_px = x; }
		void SetY(float y) { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t) { m_block_type=t; }

		void SetUp(bool b) { m_hit_up = b; }
		void SetDown(bool b) { m_hit_down = b; }
		void SetLeft(bool b) { m_hit_left = b; }
		void SetRight(bool b) { m_hit_right = b; }

		void GiveDamageToPlayer(float damage) { g_damage= damage;  }

		int Getwepon() { return wepon_have; }
		int Getposture() { return m_posture; }
		int Getpose() { return m_pose; }
		int Getattack() { return wepon_attack; }
		void GiveSpeed(float speed) { sohuran = speed; }
		void SetMessageflag(bool att) { Message_flag = att; }

	private:
		float m_px;	//位置
		float m_py;
		float m_vx; //移動ベクトル
		float m_vy;
		float m_posture; //姿勢(左右)
		float m_pose;//状態


		int m_ani_time;//アニメーションフレーム動作間隔
		int m_ani_frame;//描画フレーム

		float m_speed_power;//スピードパワー
		float m_ani_max_time;//アニメーション動作間隔

		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//踏んでいるblockの種類を確認用
		int m_block_type;

		//テスト用
		float px, py;

		float p_life;
		float p_maxlife;

		bool flg_j;

		//04:なし　123:下位3種 567:上位3種
		int wepon_have;
		int wepon_attack;

		//メニュー
		int lavel_select;	//上下ボタンセレクト用
		bool lavel_button;//一回発動用
		bool lavel_button2;//一回発動用
		/*bool lavel_button3;//一回発動用
		bool lavel_button4;//一回発動用
		bool lavel_button5;//一回発動用*/
		bool m_key_flag;

		//メニュー展開時の操作フラグ
		bool p_menuflag;
		bool p_menu_close;

		bool attack_set;
		bool attack_flag;

		float muteki_time;
		float overplayerlife;
		float g_damage;

		float sohuran;
		bool Message_flag;
};