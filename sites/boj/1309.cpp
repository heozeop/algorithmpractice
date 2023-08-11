#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int NUM = 9901;

int dp[100000][3];
int n;

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
  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[0][2] = 1;

  for (int i = 1; i < n; ++i) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % NUM;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % NUM;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % NUM;
  }

  int sum = 0;
  for (int i = 0; i < 3; ++i) {
    sum += dp[n - 1][i];
    sum %= NUM;
  }
  cout << sum;

  return;
}
