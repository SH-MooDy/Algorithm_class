#include <iostream>
using namespace std;

int N, K;
int arr[1000];

int findRank(int index, int rank) {
  if (index == N) {
    return rank + 1;
  }

  if (arr[index] < K) {
    return findRank(index + 1,
                    rank + 1);  // 요소가 K보다 작다면 인덱스, rank 증가
  } else {
    return findRank(index + 1, rank);  // 요소가 K 이상이면 인덱스만 증가
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  cin >> K;

  cout << findRank(0, 0) << endl;
  return 0;
}