#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 100;
const int SEA = 0;
const int LAND = 1;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

queue<pair<int, pair<int,int>>> q;
int d[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int arr[MAX_N][MAX_N];
int n;
int minValue = 123456789;

void input();
void solve();
void dfs(int s, int x, int y);
void bfs();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void solve() {
  int mark = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] != LAND) {
        continue;
      }

      visited[i][j] = mark;
      dfs(mark++, i, j);
    }
  }

  bfs();
  cout << minValue;

  return;
}

bool isInArea(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }

void dfs(int s, int x, int y) {
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if (!isInArea(nx, ny)) {
      continue;
    }

    if (visited[nx][ny]) {
      continue;
    }

    if (arr[nx][ny] == SEA) {
      q.push({s, {nx,ny}});
      visited[nx][ny] = s;
      d[nx][ny] = 1;
      continue;
    }

    if (arr[nx][ny] != LAND) {
      continue;
    }

    arr[nx][ny] = s;
    visited[nx][ny] = s;
    dfs(s,nx,ny);
  }
}

void printVisited() {
  cout << '\n';
  for(int i= 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << d[i][j] << " ";
    }
    cout << " ";
    for(int j = 0; j < n; ++j) {
      cout << visited[i][j] << " ";
    }
    cout << '\n';
  }
}

void bfs() {
  while(!q.empty()) {
    int mark = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    int nx, ny;
    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if (!isInArea(nx, ny)) {
        continue;
      }

      if (visited[nx][ny] == mark) {
        continue;
      }

      if(visited[nx][ny] == 0) {
        visited[nx][ny] = mark;
        d[nx][ny] = d[x][y] + 1;
        q.push({mark, {nx,ny}});
        continue;
      }

      minValue = min(minValue, d[nx][ny] + d[x][y]);
    }
  }
}

