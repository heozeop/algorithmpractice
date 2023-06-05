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

const int MAX_SIZE = 1000;
const int TARGET_POINT = 2;
const int MOVE_POINT = 1;
const int ONE = -1;

int n,m;
int arr[MAX_SIZE][MAX_SIZE];
int tx,ty;

void input();
void solve();

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

      if (arr[i][j] == TARGET_POINT) {
        tx = i;
        ty = j;
      }
    }
  }
  return; 
}

void solve() { 
  arr[tx][ty] = 0;
  queue<pair<int,pair<int,int>>> q;
  q.push({0, {tx,ty}});

  int x, y, v, nx,ny;
  while(!q.empty()) {
    v = q.front().first;
    x = q.front().second.first;
    y = q.front().second.second;
    q.pop();

    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }

      if(arr[nx][ny] != MOVE_POINT) {
        continue;
      }

      if (v+1 == 1){
        arr[nx][ny] = ONE;
      } else {
        arr[nx][ny] = v + 1;
      }

      q.push({v+1, {nx,ny}});
    }
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (arr[i][j] == ONE) {
        cout << 1;
      } else if(arr[i][j] == MOVE_POINT) {
        cout << -1;
      } else {
        cout << arr[i][j];
      }
      cout << " ";
    }
    cout << "\n";
  }
  return; 
}

