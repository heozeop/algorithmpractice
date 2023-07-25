#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 501;

vector<int> v[MAX_N];
int buildTime[MAX_N];

int n;

void input();
void solve();

int dfs(int, vector<bool> &visited);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> buildTime[i];

    int temp;
    while (1) {
      cin >> temp;

      if (temp == -1) {
        break;
      }

      v[i].push_back(temp);
    }
  }

  return;
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    vector<bool> visited(n, 0);

    cout << dfs(i, visited) << endl;
  }

  return;
}

int dfs(int curIdx, vector<bool> &visited) {
  int buildTimeOfCurIdx = buildTime[curIdx];

  if (v[curIdx].size() < 1) {
    return buildTimeOfCurIdx;
  }

  for (int i = 0; i < v[curIdx].size(); ++i) {
    int nextIdx = v[curIdx][i];
    if (visited[nextIdx]) {
      continue;
    }
    visited[nextIdx] = true;

    buildTimeOfCurIdx += dfs(nextIdx, visited);
  }

  return buildTimeOfCurIdx;
}
