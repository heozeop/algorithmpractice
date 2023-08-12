#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1000001;
const int MOD = 100000009;

int t,n;
long long dp[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> t;

  return; 
}

void solve() { 
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i = 4; i < MAX_N; ++i) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    dp[i] %= MOD;
  }

  while(t--) {
    cin >> n;

    cout << dp[n] << endl;
  }
  
  return; 
}
