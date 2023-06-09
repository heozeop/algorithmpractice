#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_NUM = 101;

int snake[MAX_NUM];
int ladder[MAX_NUM];
int n, m;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  int a,b;
  for(int i = 0; i < n; ++i) {
    cin >> a >> b;
    ladder[a] = b;
  }

  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    snake[a] = b;
  }

  return; 
}

bool isSafeToMove(int v, int a, vector<int>& b) {
  return v && v <= 100 && b[v] > a + 1;
}

void solve() { 
  vector<int> board(MAX_NUM, INT_MAX);
  queue<pair<int,int>> q;
  q.push({0,1});
  board[1] = 0;

  int a,b;
  while(!q.empty()) {
    a = q.front().first;
    b = q.front().second;
    q.pop();

    int nextP;
    for(int i = 1; i <= 6; ++i) {
      nextP = b + i;
      if (nextP > 100) {
        break;
      }

      if (board[nextP] <= a + 1) {
        continue;
      }

      board[nextP] = a + 1;
      if(!snake[nextP] && !ladder[nextP]) {
        q.push({a + 1, b + i});
      } else if (isSafeToMove(snake[nextP], a, board)) {
        board[snake[nextP]] = a + 1;
        q.push({a + 1, snake[nextP]});
      } else if (isSafeToMove(ladder[nextP], a, board)) {
        board[ladder[nextP]] = a + 1;
        q.push({a + 1, ladder[nextP]});
      }

    }
  }

  cout << board[100];

  return; 
}
