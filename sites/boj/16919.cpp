#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

const int DIRECTION[4][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0,-1},
};

const char BOMB = 'O';
const char EMPTY_SPACE = '.';
const int EMPTY = 0;

int r,c,n;
int board[201][201];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> r >> c >> n;
  char curTemp;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      cin >> curTemp;
      if(curTemp == EMPTY_SPACE) {
        board[i][j] = 0;
      } else {
        board[i][j] = 3;
      }
    }
  }
  return;
}

void setBomb(int curT) {
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(board[i][j] == EMPTY) {
        board[i][j] = curT + 3;
      }
    }
  }
}

void blowBomb(int curT) {
  int nx,ny;
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(board[i][j] == curT) {
        board[i][j] = EMPTY;
        for(int k = 0; k < 4; ++k) {
          nx = i + DIRECTION[k][0];
          ny = j + DIRECTION[k][1];

          if(nx < 1 || ny < 1 || nx > r || ny > c || board[nx][ny] == curT) {
            continue;
          }

          board[nx][ny] = EMPTY;
        }
      }
    }
  }
}

void printMap() {
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      if(board[i][j] == EMPTY) {
        cout << EMPTY_SPACE;
      } else {
        cout << BOMB;
      }
    }
    cout << '\n';
  }
}

void printBomb() {
  for(int i = 1; i <= r; ++i) {
    for(int j = 1; j <= c; ++j) {
      cout << BOMB;
    }
    cout << '\n';
  }
}

void solve() {
  if (n % 2 == 0) {
    printBomb();
    return;
  }

  if (n == 1) {
    printMap();
    return;
  }

  if(n > 4) {
    n %= 4;
    n += 4;
  }

  int curT = 2;
  while(curT <= n) {
    setBomb(curT);
    blowBomb(curT);
    curT += 1;
  }

  printMap();

  return;
}
