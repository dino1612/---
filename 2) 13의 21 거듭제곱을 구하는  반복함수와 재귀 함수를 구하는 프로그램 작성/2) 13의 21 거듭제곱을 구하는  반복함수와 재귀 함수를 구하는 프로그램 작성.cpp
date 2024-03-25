#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 반복문을 사용하여 거듭제곱을 계산하는 함수
double power_iter(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// 재귀함수를 사용하여 거듭제곱을 계산하는 함수
double power_rec(double base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power_rec(base, exponent - 1);
}

int main() {
    double base = 13;
    int exponent = 21;

    // 반복문을 사용한 거듭제곱 함수 실행 시간 측정
    auto start_iter = high_resolution_clock::now();
    double result_iter = power_iter(base, exponent);
    auto stop_iter = high_resolution_clock::now();
    auto duration_iter = duration_cast<microseconds>(stop_iter - start_iter);

    // 재귀함수를 사용한 거듭제곱 함수 실행 시간 측정
    auto start_rec = high_resolution_clock::now();
    double result_rec = power_rec(base, exponent);
    auto stop_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<microseconds>(stop_rec - start_rec);

    // 결과 출력
    cout << "반복문을 사용한 거듭제곱 결과: " << result_iter << endl;
    cout << "반복문 실행 시간: " << duration_iter.count() << " 마이크로초" << endl;

    cout << "재귀함수를 사용한 거듭제곱 결과: " << result_rec << endl;
    cout << "재귀함수 실행 시간: " << duration_rec.count() << " 마이크로초" << endl;

    return 0;
}
