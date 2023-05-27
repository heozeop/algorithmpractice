#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int EAST = 0;
const int WEST = 1;
const int NORTH = 2;
const int SOUTH = 3;
const int DIRECTION[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
typedef pair<int, int> pos;

void input();
void solve();

int board[20][20];
int opList[1000];
int dice[6];
int top = 2, bottom = 4;

bool isMovable(pos);
pos getNextPos(int);
void move(int);
void copyBottom();
void printTop();

int n, m, curX, curY, k;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m >> curX >> curY >> k;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < k; ++i) {
    cin >> opList[i];
  }

  return;
}

void solve() {
  int direction = 0;
  pos nextPos;
  for (int i = 0; i < k; ++i) {
    direction = opList[i] - 1;
    nextPos = getNextPos(direction);
    if (!isMovable(nextPos)) {
      continue;
    }

    move(direction);
    copyBottom();
    printTop();
  }

  return;
}

pos getNextPos(int direction) {
  return {
      curX + DIRECTION[direction][0],
      curY + DIRECTION[direction][1],
  };
}

bool isMovable(pos nextPos) {
  int x = nextPos.first;
  int y = nextPos.second;

  if (x < 0 || y < 0 || x >= n || y >= m) {
    return false;
  }

  return true;
}

void move(int direction) {
  curX += DIRECTION[direction][0];
  curY += DIRECTION[direction][1];

  vector<int> temp(dice, dice + 6);
  switch (direction) {
  case EAST:
    dice[0] = temp[2];
    dice[1] = temp[4];
    dice[2] = temp[1];
    dice[4] = temp[0];
    break;
  case WEST:
    dice[0] = temp[4];
    dice[1] = temp[2];
    dice[2] = temp[0];
    dice[4] = temp[1];
    break;
  case NORTH:
    dice[2] = temp[5];
    dice[3] = temp[2];
    dice[4] = temp[3];
    dice[5] = temp[4];
    break;
  case SOUTH:
    dice[2] = temp[3];
    dice[3] = temp[4];
    dice[4] = temp[5];
    dice[5] = temp[2];
    break;
  }
}

void copyBottom() {
  if (board[curX][curY] == 0) {
    board[curX][curY] = dice[bottom];
  } else {
    dice[bottom] = board[curX][curY];
    board[curX][curY] = 0;
  }
}

void printTop() { cout << dice[top] << endl; }
