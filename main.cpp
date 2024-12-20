

#include <iostream>
#include <type_traits>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int currentStep = 1; // 現在のステップ番号を管理

// 各スレッドが順番にメッセージを表示する関数
void printInOrder(int myStep, const std::string& msg){
    std::unique_lock<std::mutex> lock(mtx);
    // 自分の順番が来るまで待つ
    cv.wait(lock, [&] (){ return currentStep == myStep; });

    // メッセージを表示
    std::cout << msg << std::endl;

    // 次のステップに進む
    currentStep++;

    // 次のスレッドを起こす
    cv.notify_all();
}

/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////
int main(){
    // スレッドを生成
    std::thread t1(printInOrder, 1, "thread 1");
    std::thread t2(printInOrder, 2, "thread 2");
    std::thread t3(printInOrder, 3, "thread 3");

    // スレッドの終了を待つ
    t1.join();
    t2.join();
    t3.join();

    // プログラム終了前に一時停止
    std::cin.get();
    return 0;
}
