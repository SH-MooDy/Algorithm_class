#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Dot;

int ccw(Dot a, Dot b, Dot c) {
  return (b.first - a.first) * (c.second - a.second) -
         (b.second - a.second) * (c.first - a.first);
}

// 탄젠트를 찾기 위한 함수
bool is_clockwise(Dot a, Dot b, Dot c) { return ccw(a, b, c) < 0; }
bool is_counter_clockwise(Dot a, Dot b, Dot c) { return ccw(a, b, c) > 0; }

// merge 함수
vector<Dot> merge(const vector<Dot>& left, const vector<Dot>& right) {
  int n1 = left.size(), n2 = right.size();
  int i = 0, j = 0;

  // 오른쪽 hull에서 가장 왼쪽 점 찾기
  for (int k = 1; k < n2; k++) {
    if (right[k].first < right[j].first) {
      j = k;
    }
  }

  // 왼쪽 hull에서 가장 오른쪽 점 찾기
  for (int k = 1; k < n1; k++) {
    if (left[k].first > left[i].first) {
      i = k;
    }
  }

  int upper_i = i, upper_j = j;

  // upper tangent
  bool done = false;
  while (!done) {
    done = true;
    while (is_counter_clockwise(right[upper_j], left[upper_i],
                                left[(upper_i + 1) % n1])) {
      upper_i = (upper_i + 1) % n1;
    }
    while (is_clockwise(left[upper_i], right[upper_j],
                        right[(n2 + upper - 1) % n2])) {
      upper_j = (n2 + upper_j - 1) % n2;
      done = false;
    }
  }

  int lower_i = i, lower_j = j;
  // lower tangent
}
int main() { return 0; }