#include <iostream>
using namespace std;

const int MAX_N = 16;
int N, K, count = 0;
;
int maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maze[i][j];
    }
  }
  cin >> K;
}

void dfs(int x, int y, int length) {
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

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == 0 &&
        !visited[nx][ny]) {
      visited[nx][ny] = true;   // 방문 처리
      dfs(nx, ny, length + 1);  // 재귀 호출
      visited[nx][ny] = false;  // 원상 복구
    }
  }
}

int main() {
  input();
  visited[0][0] = true;
  dfs(0, 0, 0);

  cout << count << endl;
  return 0;
}