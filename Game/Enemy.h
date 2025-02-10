#pragma once
#include <cstdint>

enum class Behavior{
	APPROACH,	//向かってくる
	ATTACK,		//攻撃
	WITHDRAWL,	//離脱
};

class Enemy{
public:
	Enemy() = default;
	~Enemy() = default;

	/// <summary>
	/// 接近
	/// </summary>
	void Approach();

	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack();

	/// <summary>
	/// 離脱
	/// </summary>
	void Withdrawal();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

private:
	//メンバ関数ポインタ
	static void (Enemy::* pFuncTable[])();

private:
	uint32_t transitionTime_ = 2;	//2秒で遷移
};
