#include "Enemy.h"

#include <iostream>
#include <thread>
#include <chrono>

void Enemy::Update(){
    // Šes“®‚ğ2•b‚²‚Æ‚É1‰ñ‚¸‚ÂÀs‚·‚é
    for (int i = 0; i < 3; ++i){
        (this->*pFuncTable[i])();
        std::this_thread::sleep_for(std::chrono::seconds(transitionTime_));
    }
}

void Enemy::Approach(){
    std::cout << "Ú‹ß’†" << std::endl;
}

void Enemy::Attack(){
    std::cout << "UŒ‚’†" << std::endl;
}

void Enemy::Withdrawal(){
    std::cout << "—£’E’†" << std::endl;
}

// ƒƒ“ƒoŠÖ”ƒ|ƒCƒ“ƒ^‚Ì‰Šú‰»
void (Enemy::* Enemy::pFuncTable[])() = {
    &Enemy::Approach,   // Œü‚©‚Á‚Ä‚«‚Ä‚¢‚é
    &Enemy::Attack,     // UŒ‚’†
    &Enemy::Withdrawal  // —£’E’†
};
