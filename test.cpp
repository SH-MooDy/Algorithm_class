#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
using namespace std;
using namespace chrono;

// ���� ��� �Լ� ���� (O(n))
void fun1(int n) {
    volatile int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
}

// ����
int main() {
    vector<int> inputs = {1000, 2000, 4000, 8000, 16000};
    cout << "�Է� ũ��\t�ɸ� �ð� (ms)" << endl;

    for (int n : inputs) {
        auto start = high_resolution_clock::now();
        fun1(n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << n << "\t\t" << duration.count() << " ms" << endl;
    }

    return 0;
}
