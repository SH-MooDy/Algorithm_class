#include <time.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// 추상 클래스
class PriorityQueue {
 public:
  virtual void add(int val) = 0;   // 값을 추가
  virtual int extractMax() = 0;    // 최댓값 추출 후 삭제
  virtual bool empty() const = 0;  // 큐가 비었는지 확인
  virtual ~PriorityQueue() {}
};

// 정렬되지 않은 배열 방식
class UnsortedArrayPQ : public PriorityQueue {
  vector<int> data;

 public:
  // 삽입은 맨 뒤에 붙임
  void add(int val) override { data.push_back(val); }

  // 최댓값을 반환하면서 삭제
  int extractMax() override {
    auto it = max_element(data.begin(), data.end());
    int maxVal = *it;
    data.erase(it);
    return maxVal;
  }

  // 큐가 비었는지 확인
  bool empty() const override { return data.empty(); }
};

// 힙 기반 방식
class HeapPQ : public PriorityQueue {
  vector<int> heap;

  // 값을 넣을 때 위로 올라가면서 부모보다 크면 스왑
  void heapifyUp(int idx) {
    while (idx > 0) {
      int parent = (idx - 1) / 2;
      if (heap[parent] < heap[idx]) {
        swap(heap[parent], heap[idx]);
        idx = parent;
      } else {  // 힙 속성 만족 시 종료
        break;
      }
    }
  }

  // 최대값을 뽑은 후 아래로 내려가면서 자식과 swap
  void heapifyDown(int idx) {
    int size = heap.size();
    while (true) {
      int left = 2 * idx + 1;
      int right = 2 * idx + 2;
      int largest = idx;

      if (left < size && heap[left] > heap[largest]) {
        largest = left;
      }
      if (right < size && heap[right] > heap[largest]) {
        largest = right;
      }

      if (largest != idx) {  // 현재 노드가 가장 큰 값이 아니면 교환
        swap(heap[idx], heap[largest]);
        idx = largest;
      } else {
        break;
      }
    }
  }

 public:
  // 삽입
  void add(int val) override {
    heap.push_back(val);         // 값을 힙의 끝에 추가
    heapifyUp(heap.size() - 1);  // 힙 속성을 유지하기 위해 위로 올라감
  }

  // 최댓값 추출
  int extractMax() override {
    if (heap.empty()) {
      return -1;
    }
    int maxVal = heap[0];   // 루트 노드 저장
    heap[0] = heap.back();  // 마지막 요소를 루트로 이동
    heap.pop_back();        // 마지막 요소 제거
    heapifyDown(0);         // 힙 속성 유지 위해 아래로 보냄
    return maxVal;
  }

  bool empty() const override { return heap.empty(); }
};

// 테스트 함수
void test(PriorityQueue& pq, int N, int M) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> valDist(1, N);
  uniform_int_distribution<> coin(0, 1);

  for (int i = 0; i < N; ++i) pq.add(valDist(gen));

  for (int i = 0; i < M; ++i) {
    if (coin(gen) == 0 || pq.empty())
      pq.add(valDist(gen));
    else
      pq.extractMax();
  }
}

int main() {
  int N = 10000, M = 100000;

  // 배열 기반 방식
  {
    UnsortedArrayPQ unsortedPQ;
    clock_t start = clock();
    test(unsortedPQ, N, M);
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
  }

  // 힙 기반 방식
  {
    HeapPQ heapPQ;
    clock_t start = clock();
    test(heapPQ, N, M);
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
  }

  return 0;
}
