#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> nums;

void postToPre(int left, int right) {
  // 빈 트리면 종류
  if (left > right) return;

  // 루트 노드를 먼저 출력
  cout << nums[right] << " ";

  // 후순위 배열에서 둘로 나뉘는 부분 탐색
  int mid = left;
  while (mid <= right - 1 && nums[mid] < nums[right]) {
    mid++;
  }

  // 왼쪽 서브트리 탐색
  postToPre(left, mid - 1);
  // 오른쪽 서브트리 탐색
  postToPre(mid, right - 1);
  return;
}

void inputFile() {
  cin >> N;
  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    nums.push_back(num);
  }
}

int main() {
  inputFile();
  postToPre(0, N - 1);
  cout << endl;
  return 0;
}

/**
 * 후순위의 경우 제일 마지막 노드가 루트
 * 노드를 기준으로 배열을 둘로 나누고 또 그배열에서 제일 마지막이 루트
 * 전순위로 출력해야 하므로 우선 루트 출력
 * 배열의 앞부터 탐색해서 둘로 나눌 수 있는 기점 발견 후 리커젼으로 반복
 */