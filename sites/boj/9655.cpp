#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int dp[1001];
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
  queue<pair<int, int>> q;
  q.push({1, 1});
  q.push({3, 1});
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 1;
  for (int i = 4; i <= n; ++i) {
    dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
  }
  if (dp[n] % 2 == 1) {
    cout << "SK";
  } else {
    cout << "CY";
  }

  return;
}
