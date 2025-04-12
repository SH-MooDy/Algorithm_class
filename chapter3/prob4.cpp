#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// 점의 위치를 나타내는 구조체
struct Point {
  int x, y;  // x좌표, y좌표
};

// 우회전, 좌회전 계산
int crossProduct(const Point& O, const Point& A, const Point& B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 점들로부터 Convex Hull을 구하는 함수
// 결과는 반시계 방향으로 정렬된 점들의 리스트로 반환
vector<Point> convexHull(vector<Point>& points) {
  // 점들을 x 좌표 기준으로 정렬 (x가 같으면 y 기준으로)
  sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });

  vector<Point> lower;
  vector<Point> upper;

  // 아래쪽 hull을 구성
  for (const auto& p : points) {
    // 세 점이 시계 방향 또는 일직선이면 마지막 점 제거
    while (lower.size() >= 2 && crossProduct(lower[lower.size() - 2],
                                             lower[lower.size() - 1], p) <= 0) {
      lower.pop_back();
    }
    lower.push_back(p);
  }

  // 위쪽 hull을 구성
  for (auto it = points.rbegin(); it != points.rend(); ++it) {
    while (upper.size() >= 2 &&
           crossProduct(upper[upper.size() - 2], upper[upper.size() - 1],
                        *it) <= 0) {
      upper.pop_back();
    }
    upper.push_back(*it);
  }

  // 양쪽 끝 점이 중복되므로로 마지막 점 제거
  lower.pop_back();
  upper.pop_back();

  // 결과 결합
  vector<Point> result;

  for (auto it = upper.rbegin(); it != upper.rend(); ++it) {
    result.push_back(*it);
  }

  for (auto it = lower.rbegin(); it != lower.rend(); ++it) {
    result.push_back(*it);
  }

  return result;
}

int main() {
  ifstream inFile("input.txt");

  int n;  // 점의 개수
  inFile >> n;

  vector<Point> points(n);  // 입력 점들을 저장할 벡터
  for (int i = 0; i < n; ++i) {
    inFile >> points[i].x >> points[i].y;
  }

  inFile.close();

  vector<Point> hull = convexHull(points);

  for (const auto& p : hull) {
    cout << p.x << " " << p.y << endl;
  }

  return 0;
}
