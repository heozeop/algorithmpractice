#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int DIRECTION[8][2] = {
    {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}, {-1, 0}, {1, 0},
};
const int MAX_N = 11;

int n, m, k;
int arr[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
deque<int> tree[MAX_N][MAX_N];

void input();
void solve();
void springSummerFall();
void winter();
void printTrees();
bool isInArea(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      arr[i][j] = 5;
      cin >> a[i][j];
    }
  }

  int x, y, k;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> k;
    tree[x][y].push_back(k);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sort(tree[i][j].begin(), tree[i][j].end());
    }
  }

  return;
}

void solve() {
  while (k--) {
    springSummerFall();
    winter();
  }

  printTrees();
  return;
}

void springSummerFall() {

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (tree[i][j].size() < 1) {
        continue;
      }

      int idx = -1;
      int size = tree[i][j].size();

      // spring
      for (int k = 0; k < size; ++k) {
        if (arr[i][j] < tree[i][j][k]) {
          idx = k;
          break;
        } else {
          arr[i][j] -= tree[i][j][k];
          tree[i][j][k] += 1;
        }
      }

      if (idx < 0) {
        continue;
      }

      // summer
      for (int k = size - 1; k >= idx; --k) {
        arr[i][j] += tree[i][j][k] / 2;
        tree[i][j].pop_back();
      }
    }
  }

  // fall
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int size = tree[i][j].size();

      if (size < 1) {
        continue;
      }

      for (int k = 0; k < size; ++k) {
        if (tree[i][j][k] % 5 != 0) {
          continue;
        }

        int nx, ny;
        for (int l = 0; l < 8; ++l) {
          nx = i + DIRECTION[l][0];
          ny = j + DIRECTION[l][1];

          if (!isInArea(nx, ny)) {
            continue;
          }

          tree[nx][ny].push_front(1);
        }
      }
    }
  }
}

void winter() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      arr[i][j] += a[i][j];
    }
  }
}

void printTrees() {
  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (tree[i][j].size() > 0) {
        ans += tree[i][j].size();
      }
    }
  }

  cout << ans;
}

bool isInArea(int x, int y) { return x > 0 && y > 0 && x <= n && y <= n; }
