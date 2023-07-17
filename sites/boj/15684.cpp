#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 11;
const int MAX_H = 31;
const int MAX_M = 271;

int n, m, h;
int ROW, COL;
int endpoint[MAX_M][MAX_N];

void input();
void solve();
void setup(int row, int col);
int put(int amount);
void putSingleOne(int row, int col);
void undo(int row, int col);
bool putable(int row, int col);
bool validate();


int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m >> h;
  COL = n;
  ROW = h;

  for(int i = 1; i <= ROW; ++i) { 
    for(int j = 1; j <= COL; ++j) {
      endpoint[i][j] = j;
    }
  }

  int a,b;
  for(int i = 0 ; i < m; ++i) {
     cin >> a >> b;
     endpoint[a][b] = b + 1;
     endpoint[a][b + 1] = b;
  }
  
  return; 
}

void solve() { 
  // 0개 구함
  if(validate()) {
    cout << 0;
    return;
  }

  cout << put(1);
  return; 
}

int put(int amount) {
  int minVal = -1;
  for(int i = 1; i <= ROW; ++i) {
    for(int j = 1; j < COL; ++j) {
      if(!putable(i,j)) {
        continue; 
      }

      setup(i,j);
      if(validate()) {
        undo(i, j);
        return amount;
      }

      if(amount < 3) {
        int localMinVal = put(amount + 1);
        if(localMinVal != -1) {
          minVal = localMinVal;
        }
      }

      undo(i, j);
    }
  }

  return minVal;
}


bool validate() {
  for(int i = 1; i <= COL;++i) {
    int currentCol = i;

    for(int j = 1; j <= ROW; ++j) {
      currentCol = endpoint[j][currentCol];
    }

    if(currentCol != i) {
      return false;
    }
  }

  return true;
}

void setup(int a, int b) {
  endpoint[a][b] = b + 1;
  endpoint[a][b + 1] = b;
}

void undo(int a, int b) {
  endpoint[a][b] = b;
  endpoint[a][b + 1] = b + 1;
}

bool putable(int row, int col) {
  return endpoint[row][col] == col && endpoint[row][col + 1] == col + 1;
}
