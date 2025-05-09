// bool 배열을 추가해서 해결하는 방법 찾아보기
#include <iostream>
using namespace std;

int n;
int arr[20];
bool visited[20];

bool findPath(int pos) {
  if (pos >= n - 1) {  // 수열의 끝에 도착
    return true;
  }

  if (arr[pos] == 0 || visited[pos]) {  // 0에 도착 or 이미 방문한 경우 실패
    return false;
  }

  visited[pos] = true;  // 방문 처리

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