#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
int n,k;
int coin[101];
int dp[101][10001];

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
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= k; ++j) {
      int temp = 0, localMin = 10000;

      if (j % coin[i] == 0) {
        localMin = j / coin[i];
      } 

      while(j > coin[i] * temp) {
        if (dp[i - 1][j - coin[i] * temp] > 0) {
          localMin = min(dp[i - 1][j - coin[i] * temp] + temp, localMin);
        }
        temp += 1;
      }
      dp[i][j] = localMin;
    }
  }

  if(dp[n][k] < 1) {
    cout << -1;
  } else {
    cout << dp[n][k];
  }
  return;
}
