#include "Enemy.h"

#include <iostream>
#include <thread>
#include <chrono>

void Enemy::Update(){
    // 各行動を2秒ごとに1回ずつ実行する
    for (int i = 0; i < 3; ++i){
        (this->*pFuncTable[i])();
        std::this_thread::sleep_for(std::chrono::seconds(transitionTime_));
    }
}

void Enemy::Approach(){
    std::cout << "接近中" << std::endl;
}

void Enemy::Attack(){
    std::cout << "攻撃中" << std::endl;
}

void Enemy::Withdrawal(){
    std::cout << "離脱中" << std::endl;
}

// メンバ関数ポインタの初期化
void (Enemy::* Enemy::pFuncTable[])() = {
    &Enemy::Approach,   // 向かってきている
    &Enemy::Attack,     // 攻撃中
    &Enemy::Withdrawal  // 離脱中
};
