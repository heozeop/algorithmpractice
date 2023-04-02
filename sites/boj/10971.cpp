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
int sum;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> pathMap[i][j];
    }
  }
  return;
}

void dfs(int localSum, int idx, vector<bool>& visited, int count) { 
  if (count == n) {
    if(pathMap[idx][1]) {
      sum = min(sum, localSum + pathMap[idx][1]);
    }
    return;
  }

  for(int i = 2; i <= n; i++) {
    if(visited[i] || pathMap[idx][i] == 0) {
      continue;
    }

    visited[i] = true;
    dfs(localSum + pathMap[idx][i], i, visited, count + 1);
    visited[i] = false;
  }
}

void solve() {
  vector<bool> visited(n+1, false);
  visited[1] = true;
  sum = 123456789;
  dfs(0, 1, visited, 1);
  cout << sum;

  return;
}
