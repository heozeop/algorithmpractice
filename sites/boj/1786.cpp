#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

string t, p;
int pi[1000000];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  getline(cin, t);
  getline(cin, p);
  return;
}

void setPi(string s) {
  int j = 0;
  for (int i = 1; i < s.length(); i++) {
    while (j > 0 && s[j] != s[i])
      j = pi[j - 1];
    if (s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
  return;
}

vector<int> kmp(string t, string p) {
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < t.length(); i++) {
    while (j > 0 && t[i] != p[j])
      j = pi[j - 1];

    if (t[i] == p[j]) {
      if (j == p.length() - 1) {
        ans.push_back(i - p.length() + 1);
        j = pi[j];
      } else {
        j++;
      }
    }
  }
  return ans;
}

void solve() {
  setPi(p);
  auto ans = kmp(t, p);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << '\n';
  }
  return;
}
