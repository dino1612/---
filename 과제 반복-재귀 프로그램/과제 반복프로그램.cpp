#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 반복문을 사용하여 팩토리얼을 계산하는 함수
unsigned long long factorial_iterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    int num = 20;

    // 반복문을 사용한 팩토리얼 함수 실행 시간 측정
    auto start_iterative = high_resolution_clock::now();
    unsigned long long result_iterative = factorial_iterative(num);
    auto stop_iterative = high_resolution_clock::now();
    auto duration_iterative = duration_cast<microseconds>(stop_iterative - start_iterative);

    // 결과와 실행 시간 출력
    cout << num << "의 팩토리얼은 " << result_iterative << "입니다." << endl;
    cout << "반복문 실행 시간: " << duration_iterative.count() << " 마이크로초" << endl;

    return 0;
}
