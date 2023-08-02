#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 51;
const int D[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

vector<pair<int, int>> virus;
int emptySpaceSize = 0;
bool selected[10];
int arr[MAX_N][MAX_N];
int n, m;

void input();
void solve();
int backtrack(int i, int curM);
int minVal();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        emptySpaceSize += 1;
      }

      if (arr[i][j] == 2) {
        virus.push_back({i, j});
      }
    }
  }

  return;
}

void solve() {
  if (virus.size() < 1) {
    cout << 0;
    return;
  }

  int minTime = backtrack(0, 0);

  if (minTime == INT_MAX) {
    cout << -1;
  } else {
    cout << minTime;
  }

  return;
}

int backtrack(int i, int curM) {
  if (curM == m) {
    return minVal();
  }

  int localMinVal = INT_MAX;
  for (; i < virus.size(); ++i) {
    if (selected[i]) {
      continue;
    }

    selected[i] = true;
    localMinVal = min(localMinVal, backtrack(i, curM + 1));
    selected[i] = false;
  }

  return localMinVal;
}

int minVal() {
  queue<pair<int, int>> q;
  vector<vector<int>> visited(n, vector<int>(n, -1));

  for (int i = 0; i < virus.size(); ++i) {
    if (selected[i]) {
      q.push(virus[i]);
      visited[virus[i].first][virus[i].second] = 0;
    }
  }

  int sum = 0;
  int time = 0;

  while (!q.empty()) {
    auto temp = q.front();
    q.pop();
    int x = temp.first;
    int y = temp.second;

    if (sum == emptySpaceSize) {
      return time;
    }

    int nx, ny;
    for (int i = 0; i < 4; ++i) {
      nx = x + D[i][0];
      ny = y + D[i][1];

      if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
        continue;
      }

      if (arr[nx][ny] == 1) {
        continue;
      }

      if (visited[nx][ny] != -1) {
        continue;
      }
      visited[nx][ny] = visited[x][y] + 1;

      if (arr[nx][ny] == 0) {
        sum += 1;
        time = visited[nx][ny];
      }

      q.push({nx, ny});
    }
  }

  return INT_MAX;
}
