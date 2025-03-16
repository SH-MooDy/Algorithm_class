#include <fstream>
#include <iostream>
using namespace std;

int maze[20][20];

void input() {
  ifstream infile("maze.txt");

  infile >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      infile >> maze[i][j];
    }
  }
  infile >> K;
}
int main() {
  input();
  return 0;
}