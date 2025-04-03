#include <algorithm>  // max() 함수 사용을 위해 필요
#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

int N, k;
int A[16][16];
int selected_players[16];
int max_ability = INT_MIN;  // 초기값을 최소값으로 설정

// 총 능력치 계산 함수
int calcAbility() {
  int ability = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      ability += A[selected_players[i]][selected_players[j]];
    }
  }
  return ability;
}

void makeTeam(int index, int count) {
  if (count == k) {  // K명 선택 완료
    max_ability = max(max_ability, calcAbility());
    return;
  }

  if (index == N) return;  // 모든 선수 확인 완료

  // 선수 미선택
  makeTeam(index + 1, count);

  // 선수 선택
  selected_players[count] = index;
  makeTeam(index + 1, count + 1);
}

void input() {
  ifstream infile("input9.txt");
  infile >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      infile >> A[i][j];
    }
  }
  infile >> k;
}

int main() {
  input();
  makeTeam(0, 0);
  cout << max_ability << endl;
  return 0;
}
