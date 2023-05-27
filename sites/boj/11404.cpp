#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_NODES = 101;
long long minCost[MAX_NODES][MAX_NODES];
int n, m;

void input() {
  cin.sync_with_stdio();
  cin.tie(NULL);

  cin >> n >> m;

  fill(&minCost[1][1], &minCost[n][n] + 1, INF);
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    if (minCost[a][b] > c) {
      minCost[a][b] = c;
    }
  }

  for (int i = 1; i <= n; ++i) {
    minCost[i][i] = 0;
  }
}

void floydWarshall() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (minCost[j][k] > minCost[j][i] + minCost[i][k]) {
          minCost[j][k] = minCost[j][i] + minCost[i][k];
        }
      }
    }
  }
}

void print() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (minCost[i][j] == INF) {
        cout << "0 ";
      } else {
        cout << minCost[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}

int main(void) {
  input();
  floydWarshall();
  print();
}