#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

const char WALL = '#';
const char MOVABLE_SPACE = '.';
const char JIHOON_LOCATION = 'J';
const char FIRE_LOCATION = 'F';
const int MAX_SIZE = 1000;

char MIRO[MAX_SIZE][MAX_SIZE];
int r,c;
int jx,jy;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> r >> c;

  for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      cin >> MIRO[i][j];
      if(MIRO[i][j] == JIHOON_LOCATION) {
        jx = i;
        jy = j;
      }
    }
  }

  return; 
}

void setFire(vector<pair<int,int>>& fire) {
  int x,y, nx,ny;
  int popSize = fire.size();
  for(int i = 0; i < popSize; ++i) {
    x = fire[i].first;
    y = fire[i].second;
    for(int j = 0; j < 4; ++j) {
      nx = x + DIRECTION[j][0];
      ny = y + DIRECTION[j][1];

      if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
        continue;
      }

      if (MIRO[nx][ny] == MOVABLE_SPACE || MIRO[nx][ny] == JIHOON_LOCATION) {
        MIRO[nx][ny] = FIRE_LOCATION;
        fire.push_back({nx,ny});
      }
    }
  }

  fire.erase(fire.begin(), fire.begin() + popSize);
}

void solve() { 
  int curMinute = 0;

  vector<pair<int,int>> fire;
  for(int i = 0; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      if(MIRO[i][j] == FIRE_LOCATION) {
        fire.push_back({i,j});
      }
    }
  }

  vector<vector<bool>> visited(r, vector<bool>(c,false));
  queue<pair<int,pair<int,int>>> q;
  q.push({1, {jx,jy}});

  while(!q.empty()) {

    if(curMinute < q.front().first) {
      setFire(fire);
      curMinute += 1;
    }

    jx = q.front().second.first;
    jy = q.front().second.second;
    q.pop();

    int nx,ny;
    for(int i = 0; i < 4; ++i) {
      nx = jx + DIRECTION[i][0];
      ny = jy + DIRECTION[i][1];

      if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
        cout << curMinute;
        return;
      }

      if (MIRO[nx][ny] != MOVABLE_SPACE) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = true;

      q.push({curMinute + 1, {nx,ny}});
    }
  }

  cout << "IMPOSSIBLE";
  return; 
}
