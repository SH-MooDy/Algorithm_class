#include <iostream>
using namespace std;

const int PATHWAY = 0;  // 이동 가능한 공간
const int WALL = 1;     // 벽
const int VISITED = 2;  // 방문한 길

int N, K, count = 0;
int maze[16][16];
int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maze[i][j];
    }
  }
  cin >> K;
}

void findPath(int x, int y, int length) {
  // 도착 지점
  if (x == N - 1 && y == N - 1) {
    if (length <= K) {
      count++;
    }
    return;
  }

  if (length > K) {
    return;
  }

  // 현재 위치 방문 처리
  maze[x][y] = VISITED;

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + offset[dir][0];
    int ny = y + offset[dir][1];

    // 이동 가능한 범위인 경우
    if (nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == PATHWAY) {
      findPath(nx, ny, length + 1);
    }
  }

  // 방문 해제
  maze[x][y] = PATHWAY;
}

int main() {
  input();
  findPath(0, 0, 0);

  cout << count << endl;
  return 0;
}
