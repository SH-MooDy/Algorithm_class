#include <bits/stdc++.h>
using namespace std;

// Prefix 타입을  pair로 지정
typedef pair<string, string> Prefix;

// prefix를 키로 쓰기 위한 구조체
struct PrefixHash {
  // 주어진 prefix에 대한 해시 값을 계산
  size_t operator()(const Prefix& p) const {
    // 첫번째 해시와 두번째 해시를 결합
    return hash<string>()(p.first) ^
           (hash<string>()(p.second) << 1);  // 비트 패턴을 한 칸 왼쪽으로
                                             // 이동시켜 원래 값과 겹치지 않도록
  }
};

// 체인 텓ㄱ스트 생성기 클래스
class textGenerator {
 private:
  unordered_map<Prefix, vector<string>, PrefixHash> chain;

 public:
  // 생성할 최대 단어 수
  static const int MAX_WORDS = 100;

  // 단어 벡터를 읽어 체인 사전을 구성
  // words[i-2], words[i-1]를 prefix로, words[i]를 suffix로 매핑
  void build(vector<string>& words) {
    for (int i = 2; i < words.size(); i++) {
      Prefix key = make_pair(words[i - 2], words[i - 1]);
      chain[key].push_back(
          words[i]);  // 해당 prefix 뒤에 나올 수 있는 단어 추가
    }
  }

  // 시작 단어 두개로부터 텍스트 생성
  vector<string> generate(string& w1, string& w2, int max_words = MAX_WORDS) {
    // 결과에 시작 단어 두개를 추가
    vector<string> output;
    output.push_back(w1);
    output.push_back(w2);
    Prefix current = make_pair(w1, w2);  // 현재 prefix 설정

    mt19937 gen(random_device{}());

    for (int count = 2; count < max_words; count++) {
      auto it = chain.find(current);  // 현재 prefix의 suffix 목록을 검색
      if (it == chain.end() || it->second.empty()) {
        break;  // 더 이상 이어갈 suffix가 없는 경우 종료
      }
      const auto& suffixes = it->second;
      uniform_int_distribution<> dist(0, static_cast<int>(suffixes.size()) - 1);
      string next = suffixes[dist(gen)];  // 랜덤으로 다음 단어 선택
      if (next == "[end]") {
        break;  // [end]를 만나면 생성 중단시킴
      }
      output.push_back(next);
      current = {current.second, next};
    }
    return output;
  }
};

int main() {
  ifstream infile("HarryPotter.txt");
  vector<string> words;
  string word;
  while (infile >> word) {
    words.push_back(word);
  }
  words.push_back("[end]");
  textGenerator g;
  g.build(words);

  // 시작 단어 입력
  string w1, w2;
  cin >> w1 >> w2;

  auto result = g.generate(w1, w2);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << (i + 1 < result.size() ? " " : "\n");
  }
  return 0;
}