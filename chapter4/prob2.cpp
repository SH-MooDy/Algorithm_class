#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> nums;

void inputFile() {
  cin >> N;
  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    nums.push_back(num);
  }
}

// 트리의 높이를 구하는 함수
int calHeight(int left, int right) {
  // 트리가 비어있는 경우
  if (left > right) {
    return 0;
  }
  // 높이가 1인경우
  if (left == right) {
    return 1;
  }

  // 후순위 배열에서 마지막 요소가 루트
  int root = nums[right];

  // 왼쪽 서브트리 구간 찾기
  int mid = left;
  while (mid < right && nums[mid] < root) {
    mid++;
  }

  // 오른쪽 서브트리가 모두 root보다 큰지 확인
  for (int i = mid; i < right; i++) {
    // BST의 후순위 순열이 아닌경우
    if (nums[i] < root) {
      return -1;
    }
  }

  // 왼쪽 서브트리 높이 계산
  int lh = calHeight(left, mid - 1);
  if (lh == -1) {
    return -1;
  }

  // 오른쪽 서브트리 높이 계산
  int rh = calHeight(mid, right - 1);
  if (rh == -1) {
    return -1;
  }

  // 현재 트리 높이
  return 1 + max(lh, rh);
}

int main() {
  inputFile();
  int height = calHeight(0, N - 1);
  cout << height << endl;
  return 0;
}

/**
 * 일단 기본적인 로직은 후순위 배열에서 가장 뒤에 오는 요소가 루트
 * 파티션 문제처럼 루트를 기준으로 배열을 두개로 나누기
 * 리커젼으로 왼쪽, 오른쪽 각각의 높이를 구하면 가능하지 않을까?
 */