#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef pair<int,int> pos;
const int MAX_BOARD_SIZE = 101;
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;
const char LEFT = 'L';
const char RIGHT = 'D';
const int DIRECTION[4][2] = {
  {-1,0},
  {0,1},
  {1,0},
  {0,-1}
};

int currentDirection = 1;
int n, k, l, board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

void input();
void solve();
pos getNextPos(pos curPos);
bool isMovable(pos);
void move(pos,pos);
void changeDirection(char d);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  int row,col;
  for(int i = 0; i < k; ++i) {
    cin >> row >> col;
    board[row][col] = APPLE;
  }

  return;
}

void solve() {
  cin >> l;

  pos curPos = {1,1};
  board[1][1] = SNAKE;

  int time, i, x;
  char c;
  bool isGameEnd = false;
  for(i = 0, time = 0; i < l && !isGameEnd; ++i) {
    cin >> x >> c;

    do {
      time += 1;
      pos nextPos = getNextPos(curPos);
      if(!isMovable(nextPos)) {
        isGameEnd = true;
        break;
      }

      move(curPos, nextPos);
      
      curPos = nextPos;
    } while(time < x);

    changeDirection(c);
  }

  cout << time;

  return;
}

pos getNextPos(pos curPos) {
  return {
    curPos.first + DIRECTION[currentDirection][0],
    curPos.second + DIRECTION[currentDirection][1]
  };
}

bool isMovable(pos positionToMove) {
  int x = positionToMove.first, y = positionToMove.second;
  if(x < 1 || y < 1 || x > n || y > n)  {
    return false;
  }

  if (board[x][y] == SNAKE) {
    return false;
  }

  return true;
}

void move(pos curPos,pos nextPos) {
  if (board[nextPos.first][nextPos.second] == APPLE) {
    k -= 1;
  } else {
    board[curPos.first][curPos.second] = EMPTY;
  }

  board[nextPos.first][nextPos.second] = SNAKE;
}

void changeDirection(char d) {
  int nextDirection = currentDirection + 1;
  if(d == LEFT) {
    nextDirection = currentDirection - 1;
  }

  currentDirection = nextDirection % 4;
}