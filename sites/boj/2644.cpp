#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 101;

int arr[MAX_N][MAX_N];
int n, x, y;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> x >> y;
  int m;
  cin >> m;

  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;

    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  return;
}

void solve() {
  queue<pair<int, int>> q;
  vector<bool> visited(n, false);
  q.push({x, 0});
  visited[x] = 1;
  while (!q.empty()) {
    auto temp = q.front();
    q.pop();

    if (temp.first == y) {
      cout << temp.second;
      return;
    }

    for (int i = 1; i <= n; ++i) {
      if (!arr[temp.first][i]) {
        continue;
      }

      if (visited[i]) {
        continue;
      }
      visited[i] = true;

      q.push({i, temp.second + 1});
    }
  }

  cout << -1;
  return;
}
