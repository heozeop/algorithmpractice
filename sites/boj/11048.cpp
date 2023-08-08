#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_NM = 1001;

int arr[MAX_NM][MAX_NM];
int dp[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

int n,m;
void input();
void solve();
void backtrack(int, int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  return; 
}

void solve() { 
  dp[0][0] = arr[0][0];
  for(int i = 1; i < n; ++i) {
    dp[i][0] = dp[i-1][0] + arr[i][0];
  }

  for(int i = 1; i < m; ++i) {
    dp[0][i] = dp[0][i-1] + arr[0][i];
  }

  for(int i = 1; i < n; ++i) { 
    for(int j = 1; j < m; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
    }
  }

  cout << dp[n - 1][m - 1];
  return; 
}
