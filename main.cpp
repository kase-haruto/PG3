#include <iostream>
#include <type_traits>


#include <list>
#include <iterator>
#include <cstring>


/////////////////////////////////////////////////////////////////////////////////////////
//                  function
/////////////////////////////////////////////////////////////////////////////////////////
void  DisplayStations(const std::list<const char*>& stations){
    for (const char* station : stations){
        std::cout << station << " -> ";
    }
}


/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////

int main(){
  
    // 1970年の初期駅リスト
    std::list<const char*> stations1970 = {
        "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
        "Meguro", "Gotanda", "Osaki", "Shinagawa",
        "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho",
        "Tokyo", "Kanda", "Akihabara", "Okachimachi",
        "Ueno", "Uguisudani", "Nippori", "Tabata",
        "Komagome", "Sugamo", "Otsuka", "Ikebukuro"
    };

    std::cout << "Stations (1970:" << std::endl;
     DisplayStations(stations1970);
    std::cout << "\n" << std::endl;

    // 西日暮里駅を追加
    auto it = std::find(stations1970.begin(), stations1970.end(), "Nippori");
    if (it != stations1970.end()){
        stations1970.insert(std::next(it), "Nishi-Nippori");
    }

    std::cout << "Stations (2019 :" << std::endl;
     DisplayStations(stations1970);
    std::cout << "\n" << std::endl;

    // 高輪ゲートウェイ駅を追加
    it = std::find(stations1970.begin(), stations1970.end(), "Shinagawa");
    if (it != stations1970.end()){
        stations1970.insert(std::next(it), "Takanawa Gateway");
    }

    std::cout << "Stations (2022:" << std::endl;
     DisplayStations(stations1970);
    std::cout << "\n" << std::endl;

    // プログラムの終了前に一時停止
    std::cin.get();
	return 0;
}