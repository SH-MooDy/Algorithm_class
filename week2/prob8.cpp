#include <fstream>
#include <iostream>
using namespace std;

int N, W;  // 아이템 개수, 배낭 최대 무게
int weights[16], values[16];
int max_value = 0;

void knapsack(int index, int currentWeight, int currentValue) {
  // 모든 아이템을 확인한 경우
  if (index == N) {
    max_value = max(max_value, currentValue);
    return;
  }

  // 현재 아이템 포함X => 다음 아이템으로 이동
  knapsack(index + 1, currentWeight, currentValue);

  // 현재 아이템 포함 => 무게 제한 초과하지 않는다면 value 더해줌
  if (currentWeight + weights[index] <= W) {
    knapsack(index + 1, currentWeight + weights[index],
             currentValue + values[index]);
  }
}

void input() {
  ifstream infile("input.txt");

  infile >> N >> W;
  for (int i = 0; i < N; i++) {
    infile >> weights[i];
  }

  for (int i = 0; i < N; i++) {
    infile >> values[i];
  }

  infile.close();
}

int main() {
  input();

  knapsack(0, 0, 0);
  cout << max_value << endl;
  return 0;
}