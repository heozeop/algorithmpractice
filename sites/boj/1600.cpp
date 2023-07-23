#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 200;
const int OBSTICLE = 1;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

const int HORSE_MOVE[8][2] = {
    {-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
};

int k, h, w;
int arr[MAX_N][MAX_N];
bool v[30][MAX_N][MAX_N];

struct Move {
  int cnt = 0;
  int k = 0;
  int x, y;
};

void input();
void solve();
bool isInArea(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> k >> w >> h;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void solve() {
  queue<Move> q;
  Move m = {0, k, 0, 0};
  q.push(m);

  v[k][0][0] = 1;

  int nx, ny;
  while (!q.empty()) {
    m = q.front();
    q.pop();

    if (m.x == h - 1 && m.y == w - 1) {
      cout << m.cnt;
      return;
    }

    for (int i = 0; i < 4; ++i) {
      nx = m.x + DIRECTION[i][0];
      ny = m.y + DIRECTION[i][1];

      if (!isInArea(nx, ny)) {
        continue;
      }

      if (arr[nx][ny] == OBSTICLE) {
        continue;
      }

      if (v[m.k][nx][ny]) {
        continue;
      }

      v[m.k][nx][ny] = 1;
      q.push({m.cnt + 1, m.k, nx, ny});
    }

    if (m.k < 1) {
      continue;
    }

    for (int i = 0; i < 8; ++i) {
      nx = m.x + HORSE_MOVE[i][0];
      ny = m.y + HORSE_MOVE[i][1];

      if (!isInArea(nx, ny)) {
        continue;
      }

      if (arr[nx][ny] == OBSTICLE) {
        continue;
      }

      if (v[m.k - 1][nx][ny]) {
        continue;
      }
      v[m.k - 1][nx][ny] = 1;
      q.push({m.cnt + 1, m.k - 1, nx, ny});
    }
  }

  cout << -1;
  return;
}

bool isInArea(int x, int y) { return x >= 0 && y >= 0 && x < h && y < w; }
