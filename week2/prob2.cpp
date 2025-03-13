#include <iostream>
using namespace std;

int arr[1000];
int N, K;

int nearest(int target, int begin, int end) {
  int middle = (begin + 2) / 2;

  if (end - begin == 2) {
    if () } else {
    if (arr[middle] == target) {
      return middle;
    } else if (arr[middle] > target) {
      return nearest(target, begin, middle - 1);
    } else {
      return nearest(target, middle + 1, end);
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  cin >> K;

  cout << nearest(K, 0, N - 1) << endl;
  return 0;
}

// 바이너리 서치 해야할듯?