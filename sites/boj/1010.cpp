#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int tc;

void input();
void solve();
void setBridge();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> tc;
  return; 
}

void solve() { 
  while(tc--) {
    setBridge();
  }
  return; 
}

void setBridge() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for(int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }

  for(int i = 1; i <= m; ++i) {
    dp[1][i] = 1;
  }

  for(int i = 2; i <= n; ++i) {
    for(int j = i + 1; j <= m; ++j) {
      for(int k = j - 1; k >= i - 1; --k) {
        dp[i][j]+= dp[i - 1][k];
      }
    }
  }

  int sum = 0;
  for(int i = n; i <= m; ++i) {
    sum += dp[n][i];
  }

  cout << sum << endl;
}
