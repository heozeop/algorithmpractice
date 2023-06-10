#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_SIZE = 600;
const string FAIL_TO_MEET = "TT";
const int DIRECTION[4][2] = {
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
};

int n, m, numberOfPeopleMet;
int ITER_FOR_N, ITER_FOR_M;
bool visited[MAX_SIZE][MAX_SIZE];
char campus[MAX_SIZE][MAX_SIZE];

int x, y;

void input();
void solve();
void dfs(int x, int y);
bool isWall(int x, int y);
bool isFriend(int x, int y);
bool isDoyeon(int x, int y);
bool isInRange(int x, int y);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;  

  ITER_FOR_N = n;
  ITER_FOR_M = m;

  string temp;

  for(int i = 0; i < ITER_FOR_N; ++i) {
    cin >> temp;

    for(int j = 0; j < ITER_FOR_M; ++j) {
      campus[i][j] = temp[j];

      if (isDoyeon(i,j)) {
        x = i;
        y = j;
      }
    }
  }

  return; 
}

void solve() { 
  dfs(x,y);

  if (!numberOfPeopleMet) {
    cout << FAIL_TO_MEET;
  } else {
    cout << numberOfPeopleMet;
  }

  return; 
}

void dfs(int x, int y) {
  if(isFriend(x,y)) {
    numberOfPeopleMet += 1;
  }

  visited[x][y] = true;

  int nx,ny;
  for(int i = 0; i < 4; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if(!isInRange(nx,ny)) {
      continue;
    }

    if(isWall(nx,ny)){
      continue;
    }

    if(visited[nx][ny]) {
      continue;
    }

    dfs(nx,ny);
  }

  return;
}

bool isWall(int x, int y) {
  return campus[x][y] == 'X';
}

bool isFriend(int x, int y) {
  return campus[x][y] == 'P';
}

bool isDoyeon(int x, int y) {
  return campus[x][y] == 'I';
}

bool isInRange(int x, int y) {
  if (x < 0 || y < 0) {
    return false;
  }

  if (x >= n || y >= m) {
    return false;
  }

  return true;
}

