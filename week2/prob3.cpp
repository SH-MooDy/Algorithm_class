#include <iostream>
using namespace std;

int N, K;
int maze[16][16];

void inputMaze() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maze[i][j];
    }
  }
  cin >> K;
}
int main() {
  inputMaze();

  return 0;
}