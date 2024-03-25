#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 재귀적으로 팩토리얼을 계산하는 함수
unsigned long long factorial_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main() {
    int num = 20;

    // 재귀적 함수 실행 시간 측정
    auto start_recursive = high_resolution_clock::now();
    unsigned long long result_recursive = factorial_recursive(num);
    auto stop_recursive = high_resolution_clock::now();
    auto duration_recursive = duration_cast<microseconds>(stop_recursive - start_recursive);

    // 결과와 실행 시간 출력
    cout << num << "의 팩토리얼은 " << result_recursive << "입니다." << endl;
    cout << "재귀적 실행 시간: " << duration_recursive.count() << " 마이크로초" << endl;

    return 0;
}
