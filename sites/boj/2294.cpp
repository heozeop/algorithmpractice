#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
int n,k;
int coin[101];
int dp[10001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;

  for(int i = 1; i <= n; ++i) {
    cin >> coin[i];
  }

  return;
}

void solve() {
  for(int i = 1; i <= k; ++i) {
    dp[i] = 10001;
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = coin[i]; j <= k; ++j) {
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    }
  }

  if(dp[k] == 10001) {
    cout << -1;
  } else {
    cout << dp[k];
  }
  
  return;
}
