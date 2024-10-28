#pragma once
#include <cstdint>

enum class Behavior{
	APPROACH,	//Œü‚©‚Á‚Ä‚­‚é
	ATTACK,		//UŒ‚
	WITHDRAWL,	//—£’E
};

class Enemy{
public:
	Enemy() = default;
	~Enemy() = default;

	/// <summary>
	/// Ú‹ß
	/// </summary>
	void Approach();

	/// <summary>
	/// UŒ‚
	/// </summary>
	void Attack();

	/// <summary>
	/// —£’E
	/// </summary>
	void Withdrawal();

	/// <summary>
	/// XV
	/// </summary>
	void Update();

private:
	//ƒƒ“ƒoŠÖ”ƒ|ƒCƒ“ƒ^
	static void (Enemy::* pFuncTable[])();

private:
	uint32_t transitionTime_ = 2;	//2•b‚Å‘JˆÚ
};
