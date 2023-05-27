#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

string s;

int main(void) {
  input();
  solve();
  return 0;
}

void input() { return; }

vector<int> failureFunction(string s) {
  int j = 0;
  vector<int> pi(s.length(), 0);
  for (int i = 1; i < s.length(); i++) {
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];

    if (s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

void solve() {
  while (1) {
    getline(cin, s);
    if (s == ".") {
      break;
    }
    auto pi = failureFunction(s);
    // 구하고자 하는게 s에서 반복되는 것을 찾는 것이라 마지막 것만 중요
    int length = s.length();
    int last = pi[length - 1];
    if (last == 0 || length % (length - last) != 0) {
      cout << 1 << '\n';
    } else {
      cout << length / (length - last) << '\n';
    }
  }
  return;
}
