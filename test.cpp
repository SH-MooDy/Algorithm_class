#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
using namespace std;
using namespace chrono;

// 측정 대상 함수 예시 (O(n))
void fun1(int n) {
    volatile int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
}

// 메인
int main() {
    vector<int> inputs = {1000, 2000, 4000, 8000, 16000};
    cout << "입력 크기\t걸린 시간 (ms)" << endl;

    for (int n : inputs) {
        auto start = high_resolution_clock::now();
        fun1(n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << n << "\t\t" << duration.count() << " ms" << endl;
    }

    return 0;
}
