#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// 한 사람에 대한 정보를 저장하는 클래스
class Person {
 public:
  string name, company, address, zip, phone, email;

  Person() = default;
  // 생성자
  Person(string name, string company, string address, string zip, string phone,
         string email)
      : name(name),
        company(company),
        address(address),
        zip(zip),
        phone(phone),
        email(email) {}
};

vector<Person> people;

// 이진 검색 트리의 노드를 나타내는 구조체
struct Node {
  Person data;
  Node* parent;
  Node* leftC;
  Node* rightC;

  Node(Person& p) : data(p), parent(nullptr), left(nullptr), right(nullptr) {}
}

class BST {
 private:
  Node* root;

  void _printInorder(Node* node) const {
    if (!node) return;
    _printInorder(node->left);
    cout << node->data.name << endl;
    cout << "\tCompany: " << node->data.company << endl;
    cout << "\tAddress: " << node->data.address << endl;
    cout << "\tZipcode: " << node->data.zip << endl cout
         << "\tPhone: " << node->data.phone << endl;
    cout << "\tEmail: " << node->data.email << endl;
    _printInorder(node->right);
  }

 public:
  BST() : root(nullptr) {}  // 생성자, 루트를 pullptr로 초기화

  // 출력
  void print() const { _printInorder(root); }

  // 삽입
  void insert(const Person& p) {
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
};

// 파일 읽기
void read_file(string fileName) {
  ifstream infile(fileName);
  string line;

  getline(infile, line);  // 첫줄 무시

  while (getline(infile, line)) {
    stringstream ss(line);
    string name, company, address, zip, phone, email;

    getline(ss, name, '\t');
    getline(ss, company, '\t');
    getline(ss, address, '\t');
    getline(ss, zip, '\t');
    getline(ss, phone, '\t');
    getline(ss, email, '\t');

    Person P(name, company, address, zip, phone, email);
    people.push_back(P);
  }
}

int main() {
  string input;
  while (true) {
    cout << "$ ";
    getline(cin, input);

    string command, option;
    stringstream ss(input);
    ss >> command >> option;

    if (command == "exit") {
      break;
    } else if (command == "read") {
      read_file(option);
    } else if (command == "list") {
    } else if (command == "find") {
    } else if (command == "add") {
    } else if (command == "trace") {
    } else if (command == "delete") {
    } else if (command == "save") {
    }
  }

  return 0;
}
