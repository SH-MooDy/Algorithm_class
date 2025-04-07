#include <time.h>

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// 파일의 단어들을 불러오는 함수
vector<string> input_file() {
  vector<string> words;
  ifstream infile("harry_full.txt");
  string word;
  while (infile >> word) {
    words.push_back(word);
  }
  return words;
}

void bubble_sort(vector<string> v) {
  int n = v.size();
  clock_t start, finish;

  start = clock();
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < i - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
  finish = clock();

  double duration = finish - start / CLOCKS_PER_SEC;

  cout << duration << endl;
}

void insertion_sort(vector<string> v) {}

void merge_sort(vector<string> v) {}

void quick_sort(vector<string> v) {}

void heap_sort(vector<string> v) {}

void stdLibaray_sort(vector<string> v) {}

int main() {
  vector<string> words = input_file();
  bubble_sort(words);
  insertion_sort(words);
  merge_sort(words);
  quick_sort(words);
  heap_sort(words);
  stdLibaray_sort(words);
  return 0;
}