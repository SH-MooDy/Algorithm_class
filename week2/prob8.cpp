#include <fstream>
#include <iostream>
using namespace std;

int N, W;
int weight[16], value[16];

void input() {
  ifstream infile("input.txt");

  infile >> N >> W;
  for (int i = 0; i < N; i++) {
    infile >> weight[i];
  }

  for (int i = 0; i < N; i++) {
    infile >> value[i];
  }
}

int main() {
  input();
  return 0;
}