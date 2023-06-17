#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 101;
const int INF = 123456789;

int n, m, r;
int items[MAX_N];
int edges[MAX_N][MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m >> r;

  for (int i = 1; i <= n; ++i) {
    cin >> items[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        edges[i][j] = 0;
      } else {
        edges[i][j] = INF;
      }
    }
  }

  int a, b, w;
  for (int i = 0; i < r; ++i) {
    cin >> a >> b >> w;
    edges[a][b] = w;
    edges[b][a] = w;
  }

  return;
}

void solve() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
  }

  int maxValue = 0;
  for (int i = 1; i <= n; ++i) {
    int localSum = 0;
    for (int j = 1; j <= n; ++j) {
      if (edges[i][j] > m) {
        continue;
      }

      localSum += items[j];
    }

    maxValue = max(maxValue, localSum);
  }

  cout << maxValue;

  return;
}
