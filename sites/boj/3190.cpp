#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pos;
const int MAX_BOARD_SIZE = 101;
const int EMPTY = 0;
const int APPLE = 1;
const int SNAKE = 2;
const char LEFT = 'L';
const char RIGHT = 'D';
const int DIRECTION[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int currentDirection = 1;
int n, k, l, board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

void input();
void solve();
pos getNextPos(pos curPos);
bool isMovable(pos);
void move(deque<pos> &snake, pos nextPos);
void changeDirection(char d);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  int row, col;
  for (int i = 0; i < k; ++i) {
    cin >> row >> col;
    board[row][col] = APPLE;
  }

  return;
}

void solve() {
  cin >> l;
  deque<pos> snake;
  snake.push_back({1, 1});
  board[1][1] = SNAKE;

  int time, i, x;
  char c;
  bool isGameEnd = false;
  for (i = 0, time = 0; i < l && !isGameEnd; ++i) {
    cin >> x >> c;

    do {
      time += 1;
      pos nextPos = getNextPos(snake.back());
      if (!isMovable(nextPos)) {
        isGameEnd = true;
        break;
      }

      move(snake, nextPos);
    } while (time < x);

    changeDirection(c);
  }

  if (!isGameEnd) {
    while (1) {
      time += 1;
      pos nextPos = getNextPos(snake.back());
      if (!isMovable(nextPos)) {
        break;
      }

      move(snake, nextPos);
    }
  }

  cout << time;

  return;
}

pos getNextPos(pos curPos) {
  return {curPos.first + DIRECTION[currentDirection][0],
          curPos.second + DIRECTION[currentDirection][1]};
}

bool isMovable(pos positionToMove) {
  int x = positionToMove.first, y = positionToMove.second;
  if (x < 1 || y < 1 || x > n || y > n) {
    return false;
  }

  if (board[x][y] == SNAKE) {
    return false;
  }

  return true;
}

void move(deque<pos> &snake, pos nextPos) {
  if (board[nextPos.first][nextPos.second] == APPLE) {
    k -= 1;
  } else {
    board[snake.front().first][snake.front().second] = EMPTY;
    snake.pop_front();
  }

  board[nextPos.first][nextPos.second] = SNAKE;
  snake.push_back(nextPos);
}

void changeDirection(char d) {
  int nextDirection = currentDirection + 1;
  if (d == LEFT) {
    nextDirection = currentDirection + 3;
  }

  currentDirection = nextDirection % 4;
}
