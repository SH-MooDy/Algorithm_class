#include <time.h>

#include <algorithm>
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

// 버블 정렬
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

  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

// 삽입 정렬
void insertion_sort(vector<string> v) {
  int n = v.size();
  clock_t start, finish;

  start = clock();
  for (int i = 1; i < n; i++) {
    string key = v[i];
    int j = i - 1;

    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
  finish = clock();

  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

// 병합 정렬
void merge(vector<string>& v, int left, int mid, int right) {
  int i = left, j = mid + 1;
  vector<string> temp;

  while (i <= mid && j <= right) {
    if (v[i] <= v[j])
      temp.push_back(v[i++]);
    else
      temp.push_back(v[j++]);
  }
  while (i <= mid) temp.push_back(v[i++]);
  while (j <= right) temp.push_back(v[j++]);

  for (int k = 0; k < temp.size(); ++k) v[left + k] = temp[k];
}

void merge_sort_rec(vector<string>& v, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort_rec(v, left, mid);
    merge_sort_rec(v, mid + 1, right);
    merge(v, left, mid, right);
  }
}

void merge_sort(vector<string> v) {
  clock_t start, finish;
  start = clock();

  merge_sort_rec(v, 0, v.size() - 1);

  finish = clock();
  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

// 퀵 정렬
int partition(vector<string>& v, int low, int high) {
  string pivot = v[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (v[j] <= pivot) {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i + 1], v[high]);
  return i + 1;
}

void quick_sort_rec(vector<string>& v, int low, int high) {
  if (low < high) {
    int pi = partition(v, low, high);
    quick_sort_rec(v, low, pi - 1);
    quick_sort_rec(v, pi + 1, high);
  }
}

void quick_sort(vector<string> v) {
  clock_t start, finish;
  start = clock();

  quick_sort_rec(v, 0, v.size() - 1);

  finish = clock();
  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

// 힙 정렬
void heapify(vector<string>& v, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && v[left] > v[largest]) largest = left;

  if (right < n && v[right] > v[largest]) largest = right;

  if (largest != i) {
    swap(v[i], v[largest]);
    heapify(v, n, largest);
  }
}

void heap_sort(vector<string> v) {
  int n = v.size();
  clock_t start, finish;
  start = clock();

  for (int i = n / 2 - 1; i >= 0; i--) heapify(v, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(v[0], v[i]);
    heapify(v, i, 0);
  }

  finish = clock();
  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

// STL sort
void stdLibrary_sort(vector<string> v) {
  clock_t start, finish;
  start = clock();

  sort(v.begin(), v.end());

  finish = clock();
  double duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << duration << endl;
}

int main() {
  vector<string> words = input_file();

  bubble_sort(words);
  insertion_sort(words);
  merge_sort(words);
  quick_sort(words);
  heap_sort(words);
  stdLibrary_sort(words);

  return 0;
}
