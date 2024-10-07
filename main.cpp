#include <iostream>
#include <random>
#include <ctime>

// 判定結果を表示するコールバック関数
void JudgeResult(int diceNumber, int userGuess){
    // 出目が偶数か奇数かを判定
    bool isEven = (diceNumber % 2 == 0);

    // ユーザーの予想と出目の偶奇が一致するかを判定
    if ((isEven && userGuess == 2) || (!isEven && userGuess == 1)){
        printf("正解！サイコロの出目は %d でした。\n", diceNumber);
    } else{
        printf("不正解。サイコロの出目は %d でした。\n", diceNumber);
    }
}

// サイコロの出目をランダムに生成
int RollDice(){
    // ランダムデバイスの作成
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);
    return dist(gen);
}

// 指定した秒数だけ待機する
void Delay(int seconds){
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds);
}

typedef void (*judgeResult)(int, int);

int main(){
    // 繰り返しプレイするかどうかのフラグ
    char playAgain = 'y';

    // 判定結果
    judgeResult result;
    result = &JudgeResult;

    //yを押したら繰り返し遊べる
    while (playAgain == 'y'){
        // ユーザーの入力を取得
        std::cout << "サイコロの出目が奇数なら 1、偶数なら 2 と入力してください: ";
        int userGuess;
        std::cin >> userGuess;

        // サイコロの出目を決定
        int diceNumber = RollDice();

        // 3秒待機
        std::cout << "サイコロを振っています..." << std::endl;
        Delay(3);

        // 結果を判定
        result(diceNumber, userGuess);

        // 再度プレイするか
        std::cout << "\nもう一度プレイしますか？ (y/n): ";
        std::cin >> playAgain;
    }

    system("pause");
    return 0;
}
