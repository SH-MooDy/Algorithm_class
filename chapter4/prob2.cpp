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
void calHeight(int left, int right, int height) {
  // 베이스 케이스
  if (left >= right) {
    cout << height + 1 << endl;
    return;
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
      cout << -1 << endl;
      return;
    }
  }

  calHeight(left, mid - 1, height + 1);
  calHeight(mid, right - 1, height + 1);
}

int main() {
  inputFile();
  calHeight(0, N - 1, 0);
  return 0;
}

/**
 * 일단 기본적인 로직은 후순위 배열에서 가장 뒤에 오는 요소가 루트
 * 이 루트값을 기준으로 크냐 작냐에 따라서 배열을 계속 2개로 쪼갬
 * 여기서 배열을 둘로 쪼갤 수 없는 경우(한쪽이 공집합인 경우는 제외) BST가 아님
 * 둘로 쪼개는 횟수를 세면 트리의 높이를 구할 수 있지 않을까?
 */