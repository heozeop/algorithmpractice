#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
int n;
int arr[1000];
int dp[1000][1001];
int maxN;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    maxN = max(maxN, arr[i]);
  }
  return;
}

void solve() {
  for(int i = 0; i < arr[i]; ++i) {
    dp[n-1][i] = arr[i];
  }

  for(int i = n-2; i >= 0; --i) {
    for(int j = 0; j <= maxN; ++j) {
      if (j < arr[i]) {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][arr[i]] + arr[i]);
      } else {
        dp[i][j] = dp[i + 1][j];
      }
    }
  }

  int maxValue = 0;
  for(int i = 0; i <= maxN; ++i) {
    maxValue = max(maxValue, dp[0][i]);
  }
  cout << maxValue;

  return;
}
