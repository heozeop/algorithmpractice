#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MAX_N = 500;
const int DIRECTION[4][2] = {
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
};

int n;
int arr[MAX_N][MAX_N];
int mv[MAX_N][MAX_N];

void input();
void solve();
void floydwashal();
void printMax();
bool isInArea(int,int);

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

  floydwashal();
  printMax();

  return; 
}

void floydwashal() { 
  for(int i = 0; i < n;++i) {
    for(int j = 0; j < n; ++j) {
      mv[i][j] = 1;
    }
  }

  for(int l = 0; l < 4; ++l){
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        int nx,ny;
        for(int k = 0; k < 4; ++k) {
          nx = i + DIRECTION[k][0];
          ny = j + DIRECTION[k][1];

          if(!isInArea(nx, ny)){
            continue;
          }

          if (arr[i][j] >= arr[nx][ny]) {
            continue;
          }

          mv[nx][ny] = max(mv[nx][ny], mv[i][j] + 1);
        }
      }
    }
  }
}

void printMax() {
  int maxVal = 0;
  for(int i = 0; i < n;++i) {
    for(int j = 0; j < n; ++j) {
      maxVal = max(maxVal, mv[i][j]);
    }
  }

  cout << maxVal;
}

bool isInArea(int x,int y) {
  return x >= 0 && y >= 0 && x < n && y < n;
}
