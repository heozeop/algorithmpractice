#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int dp[1001][1001];

void input();
void solve();

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
  for (int i = 0; i < 10; ++i) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= 9; ++j) {
      for (int k = j; k <= 9; ++k) {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= 10007;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i <= 9; ++i) {
    sum += dp[n][i];
    sum %= 10007;
  }

  cout << sum;
  return;
}
