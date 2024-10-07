#include <iostream>
#include <random>
#include <ctime>
#include <functional>

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


// 指定した秒数だけ待機して、関数を実行
void SetTimeout(std::function<void(int, int)> func, int seconds, int diceNumber, int userGuess){
    clock_t start_time = clock();
    // 指定された時間が経過するまで待機
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds);

    // 指定した時間が経過したら関数を実行する
    func(diceNumber, userGuess);
}


int main(){
    // 繰り返しプレイするかどうかのフラグ
    char playAgain = 'y';

    // 判定結果
    std::function<void(int, int)> result = [] (int diceNumber, int userGuess){JudgeResult(diceNumber, userGuess); };

    //yを押したら繰り返し遊べる
    while (playAgain == 'y'){
        // ユーザーの入力を取得
        std::cout << "サイコロの出目が奇数なら 1、偶数なら 2 と入力してください: ";
        int userGuess;
        std::cin >> userGuess;

        // サイコロの出目を決定
        int diceNumber = RollDice();

        std::cout << "サイコロを振っています..." << std::endl;
        //3秒待機して結果を表示
        SetTimeout(result, 3, diceNumber, userGuess);

        // 再度プレイするか
        std::cout << "\nもう一度プレイしますか？ (y/n): ";
        std::cin >> playAgain;
        std::cout << "\n";
    }

    system("pause");
    return 0;
}
