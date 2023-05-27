#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_SIZE = 500;
const int DIRECTIONS[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int paperMap[MAX_SIZE][MAX_SIZE];
int paperVisitMap[MAX_SIZE][MAX_SIZE];
int n, m;

void input();
void solve();
int getGlobalMax(int i, int j, int count, int curMax);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> paperMap[i][j];
    }
  }

  return;
}

void solve() {
  int globalMax = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      paperVisitMap[i][j] = true;
      globalMax = max(globalMax, getGlobalMax(i, j, 1, paperMap[i][j]));
      paperVisitMap[i][j] = false;
    }
  }

  cout << globalMax << endl;
  return;
}

int getGlobalMax(int x, int y, int count, int curMax) {
  if (count >= 4) {
    return curMax;
  }

  int nx, ny;
  int localMax = curMax;
  for (int i = 0; i < 4; ++i) {
    nx = x + DIRECTIONS[i][0];
    ny = y + DIRECTIONS[i][1];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m || paperVisitMap[nx][ny]) {
      continue;
    }

    paperVisitMap[nx][ny] = true;
    localMax = max(localMax,
                   getGlobalMax(nx, ny, count + 1, curMax + paperMap[nx][ny]));
    paperVisitMap[nx][ny] = false;
  }

  if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < n) { //ㅓ
    localMax = max(localMax, (paperMap[x - 1][y] + paperMap[x][y - 1] +
                              paperMap[x][y] + paperMap[x + 1][y]));
  }
  if (x - 1 >= 0 && y + 1 < m && x + 1 < n) { //ㅏ
    localMax = max(localMax, (paperMap[x - 1][y] + paperMap[x][y + 1] +
                              paperMap[x][y] + paperMap[x + 1][y]));
  }
  if (y - 1 >= 0 && y + 1 < m && x + 1 < n) { //ㅗ
    localMax = max(localMax, (paperMap[x][y] + paperMap[x + 1][y] +
                              paperMap[x + 1][y - 1] + paperMap[x + 1][y + 1]));
  }
  if (y - 1 >= 0 && y + 1 < m && x + 1 < n) { //ㅜ
    localMax = max(localMax, (paperMap[x][y - 1] + paperMap[x][y] +
                              paperMap[x][y + 1] + paperMap[x + 1][y]));
  }

  return localMax;
}