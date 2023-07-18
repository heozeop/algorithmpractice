#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 2000;

int n, m;
bool isDepth5Exist;

vector<int> edges[MAX_N];

void input();
void solve();
void dfs(int count, int index, vector<bool> &visited);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;

  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  return;
}

void solve() {
  for(int i = 0; i < n; ++i) {
    vector<bool> visited(n, false);
    visited[i] = true;

    dfs(0, i, visited);

    if(isDepth5Exist) {
      break;
    }
  }

  cout << isDepth5Exist;

  return;
}

void dfs(int count, int index, vector<bool> &visited) {
  if (count == 4) {
    isDepth5Exist = true;
    return;
  }

  for(int i : edges[index]) {
    if (visited[i]) {
      continue;
    }

    if (isDepth5Exist) {
      return;
    }

    visited[i] = true;
    dfs(count + 1, i, visited);
    visited[i] = false;
  }
}
