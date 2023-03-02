#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
const int MAX_SIZE = 500;
const int NUM_OF_TYPE = 19;

int paperMap[MAX_SIZE][MAX_SIZE];
int n, m;

class Tetromino {
  int position[4][2];
public:
  Tetromino() {}
  Tetromino(int position[4][2]) { 
    this->setPosition(position);
  }

  void setPosition(int position[4][2]) {
    for(int i = 0; i < 4; ++i) {
      this->position[i][0] = position[i][0];
      this->position[i][1] = position[i][1];
    }
  }

  bool isPossible(int i, int j) {
    int ni,nj;
    for(int k = 0; k < 4; ++k) {
      ni = i + this->position[k][0];
      nj = j + this->position[k][1];

      if(ni >= n || nj >= m) {
        return false;
      }
    }

    return true;
  };

  int sum(int i, int j) {
    int localMax = 0;
    int ni,nj;

    for(int k = 0; k < 4; ++k) {
      ni = i + this->position[k][0];
      nj = j + this->position[k][1];

      localMax += paperMap[ni][nj];
    }

    return localMax;
  }
};

int typeList[NUM_OF_TYPE][4][2] = {
  {{0,0},{0,1},{0,2}, {0, 3}},
  {{0,0},{1,0},{2,0},{3, 0}},
  {{0,0},{0,1},{1,0},{1, 1}},
  {{0,0},{1,0},{2,0},{2, 1}},
  {{0,0},{0,1},{0,2},{1, 0}},
  {{0,0},{0,1},{1,1},{2, 1}},
  {{0,0},{0,1},{0,2},{-1, 2}},
  {{0,0},{1,0},{1,1},{2, 1}},
  {{0,0},{0,1},{-1,1},{-1, 2}},
  {{0,0},{0,1},{0,2},{1, 1}},
  {{0,0},{0,1},{1,1},{-1, 1}},
  {{0,0},{1,0},{2,0},{1, 1}},
  {{0,0},{0,1},{0,2},{-1, 1}},
  {{0,0},{0,1},{-1,1},{-2, 1}},
  {{0,0},{1,0},{1,1},{1, 2}},
  {{0,0},{0,1},{1,0},{2, 0}},
  {{0,0},{0,1},{0,2},{1, 2}},
  {{0,0},{1,0},{0,1},{-1, 1}},
  {{0,0},{0,1},{1,1},{1, 2}},
};


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
      cin >> paperMap[i][j];
    }
  }

  return;
}

void solve() {
  Tetromino curTetromino;
  int globalMax, localMax;
  globalMax = localMax = 0;
  for(int k = 0; k < NUM_OF_TYPE; ++k) {
    curTetromino.setPosition(typeList[k]);
    localMax = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(curTetromino.isPossible(i,j)) {
          localMax = max(localMax, curTetromino.sum(i,j));
        }
      }
    }

    globalMax = max(globalMax, localMax);
  }

  cout << globalMax << endl;
  return;
}
