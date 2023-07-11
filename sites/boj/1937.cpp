#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_V = 1000001;
const int MAX_N = 500;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int n;
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void input();
void solve();
int dfs(int x, int y);
bool isInArea(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  return;
}

void solve() {
  int maxVal = 0;
  for(int i= 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      maxVal = max(maxVal, dfs(i, j));
    }
  }

  cout << maxVal;
  
  return;
}

int dfs(int x, int y) {
  if (dp[x][y]) {
    return dp[x][y];
  }

  int nx,ny;

  dp[x][y] = 1;
  for(int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if (!isInArea(nx, ny)) {
      continue;
    }

    if (arr[nx][ny] <= arr[x][y]) {
      continue;
    }

    dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
  }

  return dp[x][y];
}

bool isInArea(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }

