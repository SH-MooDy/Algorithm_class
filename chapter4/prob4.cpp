#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Person {
 public:
  string name, company, address, zip, phone, email;

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
