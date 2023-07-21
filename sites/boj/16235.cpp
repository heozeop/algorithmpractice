#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int DIRECTION[8][2] = {
  {0,1},
  {0,-1},
  {1,1},
  {-1,1},
  {-1,-1},
  {1,-1},
  {-1,0},
  {1,0},
};
const int MAX_N = 11;

int n, m, k;
int arr[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
priority_queue<pair<int, pair<int,int>>> q;

void input();
void solve();
void springSummerFall();
void winter();
void printTrees();
bool isInArea(int,int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m >> k;

  for(int i = 1; i <= n; ++i) {
    for(int j= 1; j <= n; ++j) {
      arr[i][j] = 5;
      cin >> a[i][j];
    }
  }

  int x,y,k;
  for(int i = 0; i < m; ++i) {
    cin >> x >> y >> k;
    q.push({k, {x,y}});
  }
  

  return; 
}

void solve() { 
  while(k--) {
    springSummerFall();
    winter();
  }

  printTrees();
  return; 
}

void springSummerFall() {
  vector<pair<int,pair<int,int>>> normal;
  vector<pair<int,pair<int,int>>> died;
  vector<pair<int,pair<int,int>>> grow;

  // spring
  int x, y, k;
  while(!q.empty()) {
    auto temp = q.top();
    q.pop();

    k = temp.first;
    x = temp.second.first;
    y = temp.second.second;
    
    if(arr[x][y] < k) {
      died.push_back({k, {x, y}});
      continue;
    }

    arr[x][y] -= k;
    if((k + 1) % 5 == 0) {
      grow.push_back({k + 1, {x, y}});
    } else {
      normal.push_back({k + 1, {x, y}});
    }
  }

  for(auto temp : normal) {
    q.push(temp);
  }

  // summer
  for(auto temp : died) {
    k = temp.first;
    x = temp.second.first;
    y = temp.second.second;

    arr[x][y] += k / 2;
  }

  // fall
  for(auto temp : grow) {
    q.push(temp);

    int nx, ny;
    for(int i = 0; i < 8; ++i) {
      nx = temp.second.first + DIRECTION[i][0];
      ny = temp.second.second + DIRECTION[i][1];

      if(!isInArea(nx, ny)) {
        continue;
      }

      q.push({1, {nx, ny}});
    }
  }
}

void winter() {
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      arr[i][j] += a[i][j];
    }
  }
}

void printTrees() {
  cout << q.size();
}

bool isInArea(int x, int y) {
  return x > 0 && y > 0 && x <= n && y <= n;
}

