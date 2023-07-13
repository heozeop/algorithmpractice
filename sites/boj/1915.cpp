#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1000;

int n, m;
int arr[MAX_N][MAX_N];
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void solve() {
  vector<int> row(n, 0);
  vector<int> col(m, 0);

  for (int i = 0; i < n; ++i) {
    int localMax = 0;
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == 1) {
        localMax += 1;
      } else {
        row[i] = max(row[i], localMax);
        localMax = 0;
      }
    }
    row[i] = max(row[i], localMax);
  }

  for (int i = 0; i < m; ++i) {
    int localMax = 0;
    for (int j = 0; j < n; ++j) {
      if (arr[j][i] == 1) {
        localMax += 1;
      } else {
        col[i] = max(col[i], localMax);
        localMax = 0;
      }
    }
    col[i] = max(col[i], localMax);
  }
  return;
}
