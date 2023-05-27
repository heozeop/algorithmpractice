#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int n;
int pathMap[11][11];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> pathMap[i][j];
    }
  }
  return;
}

int dfs(int idx, vector<bool> &visited, int count) {
  if (count == n) {
    if (pathMap[idx][1]) {
      return pathMap[idx][1];
    }

    return 123456789;
  }

  int val = 123456789;
  for (int i = 2; i <= n; i++) {
    if (visited[i] || pathMap[idx][i] == 0) {
      continue;
    }

    visited[i] = true;
    val = min(val, dfs(i, visited, count + 1) + pathMap[idx][i]);
    visited[i] = false;
  }

  return val;
}

void solve() {
  vector<bool> visited(n + 1, false);
  visited[1] = true;
  cout << dfs(1, visited, 1);

  return;
}
