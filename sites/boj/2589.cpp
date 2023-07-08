#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int DIRECTION[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};
const int MAX_N = 50;
const char LAND = 'L';

int n, m;
char arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
queue<pair<int, pair<int,int>>> q;
int maxN;

void input();
void solve();
void bfs(int,int);
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
    }
  }
  return;
}

void solve() { 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(arr[i][j] != LAND) {
        continue; 
      }

      bfs(i,j);
    }
  }

  cout << maxN;
  return; 
}

void bfs(int x, int y) {
  memset(visited, false, sizeof(visited));
  q.push({0, {x,y}});
  visited[x][y] = true;

  int time;
  while(!q.empty()) {
    auto iter = q.front();
    q.pop();

    time = iter.first;
    x = iter.second.first;
    y = iter.second.second;

    int nx,ny;
    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if(!isInArea(nx,ny)) {
        continue;
      }

      if (arr[nx][ny] != LAND) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = true;

      q.push({time + 1, {nx, ny}});
    }
  }

  maxN = max(maxN, time);
}

bool isInArea(int x, int y){
  return x >= 0 && y >= 0 && x < n && y < m;
}

