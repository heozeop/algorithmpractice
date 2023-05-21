#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 20;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
int r, c;
char board[MAX_N + 1][MAX_N + 1];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> r >> c;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      scanf(" %c", &board[i][j]);
    }
  }

  return;
}

int bfs() {
  int gmax = 0;
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {1, 1}});


  while (!q.empty()) {
    auto temp = q.front();
    q.pop();

    int curAlphabetNumber = board[temp.second.first][temp.second.second] - 'A';
    temp.first += (1 << curAlphabetNumber);
    

    int nx, ny, nextAlphabetNumber;
    for (int i = 0; i < 4; ++i) {
      nx = temp.second.first + DIRECTION[i][0];
      ny = temp.second.second + DIRECTION[i][1];

      if (nx < 1 || ny < 1 || nx > r || ny > c) {
        continue;
      }

      nextAlphabetNumber = board[nx][ny] - 'A';
      if (temp.first & (1 << nextAlphabetNumber)) {
        continue;
      }

      q.push({temp.first, {nx, ny}});
    }

    int localMax = 0;
    for(int i = 0; i < 26; ++i) {
      if(temp.first & (1 << i)) {
        localMax += 1;    
      }
    }
    gmax = max(gmax, localMax);
  }

  return gmax;
}

void solve() {
  cout << bfs();

  return;
}
