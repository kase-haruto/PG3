#include <iostream>

//一般的な賃金形態の場合の賃金
int CalculateWage(int hour){
	return 1072 * hour;
}

//再帰的な賃金形態
int RecursiveWage(int hour){
	// 最初の1時間の時給は100円
	if (hour == 1){
		return 100;
	}
	// limitTimeが2時間以上の場合の賃金計算
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

	printf("労働時間は%d時間\n",workingHours);
	printf("一般的な賃金形態:%d\n", CalculateWage(workingHours));
	printf("再帰的な賃金形態:%d\n", CalculateTotalRecursiveWage(workingHours));
	
	if (CalculateWage(workingHours)> CalculateTotalRecursiveWage(workingHours)){
		printf("%s\n", "一般的な賃金形態のほうが高賃金");
	} else{
		printf("%s\n", "再帰的な賃金形態のほうが高賃金");
	}
	

	// 終了前にキー入力待ち
	std::cin.get();
	return 0;
}