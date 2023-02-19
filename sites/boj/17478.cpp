#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;

void input();
void solve();

int n;
void answer(int n, int prefixCount);
void printLineWithPrefix(int prefixCount, string statement);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void solve() {
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  answer(n, 0);
  return;
}

void answer(int n, int prefixCount) {
  printLineWithPrefix(prefixCount, "\"재귀함수가 뭔가요?\"");
  
  if (n == 0) {
    printLineWithPrefix(prefixCount, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
  } else {
    printLineWithPrefix(prefixCount, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
    printLineWithPrefix(prefixCount, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
    printLineWithPrefix(prefixCount, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");

    answer(n-1, prefixCount + 1);
  }


  printLineWithPrefix(prefixCount, "라고 답변하였지.");
}

void printLineWithPrefix(int prefixCount, string statement) {
  for(int i = 0; i < prefixCount; ++i) {
    cout << "____";
  }

  cout << statement << '\n';
}