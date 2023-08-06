#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int dp[100001];

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
  dp[1] = 1;
  for(int i = 2; i <= n; ++i) {
    dp[i] = i;
    for(int j = 1; j * j <= i; ++j) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }

  cout << dp[n];

  return; 
}
