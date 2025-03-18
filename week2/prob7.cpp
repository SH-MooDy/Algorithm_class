#include <iostream>
using namespace std;

int n, count = 0;
int arr[16];

void findBinarySeq(int index, int num) {
  if (index != -1) {  // 첫 단계를 위한 예외처리
    arr[index] = num;
    // 연속으로 0이 나오면 중단, 수열 길이가 1인인 상태에서는 신경 쓸 필요 X
    if (arr[index - 1] == arr[index] && arr[index] == 0 && index > 0) {
      return;
    }

    // 수열이 끝까지 차면 count++
    if (index == n - 1) {
      count++;
      return;
    }
  }

  // 해당 위치에 0 or 1 배치 후 리커젼
  for (int i = 0; i < 2; i++) {
    findBinarySeq(index + 1, i);
  }
}

int main() {
  cin >> n;
  findBinarySeq(-1, 0);
  cout << count << endl;
  return 0;
}