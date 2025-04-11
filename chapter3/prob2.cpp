#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Person {
 public:
  string name, company, address, zipcode, phone, email;

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

vector<Person> people;

// 파일 읽기
void read_file(string fileName) {
  ifstream infile(fileName);
  string line;
  while (getline(infile, line)) {
    stringstream ss(line);
    string name, company, address, zipcode, phone, email;

    getline(ss, name, '|');
    getline(ss, company, '|');
    getline(ss, address, '|');
    getline(ss, zipcode, '|');
    getline(ss, phone, '|');
    getline(ss, email, '|');

    Person P(name, company, address, zipcode, phone, email);
    people.push_back(P);
  }
}

// 모든 사람에 대한 정보를 출력
void print_all() {
  for (const auto& p : people) {
    cout << p.name << endl;
    cout << "\tCompany: " << p.company << endl;
    cout << "\tAddress: " << p.address << endl;
    cout << "\tZipcode: " << p.zipcode << endl;
    cout << "\tPhones: " << p.phone << endl;
    cout << "\tEmail: " << p.email << endl;
  }
}

// 정렬을 위한 함수
template <typename Compare>
void sort_people(Compare comp) {
  sort(people.begin(), people.end(), comp);
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
    } else if (command == "print") {
      print_all();
    } else if (command == "sort") {
      if (option == "-name") {
        sort_people(
            [](const Person& a, const Person& b) { return a.name < b.name; });
      } else if (option == "-address") {
        sort_people([](const Person& a, const Person& b) {
          return a.address < b.address;
        });
      } else if (option == "-company") {
        sort_people([](const Person& a, const Person& b) {
          return a.company < b.company;
        });
      } else if (option == "-zipcode") {
        sort_people([](const Person& a, const Person& b) {
          return a.zipcode < b.zipcode;
        });
      } else if (option == "-phones") {
        sort_people(
            [](const Person& a, const Person& b) { return a.phone < b.phone; });
      } else if (option == "-email") {
        sort_people(
            [](const Person& a, const Person& b) { return a.email < b.email; });
      }
    }
  }
  return 0;
}