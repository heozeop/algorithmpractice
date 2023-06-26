#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int DIRECTION[4][2] = {
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
};
const int MAX_SIZE = 300;

int n, m;
int arr[MAX_SIZE][MAX_SIZE];
int arr2[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void input();
void solve();
bool isNoIceLeft();
void melt();
bool checkDivided();
bool isSea(int x, int y);
bool isInArea(int x, int y);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void printArr() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() { 
  bool isDivided = false;
  int time = 0;
  while(!isDivided) {
    if(isNoIceLeft()) {
      cout << 0;
      return;
    }

    melt();
    // printArr();
    isDivided = checkDivided();
    time += 1;
  }


  cout << time;
  return;
}


bool isNoIceLeft() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(arr[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void melt() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (!arr[i][j]) {
        continue;
      }

      int nx,ny, seacount = 0;
      for(int k = 0; k < 4; ++k) {
        nx = i + DIRECTION[k][0];
        ny = j + DIRECTION[k][1];
        
        if(!isSea(nx,ny)) {
          continue;
        }

        seacount += 1;
      }

      arr2[i][j] = max(0, arr[i][j] - seacount);
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      arr[i][j] = arr2[i][j];
    }
  }
}

void dfs(int x, int y) {
  visited[x][y] = -1;

  int nx,ny;
  for(int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if(isSea(nx, ny)) {
      continue;
    }

    if (!isInArea(nx,ny)) {
      continue;
    }

    if(visited[nx][ny] < 0) {
      continue;
    }

    dfs(nx, ny);
  }
}

bool checkDivided() {
  bool isNamed = false;
  memset(visited, 0, sizeof(visited));

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (!arr[i][j]) {
        continue;
      }

      if (visited[i][j] < 0) {
        continue;
      }

      if(!isNamed) {
        dfs(i, j);
        isNamed = true;
        continue;
      }

      return true;
    }
  }

  return false;
}

bool isSea(int x, int y) {
  return isInArea(x, y) && arr[x][y] == 0;
}

bool isInArea(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

