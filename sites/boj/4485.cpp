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
const int MAX_N = 125;
const int INF = 123456789;

int n;
int arr[MAX_N][MAX_N];

void input();
void solve();
int bfs();
bool init();
bool isInArea(int,int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { return; }

void solve() {
  for (int i = 1; init(); ++i) {
    cout << "Problem " << i << ": " << bfs() << '\n';
  }

  return;
}

bool init() {
  cin >> n;
  if (n == 0) {
    return false;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  return true;
}

int bfs() {
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
  visited[0][0] = true;
  q.push({arr[0][0], {0,0}});
  
  while(!q.empty()) {
    auto temp = q.top();
    q.pop();

    int w = temp.first;
    int x = temp.second.first;
    int y = temp.second.second;

    if(x == n - 1 && y == n-1) {
      return w;
    }

    int nx, ny;
    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];

      if(!isInArea(nx,ny)) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = true;

      q.push({w + arr[nx][ny], {nx, ny}});
    }
     
  }

  return -1;
}

bool isInArea(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n;
}
