#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

int N, W;
int w[20], v[20], c[20];
int max_value = INT_MIN;

void input() {
  ifstream infile("input10.txt");
  infile >> N;

  for (int i = 0; i < N; i++) {
    infile >> w[i] >> v[i] >> c[i];
  }

  infile >> W;
}

void findMaxValue(int index, int currentWeight, int currentValue) {
  // 모든 아이템을 확인한 경우
  if (index == N) {
    max_value = max(max_value, currentValue);
    return;
  }

  // 현재 물건 미포함(폐기)
  findMaxValue(index + 1, currentWeight, currentValue - c[index]);

  // 현재 물건 포함
  if (currentWeight + w[index] <= W) {
    findMaxValue(index + 1, currentWeight + w[index], currentValue + v[index]);
  }
}

int main() {
  input();
  findMaxValue(0, 0, 0);
  cout << max_value << endl;
  return 0;
}