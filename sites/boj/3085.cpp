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
typedef pair<int,int> pos;

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
bool visit[MAX_BOARD_SIZE][MAX_BOARD_SIZE][4];
int maxVal, n;

int checkLine(pos, pos);
int countWithFixedRow(int);
int countWithFixedCol(int);
void swapOnBoard(pos, pos);

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
      visit[i][j][val] = true;
    }
  }

  return;
}

void solve() {
  int numOfSections = n * n;
  pos a,b;
  int aColor, bColor, localMax;
  localMax = 0;
  for(int i = 0; i < n; ++i) {
    localMax = max(localMax, countWithFixedRow(i));
    localMax = max(localMax, countWithFixedCol(i));
  }
  
  if(localMax == n) {
    cout << n;
    return;
  }

  for(int i = 0; i < numOfSections - 1; ++i) {
    a.first = i / n;
    a.second = i % n;
    aColor = board[a.first][a.second];
    for(int j = i + 1; j < numOfSections; ++j) {
      b.first = j / n;
      b.second = j % n;
      bColor = board[b.first][b.second];

      if(aColor == bColor || visit[a.first][a.second][bColor] && visit[b.first][b.second][aColor]) {
        continue;
      }

      visit[a.first][a.second][bColor] = true;
      visit[b.first][b.second][aColor] = true;
      swapOnBoard(a,b);
      localMax = checkLine(a, b);
      swapOnBoard(a,b);
      maxVal = max(localMax, maxVal);

      if(maxVal == n) {
        cout << n;
        return;
      }
    }
  }
  cout << maxVal;
  return;
}

int checkLine(pos a, pos b) {
  int localMax = 0;
  localMax = max(localMax, max(countWithFixedRow(a.first), countWithFixedRow(b.first)));
  localMax = max(localMax, max(countWithFixedCol(a.second), countWithFixedCol(b.second)));

  return localMax;
}

int countWithFixedRow(int row) {
  int prevC, count;
  prevC = board[row][0];
  count = 1;
  for(int i = 1; i < n; ++i) {
    if (board[row][i] == prevC) {
      count += 1;
    } else {
      prevC = board[row][i];
      count = 1;
    }
  }

  return count;
}

int countWithFixedCol(int col) {
  int prevC, count;
  prevC = board[0][col];
  count = 1;
  for(int i = 1; i < n; ++i) {
    if (board[i][col] == prevC) {
      count += 1;
    } else {
      prevC = board[i][col];
      count = 1;
    }
  }

  return count;
}

void swapOnBoard(pos a, pos b) {
  int temp = board[a.first][a.second];
  board[a.first][a.second] = board[b.first][b.second];
  board[b.first][b.second] = temp;
}