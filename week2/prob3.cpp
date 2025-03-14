#include <iostream>
using namespace std;

int n;
int maze[16][16];

void inputMaze() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
    }
  }
}
int main() {
  inputMaze();

  return 0;
}