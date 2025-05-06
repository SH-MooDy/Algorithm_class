#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// 각 노드들의 정보를 저장하는 구조체
struct Node {
  int right;
  int left;
};

int N;
vector<Node> node_list;
vector<bool> isChild;

void inputFile() {
  ifstream infile("input1.txt");
  infile >> N;

  node_list.assign(N, {-1, -1});
  isChild.assign(N, false);

  for (int i = 0; i < N; i++) {
    int id, l, r;
    infile >> id >> l >> r;
    node_list[id].left = l;
    node_list[id].right = r;

    // 어떤 노드의 자식인지 기록
    if (l != -1) {
      isChild[l] = true;
    }
    if (r != -1) {
      isChild[r] = true;
    }
  }
}

void preOrder(int i) {
  if (i == -1) return;
  cout << i << " ";
  preOrder(node_list[i].left);
  preOrder(node_list[i].right);
}

void inOrder(int i) {
  if (i == -1) return;
  inOrder(node_list[i].left);
  cout << i << " ";
  inOrder(node_list[i].right);
}

void postOrder(int i) {
  if (i == -1) return;
  postOrder(node_list[i].left);
  postOrder(node_list[i].right);
  cout << i << " ";
}

int main() {
  inputFile();

  // 루트 찾기
  int root = 0;
  for (int i = 0; i < N; i++) {
    if (!isChild[i]) {
      root = i;
      break;
    }
  }

  preOrder(root);
  cout << endl;

  inOrder(root);
  cout << endl;

  postOrder(root);
  cout << endl;
  return 0;
}
