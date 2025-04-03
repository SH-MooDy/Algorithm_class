#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000];

// K 이상의 값이 처음 등장하는 위치를 찾는 바이너리 서치
int binarySearch(int begin, int end, int K) {
  if (begin >= end) {
    return begin;  // K 이상의 값이 처음 등장하는 위치 반환
  }

  int middle = (begin + end) / 2;

  if (arr[middle] < K) {
    // middle 값이 K보다 작으므로 오른쪽 탐색
    return binarySearch(middle + 1, end, K);
  } else {
    // middle 값이 K 이상이므로 왼쪽 탐색
    return binarySearch(begin, middle, K);
  }
}

// K와 가장 가까운 값을 찾는 함수
int nearest(int N, int K) {
  int index = binarySearch(0, N, K);  // K 이상의 첫 번째 위치 찾기

  // K보다 작은 값이 없는 경우
  if (index == 0) {
    return arr[0];
  }
  // K 이상의 값이 없는 경우
  if (index == N) {
    return arr[N - 1];
  }

  // K와 가장 가까운 값을 선택
  if (abs(arr[index] - K) < abs(arr[index - 1] - K)) {
    return arr[index];
  } else {
    return arr[index - 1];
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
