#include <iostream>
using namespace std;

int const PATHWAY = 0;  // 통로
int const WALL = 1;     // 벽
int const BOMB = 2;     // 폭탄
int const VISITED = 3;  // 방문한 길

int N, K;
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

bool findPath(int x, int y, int injury) {
  // 도착 경우
  if (x == N - 1 && y == N - 1) {
    return true;
  }

  // 부상 횟수 초과 시 실패
  if (injury > K) {
    return false;
  }

  int original = maze[x][y];  // 원래 값 저장
  maze[x][y] = VISITED;       // 방문 처리

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + offset[dir][0];
    int ny = y + offset[dir][1];

    if (nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] != WALL) {
      if (maze[nx][ny] == PATHWAY) {
        if (findPath(nx, ny, injury)) {
          return true;
        }
      } else if (maze[nx][ny] == BOMB) {
        if (findPath(nx, ny, injury + 1)) {
          return true;
        }
      }
    }
  }

  maze[x][y] = original;  // 원상 복구
  return false;
}

int main() {
  input();
  if (findPath(0, 0, 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}