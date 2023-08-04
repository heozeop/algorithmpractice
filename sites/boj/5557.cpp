#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int n, ans;
int arr[100];
ll dp[100][901];
int cnt;

void input();
void solve();
void dfs(int cur, int sum);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return;
}

void solve() {
  dp[0][arr[0]] = 1;

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 0; j <= 20; ++j) {
      if (j + arr[i] < 21) {
        dp[i][j] += dp[i - 1][j + arr[i]];
      }

      if (j - arr[i] >= 0) {
        dp[i][j] += dp[i - 1][j - arr[i]];
      }
    }
  }

  cout << dp[n - 2][arr[n - 1]];
  return;
}
