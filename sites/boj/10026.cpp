#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

const int DIRECTION[4][2] = {
  {0,1},
  {0,-1},
  {1,0},
  {-1,0},
};

const int MAX_N = 100;
const int NORMAL = 1;
const int BLIND = 2;
char arr[MAX_N][MAX_N];
int n;

void input();
void solve();

bool isSameColorByNormal(int, int, char);
bool isSameColorByBlind(int, int, char);
int findNumOfGroup(int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  return;
}

void solve() {
  cout << findNumOfGroup(NORMAL) << " " << findNumOfGroup(BLIND);
  return;
}

bool isSameColorByBlind(int x, int y, char c) {
  return c == arr[x][y] || (arr[x][y] == 'R' && c == 'G') || (arr[x][y] == 'G' && c == 'R');
}

bool isSameColorByNormal(int x, int y, char c) {
  return c == arr[x][y];
}

void dfs(int x, int y, char mark, vector<vector<int>>& ar, int type) {
  int nx, ny;
  ar[x][y] = mark;

  for(int i = 0 ; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
      continue;
    }

    if (ar[nx][ny] != 0) {
      continue;
    }
    
    bool isSame = false;

    switch(type) {
      case NORMAL:
        isSame = isSameColorByNormal(nx, ny, mark);
        break;
      case BLIND:
        isSame = isSameColorByBlind(nx, ny, mark);
        break;
    }

    if (isSame) {
      dfs(nx,ny, mark, ar, type);
    }
  }
}

int findNumOfGroup(int type) {
  int ans = 1;
  vector<vector<int>> v(n, vector<int>(n, 0));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(v[i][j] != 0) {
        continue;
      }

      dfs(i,j, arr[i][j], v, type);
      ans += 1;
    }
  }
  
  return ans - 1;
}

