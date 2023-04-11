#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;

typedef long long ll;
const int DIRECTION[4][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
};

void input();
void solve();

int sr,sc,er,ec;
int n;
ll board[21][21];
ll maxVal;
bool merged[21][21];
void choice(int moveCount, vector<vector<ll>> map, int curD);
void move(int curD, vector<vector<ll>>& map);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  return;
}

void solve() {
  vector<vector<ll>> temp(n+1, vector<ll>(n+1));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      temp[i][j] = board[i][j];
    }
  }
  choice(0, temp, 0);
  cout << maxVal;

  return;
}


void choice(int moveCount, vector<vector<ll>> map, int curD) {
  if(moveCount > 5) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        maxVal = max(maxVal, map[i][j]);
      }
    }
    return;
  }

  if (moveCount > 0) {
    move(curD, map);
  }

  for(int i = 0; i < 4; ++i) {
    choice(moveCount + 1, map, i);
  }
}

void getPointByDirection(int curD,int i) {
  switch(curD) {
      case 0: 
        er = 1;
        ec = i;
        sr = 2;
        sc = i;
        break;
      case 1:
        er = i;
        ec = n;
        sr = i;
        sc = n-1;
        break;
      case 2:
        er = n;
        ec = i;
        sr = n-1;
        sc = i;
        break;
      case 3:
        er = i;
        ec = 1;
        sr = i; 
        sc = 2;
        break;
    }
}

bool isStartPointInRange() {
  return sc> 0 && sr > 0 && sc <= n && sr <= n;
}

bool isEndPointInRange() {
  return  ec > 0 && er > 0 && ec <= n && er <= n;
}

bool isPointInRange() {
  return isStartPointInRange() && isEndPointInRange();
}

bool isStartAndEndStickTogether(int curD) {
  return sr == (er - DIRECTION[curD][0]) && sc == (ec - DIRECTION[curD][1]);
}

void move(int curD, vector<vector<ll>>& map) {
  memset(merged, 0, sizeof(merged));

  for(int i = 1; i <= n; ++i) {
    getPointByDirection(curD, i);

    while(isPointInRange()) {
      while(isStartPointInRange() && !map[sr][sc]) {
        sr -= DIRECTION[curD][0];
        sc -= DIRECTION[curD][1];
      }

      if(!isStartPointInRange()) {
        break;
      }

      if(map[er][ec] == 0) {
        map[er][ec] = map[sr][sc];
        map[sr][sc] = 0;
      } else if(map[sr][sc] == map[er][ec] && !merged[er][ec]) {
        merged[er][ec] = true;
        map[er][ec] *= 2;
        map[sr][sc] = 0;
      } else if (isStartAndEndStickTogether(curD)) {
        er -= DIRECTION[curD][0];
        ec -= DIRECTION[curD][1];
        sr -= DIRECTION[curD][0];
        sc -= DIRECTION[curD][1];
      } else {
        er -= DIRECTION[curD][0];
        ec -= DIRECTION[curD][1];
        map[er][ec] = map[sr][sc];
        map[sr][sc] = 0;
      }
    }
  }
}