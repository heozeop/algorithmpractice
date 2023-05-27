#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
int n, m, k;
int array2D[301][301];
int calculateSum();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> array2D[i][j];
    }
  }
  cin >> k;
  return;
}

void solve() {
  for (int i = 0; i < k; ++i) {
    cout << calculateSum() << '\n';
  }

  return;
}

int calculateSum() {
  int i, j, x, y;
  int sum = 0;

  cin >> i >> j >> x >> y;
  for (int row = i; row <= x; ++row) {
    for (int col = j; col <= y; ++col) {
      sum += array2D[row][col];
    }
  }

  return sum;
}
