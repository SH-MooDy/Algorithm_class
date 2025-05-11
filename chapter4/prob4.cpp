#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 한 사람에 대한 정보를 저장하는 클래스
class Person {
 public:
  string name, company, address, zipcode, phone, email;

  Person() = default;
  // 생성자
  Person(string name, string company, string address, string zipcode,
         string phone, string email)
      : name(name),
        company(company),
        address(address),
        zipcode(zipcode),
        phone(phone),
        email(email) {}
};

// 이진 검색 트리의 노드를 나타내는 구조체
struct Node {
  Person data;
  Node* parent;
  Node* left;
  Node* right;

  Node(Person& p) : data(p), parent(nullptr), left(nullptr), right(nullptr) {}
};

class BST {
 private:
  Node* root;

  // 한 사람 정보를 출력
  void print_info(Node* node) {
    cout << node->data.name << endl
         << "   Company: " << node->data.company << endl
         << "   Address: " << node->data.address << endl
         << "   Zipcode: " << node->data.zipcode << endl
         << "   Phone: " << node->data.phone << endl
         << "   Email: " << node->data.email << endl;
  }

  // 트리를 중순위로 순회하면서 출력
  void printInorder(Node* node) {
    if (!node) return;
    printInorder(node->left);
    print_info(node);
    printInorder(node->right);
  }

  // 중순위로 일치하는 이름을 탐색
  Node* findByName(Node* node, string& find_name) {
    if (!node) return nullptr;

    if (Node* found = findByName(node->left, find_name)) {
      return found;
    }
    if (node->data.name == find_name) {
      return node;
    }

    return findByName(node->right, find_name);
  }

  // 중순위로 순회하며 저장
  void saveInorder(Node* node, ofstream& outfile) {
    if (!node) return;
    saveInorder(node->left, outfile);

    outfile << node->data.name << '\t' << node->data.company << '\t'
            << node->data.address << '\t' << node->data.zipcode << '\t'
            << node->data.phone << '\t' << node->data.email << '\n';

    saveInorder(node->right, outfile);
  }

  // 삭제를 위한 메서드들
  // 서브트리 최솟값을 반환
  Node* minimum(Node* x) {
    while (x->left) {
      x = x->left;
    }
    return x;
  }

  // u노드를 v노드로 대체
  void transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v) {
      v->parent = u->parent;
    }
  }

  // 노드 삭제 로직
  void eraseNode(Node* z) {
    if (!z->left) {
      // 왼쪽 자식인 없으면 오른쪽 자식으로 대체
      transplant(z, z->right);
    } else if (!z->right) {
      // 오른쪽 자식이 없으면 왼쪽 자식으로 대체
      transplant(z, z->left);
    } else {
      // 두자식이 모두 있는 경우
      Node* y = minimum(z->right);  // 오른쪽 서브트리 최솟값
      if (y->parent != z) {
        // y를 y의 오른쪽 자식으로 대체
        transplant(y, y->right);
        y->right = z->right;  // z의 오른쪽을 y에 연결
        y->right->parent = y;
      }
      // z를 y로 대체
      transplant(z, y);
      y->left = z->left;  // z의 왼쪽을 y에 연결
      y->left->parent = y;
    }
    delete z;
  }

 public:
  BST() : root(nullptr) {}  // 생성자, 루트를 mullptr로 초기화

  // 출력
  void printList() { printInorder(root); }

  // 삽입
  void insert(Person& p) {
    Node* newNode = new Node(p);
    if (!root) {
      root = newNode;
      return;
    }
    Node* cur = root;
    Node* parent = nullptr;
    while (cur) {
      parent = cur;
      if (p.name < cur->data.name)
        cur = cur->left;
      else
        cur = cur->right;
    }
    newNode->parent = parent;
    if (p.name < parent->data.name)
      parent->left = newNode;
    else
      parent->right = newNode;
  }

  // 검색
  void findAndPrint(string& name) {
    Node* node = findByName(root, name);
    if (node == nullptr) {
      cout << name << " does not exist" << endl;
      return;
    }
    print_info(node);
  }

  Node* find(string& name) { return findByName(root, name); }

  // 추가
  void add(string& name) {
    Person p;
    p.name = name;
    cout << "Company? ";
    getline(cin, p.company);
    cout << "Address? ";
    getline(cin, p.address);
    cout << "Zipcode? ";
    getline(cin, p.zipcode);
    cout << "phone? ";
    getline(cin, p.phone);
    cout << "Email? ";
    getline(cin, p.email);

    insert(p);
    cout << name << " was successfully added." << endl;
  }

  // 추적
  void trace(string& name) {
    Node* cur = root;
    while (cur) {
      cout << cur->data.name << endl;
      if (name == cur->data.name) {
        return;
      }

      if (name < cur->data.name) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    cout << name << " does not exist" << endl;
  }

  // 삭제
  void remove(string& name) {
    Node* z = findByName(root, name);
    if (!z) {
      cout << name << " does net exist" << endl;
      return;
    }
    eraseNode(z);
  }

  // 저장
  void save(string& fileName) {
    ofstream outfile(fileName);

    outfile << "name\tcompany_name\taddress\tzip\tphone\temail\n";  // 헤더부분
    saveInorder(root, outfile);

    outfile.close();
  }
};

// 문자열에서 큰 따옴표 제거
string extractQuoted(string s) {
  size_t start = s.find('"');
  if (start == string::npos) return "";

  size_t end = s.find('"', start + 1);
  if (end == string::npos) return "";

  return s.substr(start + 1, end - start - 1);
}

// 파일 읽기
void readFile(string fileName, BST& bst) {
  ifstream infile(fileName);
  string line;
  getline(infile, line);  // 첫줄 무시

  while (getline(infile, line)) {
    stringstream ss(line);
    Person p;
    string tmp;
    getline(ss, p.name, '\t');
    getline(ss, tmp, '\t');
    {
      string inner = extractQuoted(tmp);
      p.company = inner.empty() ? tmp : inner;
    }
    getline(ss, tmp, '\t');
    {
      string inner = extractQuoted(tmp);
      p.address = inner.empty() ? tmp : inner;
    }

    getline(ss, p.zipcode, '\t');
    getline(ss, p.phone, '\t');
    getline(ss, p.email, '\t');
    bst.insert(p);
  }
  infile.close();
}

int main() {
  BST address_list;
  string input, command, arg;
  while (true) {
    cout << "$ ";
    getline(cin, input);

    stringstream ss(input);
    ss >> command >> arg;

    if (command == "exit") {
      break;
    } else if (command == "read") {
      readFile(arg, address_list);
    } else if (command == "list") {
      address_list.printList();
    } else if (command == "find") {
      address_list.findAndPrint(arg);
    } else if (command == "add") {
      // 중복검사
      if (address_list.find(arg) != nullptr) {
        cout << arg << " already exists" << endl;
        continue;
      }
      // 추가
      address_list.add(arg);
    } else if (command == "trace") {
      address_list.trace(arg);
    } else if (command == "delete") {
      address_list.remove(arg);
    } else if (command == "save") {
      address_list.save(arg);
    }
  }

  return 0;
}
