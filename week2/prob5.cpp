#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

const int PATHWAY = 0;  // 통로
const int WALL = 1;     // 벽
const int VISITED = 2;  // 방문한 길

int N, K, min_rest = INT_MAX;
int maze[20][20];
int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void input() {
  ifstream infile("maze.txt");
  infile >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      infile >> maze[i][j];
    }
  }
  infile >> K;
  infile.close()
}

void findPath(int x, int y, int rest, int direction) {
  if (rest >= min_rest) {  // 최선의 경우를 벗어나는 경우를 알 필요X
    return;
  }

  if (x == N - 1 && y == N - 1) {  // 도착 후 휴식 횟수 최솟값 갱신
    min_rest = rest;
    return;
  }

  maze[x][y] = VISITED;  // 방문 처리

  for (int dir = 0; dir < 4; dir++) {
    int nx = x, ny = y;
    bool isMoved = false;

    for (int dist = 1; dist <= K; dist++) {
      nx += offset[dir][0];
      ny += offset[dir][1];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N || maze[nx][ny] != PATHWAY) {
        break;  // 갈 수 있는 길이 없는 경우 중단
      }

      isMoved = true;

      // 한 번 이동 후 휴식
      findPath(nx, ny, rest + 1, dir);
    }
  }
  maze[x][y] = PATHWAY;  // 방문 해제
}

int main() {
  input();
  maze[0][0] = VISITED;  // 시작점 방문 처리
  findPath(0, 0, 0, -1);
  if (min_rest == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << min_rest << endl;
  }
  return 0;
}
