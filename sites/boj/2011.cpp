#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int n;
int sc[5001];
int dp[5001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  string temp;
  cin >> temp;
  n = temp.length();
  int i = 1;
  for (char c : temp) {
    sc[i++] = c - '0';
  }

  return;
}

void solve() {
  if (sc[1] == 0) {
    cout << 0;
    return;
  }
  dp[0] = 1;
  dp[1] = 1;

  int temp;
  for (int i = 2; i <= n; ++i) {
    if (sc[i] == 0 && (sc[i - 1] == 0 || sc[i - 1] > 2)) {
      cout << 0;
      return;
    }

    if (sc[i] > 0) {
      dp[i] += dp[i - 1];
    }

    temp = sc[i] + sc[i - 1] * 10;

    if (temp >= 10 && temp <= 26) {
      dp[i] += dp[i - 2];
    }

    dp[i] %= 1000000;
  }
  cout << dp[n];

  return;
}
