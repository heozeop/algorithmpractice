#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
const int MAX_BOARD_SIZE = 51;
const int RED = 1;
const int BLUE = 2;
const int GREEN = 3;
const int YELLOW = 4;

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int maxVal, n;

int countWithFixedRow(int);
int countWithFixedCol(int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  string temp;
  int val;
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    for(int j = 0; j < n; ++j) {
      switch(temp[j]) {
        case 'C':
          val = RED;
          break;
        case 'P':
          val = BLUE;
          break;
        case 'Z':
          val = GREEN;
          break;
        case 'Y':
          val = YELLOW;
      }
      board[i][j] = val;
    }
  }

  return;
}

void solve() {
  for(int i = 0; i < n; ++i) {
    maxVal = max(maxVal, countWithFixedRow(i));
    maxVal = max(maxVal, countWithFixedCol(i));
  }

  if(maxVal == n) {
    cout << n;
    return;
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n - 1; ++j) {
      swap(board[i][j], board[i][j+1]);
      maxVal = max(maxVal, countWithFixedRow(i));
      maxVal = max(maxVal, countWithFixedCol(j));
      maxVal = max(maxVal, countWithFixedCol(j+1));
      swap(board[i][j+1],board[i][j]);

      swap(board[j][i],board[j+1][i]);
      maxVal = max(maxVal, countWithFixedCol(i));
      maxVal = max(maxVal, countWithFixedRow(j));
      maxVal = max(maxVal, countWithFixedRow(j+1));
      swap(board[j+1][i], board[j][i]);
    }
  }

  cout << maxVal;
  return;
}

int countWithFixedRow(int row) {
  int prevC, count;
  prevC = board[row][0];
  count = 1;
  int localMax = 0;
  for(int i = 1; i < n; ++i) {
    if (board[row][i] == prevC) {
      count += 1;
    } else {
      prevC = board[row][i];
      localMax = max(localMax, count);
      count = 1;
    }
  }

  return max(count, localMax);
}

int countWithFixedCol(int col) {
  int prevC, count, localMax;
  prevC = board[0][col];
  count = 1;
  localMax = 0;
  for(int i = 1; i < n; ++i) {
    if (board[i][col] == prevC) {
      count += 1;
    } else {
      prevC = board[i][col];
      localMax = max(localMax, count);
      count = 1;
    }
  }

  return max(localMax, count);
}
