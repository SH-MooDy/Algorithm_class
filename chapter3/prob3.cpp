#include <fstream>
#include <iostream>
using namespace std;
int n;
int dot[100];

void input_file() {
  ifstream infile("input.txt");
  infile >> n;
  for (int i = 0; i < n; i++) {
    infile >> dot[i];
  }
}

int main() {
  input_file();
  return 0;
}