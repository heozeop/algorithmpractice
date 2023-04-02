#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();

int n;
int pathMap[11][11];
int dp[11][11][11];
int weight(int,int,vector<bool>&, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dp[0][i][j];
    }
  }
  return;
}

void solve() {
  if (n == 2) {
    cout << dp[0][1][2] + dp[0][2][1];
    return;
  }

  int localSum = 123456789;
  vector<bool> visited(n + 1, false);
  visited[1] = true;

  for(int j = 2; j <= n; j++) {
    visited[j] = true;
    for(int k = 2; k <= n; k++) {
      if (j == k || dp[0][1][j] == 0 || dp[0][k][1] == 0) {
        continue;
      }

      visited[k] = true;
      localSum = min(localSum, weight(j, k, visited, max(n - 3, 0)) + dp[0][1][j] + dp[0][k][1]);
      visited[k] = false;
    }
    visited[j] = false;
  }
  cout << localSum;

  return;
}

int weight(int start, int end, vector<bool>& visited, int visitedCount) {
  if (visitedCount == 0 || dp[visitedCount][start][end]) {
    return dp[visitedCount][start][end];
  }

  int localSum = 123456789;
  if (visitedCount == 1) {
    for(int i = 1; i <= n; ++i) {
      if(visited[i] || dp[0][start][i] == 0 || dp[0][i][end] == 0) {
        continue;
      }

      localSum = min(localSum, dp[0][start][i] + dp[0][i][end]);
    }

    return dp[1][start][end] = localSum;
  }

  for(int i = 2; i <= n; ++i) {
    if(visited[i] || start == i || dp[0][start][i] == 0) {
      continue;
    }

    visited[i] = true;
    for(int j = i; j <= n; ++j) {
      if(visited[j] || j == end || dp[0][j][end] == 0) {
        continue;
      }
      visited[j] = true;

      localSum = min(localSum, weight(i, j, visited, max(0, visitedCount - 2)) + dp[0][start][i] + dp[0][j][end]);
      visited[j] = false;
    }
    visited[i] = false;
  }

  return dp[visitedCount][start][end] = min(localSum, dp[visitedCount][start][end]);
}
