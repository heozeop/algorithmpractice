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
int arr[MAX_N][MAX_N];
int n;

void input();
void solve();
int findIsland(int);
void initiate();

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
  int maxVal = 0;
  for(int i = 0; i <= MAX_N; ++i) {
    int localMax = findIsland(i);
    
    if (localMax == 0) {
      break;
    }

    maxVal = max(maxVal, localMax);
  }

  cout << maxVal;
  return;
}

bool isReachable(int x, int y, int limit, vector<vector<bool>>& visited ) {
  if (x < 0 || y < 0) {
    return false;
  }

  if (x >= n || y >= n) {
    return false; 
  }

  if (arr[x][y] <= limit) {
    return false;
  }

  if(visited[x][y]) {
    return false; 
  }

  return true;
}

void dfs(int x, int y, int limit, vector<vector<bool>>& visited) {
  if (visited[x][y]) {
    return;
  }

  visited[x][y] = true;
  int nx,ny;
  for(int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];
    if(isReachable(nx,ny,limit, visited)) {
      dfs(nx,ny,limit, visited);
    }
  }
}

int findIsland(int limit) {
  int numOfIsland = 0;

  vector<vector<bool>> visited(n,  vector<bool>(n,false));

  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(isReachable(i,j,limit, visited)) {
        dfs(i,j,limit, visited);
        numOfIsland += 1;
      }
    }
  }

  return numOfIsland;
}

