#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

const int DIRECTION[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
};

int space[21][21];
bool visited[21][21];
int n;
int sAte, sSize;
pair<int, int> sPos;
int moveTime;
struct compare {
  bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.first != b.first) {
      return a.first > b.first;
    }

    if (a.second.first != b.second.first) {
      return a.second.first > b.second.first;
    }

    return a.second.second > b.second.second;
  }
};

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> space[i][j];

      if (space[i][j] == 9) {
        sPos = make_pair(i, j);
      }
    }
  }
  return;
}

void solve() {
  bool isSharkAte = true;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 compare>
      q;
  int nx, ny, nf;
  sSize = 2;

  while (isSharkAte) {
    isSharkAte = false;
    memset(visited, false, sizeof(visited));
    while (!q.empty()) {
      q.pop();
    }

    q.push({0, sPos});
    visited[sPos.first][sPos.second] = true;
    while (!q.empty() && !isSharkAte) {
      auto temp = q.top();
      q.pop();
      nx = temp.second.first;
      ny = temp.second.second;
      nf = space[nx][ny];

      if (nf != 0 && nf != 9 && sSize > nf) {
        moveTime += temp.first;
        visited[nx][ny] = true;
        space[sPos.first][sPos.second] = 0;
        space[nx][ny] = 9;
        sPos = make_pair(nx, ny);
        sAte += 1;
        if (sSize == sAte) {
          sSize = min(sSize + 1, 7);
          sAte = 0;
        }
        isSharkAte = true;
        break;
      }

      for (int i = 0; i < 4; ++i) {
        nx = temp.second.first + DIRECTION[i][0];
        ny = temp.second.second + DIRECTION[i][1];
        if (nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny]) {
          continue;
        }

        nf = space[nx][ny];
        if (sSize < nf) {
          continue;
        }
        visited[nx][ny] = true;
        q.push({temp.first + 1, {nx, ny}});
      }
    }
  }

  cout << moveTime;
  return;
}
