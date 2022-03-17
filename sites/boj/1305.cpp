#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void input();
void solve();
int n;
string s;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> s;
  return;
}

vector<int> ff(string str) {
  vector<int> pi(str.length(), 0);
  int j = 0;
  for(int i = 1; i < str.length(); i++) {
    while(j > 0 && str[i] != str[j]) j = pi[j - 1];
    if(str[i] == str[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

void solve() {
  auto pi = ff(s);
  cout << n - pi[n-1];

  return;
}
