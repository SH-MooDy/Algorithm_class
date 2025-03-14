#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000];

int binarySearch(int begin, int end, int K) {
  if (begin >= end) {
    return begin;
  }

  int middle = (begin + end) / 2;

  if (arr[middle] < K) {
    return binarySearch(middle + 1, end, K);
  } else {
    return binarySearch(begin, middle, K);
  }
}

int nearest(int N, int K) {
  int idx = binarySearch(0, N, K);

  if (idx == 0) {
    return arr[0];
  }
  if (idx == N) {
    return arr[N - 1];
  }

  if (abs(arr[idx] - K) < abs(arr[idx - 1] - K)) {
    return arr[idx];
  } else {
    return arr[idx - 1];
  }
}
int main() {
  int N, K;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cin >> K;

  cout << nearest(N, K) << endl;
  return 0;
}

// 바이너리 서치 해야할듯?