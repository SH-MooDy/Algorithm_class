#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// 각 노드들의 정보를 저장하는 구조체
struct Node {
  int current;
  int right;
  int left;
};

int N;
vector<int> node_list;

void inputFile() {
  ifstream infile("input1.txt");
  infile >> N;

  for (int i = 0; i < N; i++) {
    Node node;
    infile >> node.current >> node.left >> node.right;
    // 노드를 node_list 벡터에 저장
    node_list.push_back(node);
  }
}

void preOrder(Node node) {
  cout << node.current << " ";

  find()
}

int main() {
  inputFile();

  return 0;
}

/**
 * struct Node {
    int left, right;
};

vector<Node> tree(N);
vector<bool> isChild(N, false);

// 입력 처리
for (int i = 0; i < N; ++i) {
    int node, l, r;
    cin >> node >> l >> r;
    tree[node] = {l, r};
    if (l != -1) isChild[l] = true;
    if (r != -1) isChild[r] = true;
}

// 루트 찾기
int root = -1;
for (int i = 0; i < N; ++i)
    if (!isChild[i]) root = i;s

// 순회 함수
void preorder(int cur) {
    if (cur == -1) return;
    cout << cur << ' ';
    preorder(tree[cur].left);
    preorder(tree[cur].right);
}
void inorder(int cur) {
    if (cur == -1) return;
    inorder(tree[cur].left);
    cout << cur << ' ';
    inorder(tree[cur].right);
}
void postorder(int cur) {
    if (cur == -1) return;
    postorder(tree[cur].left);
    postorder(tree[cur].right);
    cout << cur << ' ';
}

// 호출
preorder(root); cout << endl;
inorder(root); cout << endl;
postorder(root); cout << endl;

 */