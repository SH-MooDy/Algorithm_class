#include <iostream>
using namespace std;

int n;
int arr[20];

bool findPath(int pos) {
  if (pos == n - 1) {  // 수열의 끝에 도착
    return true;
  }

  if (arr[pos] == 0) {  // 0에 도착 시 실패
    return false;
  }

  // 해당 칸의 수 이하 만큼 이동 가능
  for (int dist = 1; dist <= arr[pos]; dist++) {
    if (findPath(pos + dist)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (findPath(0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}