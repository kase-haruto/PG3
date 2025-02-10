#include <iostream>
#include <string>
#include <chrono>

/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////
int main(){
    const size_t kStringLength = 100000;
    std::string originalString(kStringLength, 'a');

    // 計測開始めっせーじ
    std::cout << kStringLength << "文字を移動とコピーで比較しました。\n";

    // -----------------------------
    // copy にかかる時間
    // -----------------------------
    auto copyStart = std::chrono::high_resolution_clock::now();
    // コピーコンストラクタ
    std::string copyConstructedString = originalString;
    auto copyEnd = std::chrono::high_resolution_clock::now();

    // duration_cast でマイクロ秒単位の整数に変換して取得
    auto copyTime = std::chrono::duration_cast< std::chrono::microseconds >(
        copyEnd - copyStart).count();

    // -----------------------------
    // move にかかる時間
    // -----------------------------
    auto moveStart = std::chrono::high_resolution_clock::now();
    // ムーブコンストラクタ
    std::string moveConstructedString = std::move(originalString);
    auto moveEnd = std::chrono::high_resolution_clock::now();

    auto moveTime = std::chrono::duration_cast< std::chrono::microseconds >(
        moveEnd - moveStart).count();

    // 結果の出力
    std::cout << "コピー: " << copyTime << "us\n";
    std::cout << "移動: " << moveTime << "us\n";

    // プログラムの終了前に一時停止
    std::cout << "続行するには何かキーを押してください・・・";
    std::cin.get();

    return 0;
}