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
const int AIR = -1;
const int EMPTY = 0;
const int CHEESE = 1;
const int MARK = 2;
const int MAX_N = 100;

int n, m;
int arr[MAX_N][MAX_N];

void input();
void solve();
bool isAirNear(int x, int y);
bool isInArea(int, int);
void mark();
void melt();
void spreadAir();
int numberOfCheese();

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

void printArr() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  cout << '\n';
}

void solve() {
  int time = 0;
  int leftCount = numberOfCheese();

  while (1) {
    spreadAir();
    mark();
    melt();
    ++time;

    int localLeftCount = numberOfCheese();
    if (localLeftCount == 0) {
      break;
    }

    leftCount = localLeftCount;
  }

  cout << time << '\n' << leftCount;

  return;
}

int numberOfCheese() {
  int numOfCheese = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == CHEESE) {
        ++numOfCheese;
      }
    }
  }

  return numOfCheese;
}

void spreadAir() {
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  q.push({0, 0});
  arr[0][0] = AIR;

  pair<int, int> temp;

  while (!q.empty()) {
    temp = q.front();
    q.pop();

    int x = temp.first;
    int y = temp.second;

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if (!isInArea(nx, ny)) {
        continue;
      }

      if (arr[nx][ny] == CHEESE) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = true;

      arr[nx][ny] = AIR;
      q.push({nx, ny});
    }
  }
}

void mark() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == CHEESE && isAirNear(i, j)) {
        arr[i][j] = MARK;
      }
    }
  }
}

void melt() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (arr[i][j] == MARK) {
        arr[i][j] = AIR;
      }
    }
  }
}

bool isInArea(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

bool isAirNear(int x, int y) {
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if (!isInArea(nx, ny)) {
      continue;
    }

    if (arr[nx][ny] == AIR) {
      return true;
    }
  }

  return false;
}
