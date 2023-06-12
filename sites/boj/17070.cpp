#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int GARO = 0;
const int SERO = 1;
const int DEAGAKSUN = 2;
const int WALL = 1;

int arr[16][16];
int dp[16][16];

int n;

void input();
void solve();

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

bool isMovable(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n && arr[x][y] != WALL;
}

void dfs(int x, int y, int type) {
  dp[x][y] += 1;

  if (x == n - 1 && y == n - 1) {
    return;
  }

  switch (type) {
  case GARO:
    if (isMovable(x, y + 1)) {
      dfs(x, y + 1, GARO);
    }

    if (isMovable(x + 1, y + 1) && isMovable(x + 1, y) && isMovable(x, y + 1)) {
      dfs(x + 1, y + 1, DEAGAKSUN);
    }
    break;
  case SERO:
    if (isMovable(x + 1, y)) {
      dfs(x + 1, y, SERO);
    }

    if (isMovable(x + 1, y + 1) && isMovable(x + 1, y) && isMovable(x, y + 1)) {
      dfs(x + 1, y + 1, DEAGAKSUN);
    }
    break;
  case DEAGAKSUN:
    if (isMovable(x, y + 1)) {
      dfs(x, y + 1, GARO);
    }

    if (isMovable(x + 1, y + 1) && isMovable(x + 1, y) && isMovable(x, y + 1)) {
      dfs(x + 1, y + 1, DEAGAKSUN);
    }

    if (isMovable(x + 1, y)) {
      dfs(x + 1, y, SERO);
    }
    break;
  }
}

void solve() {
  dfs(0, 1, GARO);

  cout << dp[n - 1][n - 1];
  return;
}
