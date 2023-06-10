#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1001;

int n, m, x;
int village[MAX_N][MAX_N];
int shortestPath[MAX_N];

void input();
void solve();
int dijkstraFindPath(int from, int end);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m >> x;

  int s,e,t;

  for(int i = 0; i < m; ++i) {
    cin >> s >> e >> t;

    village[s][e] = t;
  }

  return; 
}

void solve() { 
  for(int i = 1; i <= n; ++i) {
    if (x == i) {
      continue;
    }

    shortestPath[i] = dijkstraFindPath(i, x);
  }

  vector<bool> visited(n + 1);
  priority_queue<pair<int, int>> q;

  visited[x] = true;
  for(int i = 1; i <= n; ++i) {
    int value = village[x][i];
    if (!value) {
      continue;
    }

    q.push({ -value, i });
  }

  int globalMax = 0;
  while(!q.empty()) {
    auto fromVal = q.top();
    q.pop();

    if (visited[fromVal.second]) {
      continue;
    }

    visited[fromVal.second] = true;
    globalMax = max(globalMax, shortestPath[fromVal.second] - fromVal.first);

    for(int i = 1; i <= n; ++i) {
      if (visited[i]) {
        continue;
      }

      int value = village[fromVal.second][i];
      if (!value) {
        continue;
      }

      q.push({ fromVal.first - value,  i });
    }
  }

  cout << globalMax;

  return; 
}

int dijkstraFindPath(int from, int end) {
  vector<bool> visited(n + 1);
  priority_queue<pair<int, int>> q;

  visited[from] = true;
  for(int i = 1; i <= n; ++i) {
    int value = village[from][i];
    if (!value) {
      continue;
    }

    q.push({ -value, i });
  }

  while(!q.empty()) {
    auto fromVal = q.top();
    q.pop();

    if (fromVal.second == end) {
      return -fromVal.first;
    }

    if (visited[fromVal.second]) {
      continue;
    }

    visited[fromVal.second] = true;

    for(int i = 1; i <= n; ++i) {
      if (visited[i]) {
        continue;
      }

      int value = village[fromVal.second][i];
      if (!value) {
        continue;
      }

      q.push({ fromVal.first - value,  i });
    }
  }

  return 0;
}

