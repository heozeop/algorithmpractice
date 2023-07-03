#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};
const int MAX_N = 50;
const char ROCK = 'X';
const char EMPTY = '.';
const char WATER = '*';
const char BIBBER_HOME = 'D';
const char GOSMDOCHI = 'S';
const string NOT_AVAILABLE = "KAKTUS";

char arr[MAX_N][MAX_N];
char arr2[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, m;
int gx, gy;

void input();
void solve();
void waterSpread();
bool isInArea(int, int);

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

      if (arr[i][j] == GOSMDOCHI) {
        gx = i;
        gy = j;
      }
    }
  }
  return;
}

void solve() {
  queue<pair<int, pair<int, int>>> q;
  q.push({1, {gx, gy}});
  arr[gx][gy] = EMPTY;
  int prevSpreadTime = 1;
  visited[gx][gy] = 1;

  while (!q.empty()) {
    int localTime = q.front().first;
    gx = q.front().second.first;
    gy = q.front().second.second;
    q.pop();

    if (prevSpreadTime == localTime) {
      waterSpread();
      prevSpreadTime += 1;
    }

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
      nx = gx + DIRECTION[i][0];
      ny = gy + DIRECTION[i][1];

      if (!isInArea(nx, ny)) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = 1;

      if (arr[nx][ny] == BIBBER_HOME) {
        cout << localTime;
        return;
      }

      if (arr[nx][ny] != EMPTY) {
        continue;
      }

      q.push({localTime + 1, {nx, ny}});
    }
  }

  cout << NOT_AVAILABLE;
  return;
}

bool isInArea(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

void waterSpread() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] != WATER) {
        if (arr2[i][j] != WATER) {
          arr2[i][j] = arr[i][j];
        }
        continue;
      }

      int nx, ny;
      for (int k = 0; k < 4; ++k) {
        nx = i + DIRECTION[k][0];
        ny = j + DIRECTION[k][1];

        if (!isInArea(nx, ny)) {
          continue;
        }

        if (arr[nx][ny] == EMPTY) {
          arr2[nx][ny] = WATER;
        }
      }
      arr2[i][j] = WATER;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      arr[i][j] = arr2[i][j];
    }
  }
}
