#include <iostream>
using namespace std;

int N, K;
int arr[1000];

int findRank(int idx, int rank) {
  if (idx == N) {
    return rank + 1;
  }

  if (arr[idx] < K) {
    return findRank(idx + 1, rank + 1);
  } else {
    return findRank(idx + 1, rank);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  cin >> K;

  int rank = 0;
  cout << findRank(0, rank) << endl;
  return 0;
}