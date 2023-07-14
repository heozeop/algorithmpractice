#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1001;

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
  char temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> temp;
      arr[i][j] = temp - '0';
    }
  }
  return;
}

void solve() {
  int maxVal = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr[i][j] == 0) {
        continue;
      }

      arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
      maxVal = max(maxVal, arr[i][j]);
    }
  }

  cout << maxVal * maxVal;
  return;
}
