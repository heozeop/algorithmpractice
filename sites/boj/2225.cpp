#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MOD = 1000000000;

void input();
void solve();

int n, k;
long long dp[201][201];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  return;
}

void solve() {
  for (int i = 1; i <= k; i++) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][k];
  return;
}
