#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int DIRECTION[4][2] = {
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
};
const int MAX_N = 100;
const int OUTSIDE_AIR = -1;
const int FREEZE_CHEESE = 1;
const int CHEESE_TO_DELETE = 2;

int n,m;
int monunpaper[MAX_N][MAX_N];

void input();
void solve();
bool isAllMelted();
void markOutsideAir();
void markCheeseToMelt();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> monunpaper[i][j];
    }
  }

  return; 
}

void printMapForDebug(string debugFor) {
  cout << debugFor << '\n';
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cout << monunpaper[i][j] << " ";
    }
    cout << '\n';
  }
    cout << '\n';
}

void solve() { 
  int times = 0;
  while(!isAllMelted()) {
    markOutsideAir();
    markCheeseToMelt();
    times += 1;
  }

  cout << times;

  return; 
}

bool isAllMelted() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (monunpaper[i][j] == FREEZE_CHEESE) {
        return false;
      }
    }
  }

  return true;
}

void markOutsideAir() {
  queue<pair<int,int>> q;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  visited[0][0] = true;
  q.push({0,0});
  
  int x, y, nx, ny;
  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }

      if (monunpaper[nx][ny] == FREEZE_CHEESE) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }

      monunpaper[nx][ny] = OUTSIDE_AIR;
      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

void markCheeseToMelt() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (monunpaper[i][j] != FREEZE_CHEESE) {
        continue;
      }

      int facedSectionCount = 0;
      int nx,ny;
      for(int k = 0; k < 4; ++k){ 
        nx = i + DIRECTION[k][0];
        ny = j + DIRECTION[k][1];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
          continue;
        }

        if (monunpaper[nx][ny] == OUTSIDE_AIR) {
          facedSectionCount++;
        }
      }

      if (facedSectionCount >= 2) {
        monunpaper[i][j] = CHEESE_TO_DELETE;
      }
    }
  }
}

