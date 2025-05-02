#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  vector<int> node_list;
  vector<int> node;

  ifstream infile("input1.txt");
  infile >> N;

  for (int i = 0; i < N; i++) {
    int num, left_child, right_child;
    infile >> num >> left_child >> right_child;

    // 노드하나에 대한한 정보들을 node 벡터에 저장
    node.push_back(num);
    node.push_back(left_child);
    node.push_back(right_child);

    // 노드를 node_list 벡터에 저장
    node_list.push_back();
  }

  return 0;
}