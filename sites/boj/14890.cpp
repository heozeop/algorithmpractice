#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100;

int n, l;
int arr[MAX_N][MAX_N];
int cnt;

void input();
void solve();
bool test(int row, int col, int dx, int dy);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    if (test(i, 0, 0, 1)) {
      cnt += 1;
    }

    if (test(0, i, 1, 0)) {
      cnt += 1;
    }
  }

  cout << cnt;

  return;
}

bool test(int row, int col, int dx, int dy) {
  int prevDownHill = -1;
  int temp = arr[row][col];

  for (int i = 1; i < n; ++i) {
    int cur = arr[row + dx * i][col + dy * i];
    if (temp == cur) {
      continue;
    }

    if (cur == temp - 1) {
      for (int j = 0; j < l; ++j) {
        if (j + i >= n) {
          return false;
        }

        if (arr[row + dx * (j + i)][col + dy * (j + i)] != temp - 1) {
          return false;
        }
      }

      temp -= 1;
      i += l - 1;
      prevDownHill = i;

      continue;
    }

    if (cur == temp + 1) {
      for (int j = 1; j <= l; ++j) {
        if (i - j <= prevDownHill) {
          return false;
        }

        if (arr[row + dx * (i - j)][col + dy * (i - j)] != temp) {
          return false;
        }
      }

      temp = temp + 1;
      continue;
    }

    return false;
  }

  return true;
}
