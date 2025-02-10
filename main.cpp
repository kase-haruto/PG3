#include <iostream>

// 一般的な賃金形態の場合の賃金
int CalculateWage(int hour){
    return 1072 * hour;
}

// 再帰的な賃金形態
int RecursiveWage(int hour){
    if (hour == 1){
        return 100;
    }
    return RecursiveWage(hour - 1) * 2 - 50;
}

// 合計賃金を計算する関数
int CalculateTotalRecursiveWage(int hours){
    int totalWage = 0;
    for (int hour = 1; hour <= hours; ++hour){
        totalWage += RecursiveWage(hour);
    }
    return totalWage;
}

int main(){
    int workingHours = 8;

    std::cout << "労働時間は " << workingHours << " 時間\n";
    std::cout << "一般的な賃金形態: " << CalculateWage(workingHours) << " 円\n";
    std::cout << "再帰的な賃金形態: " << CalculateTotalRecursiveWage(workingHours) << " 円\n";

    if (CalculateWage(workingHours) > CalculateTotalRecursiveWage(workingHours)){
        std::cout << "一般的な賃金形態のほうが高賃金\n";
    } else{
        std::cout << "再帰的な賃金形態のほうが高賃金\n";
    }

    // 終了前にキー入力待ち
    std::cin.get();
    return 0;
}
