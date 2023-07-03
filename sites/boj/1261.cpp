#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int INF = 123456789;
const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

const int MAX_N = 100;
const int WALL = 1;

struct Info {
  int x, y, sum;
};

int n, m;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void input();
void solve();
void minDFS(int x, int y, int breaks);
bool isInArea(int x, int y);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> m >> n;
  char temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> temp;
      arr[i][j] = temp - '0';
    }
  }
  return;
}

void solve() {
  deque<Info> q;
  q.push_back({0,0,0});
  visited[0][0] = true;

  while(!q.empty()) {
    auto cur = q.front();
    q.pop_front();

    int x = cur.x;
    int y = cur.y;
    int sum = cur.sum;

    if (x == n - 1 && y == m - 1) {
      cout << sum;
      break;
    }

    int nx,ny;
    for(int i = 0; i < 4; ++i) {
      nx = x + DIRECTION[i][0];
      ny = y + DIRECTION[i][1];
      if (!isInArea(nx,ny)) {
        continue;
      }

      if(visited[nx][ny]) {
        continue;
      }

      visited[nx][ny] = true;
      if(arr[nx][ny] == WALL) {
        q.push_back({nx,ny,sum + 1});
      } else {
        q.push_front({nx, ny, sum});
      }
    }
  }
}

bool isInArea(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
