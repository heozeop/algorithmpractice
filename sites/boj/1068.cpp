#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> parent[51];
int leafCnt, rootIdx;

void input();
void solve();
void dfs(int cur);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  int p;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    if (p == -1) {
      rootIdx = i;
      continue;
    }

    parent[p].push_back(i);
  }

  cin >> m;
  return;
}

void solve() {
  if (rootIdx == m) {
    cout << 0;
    return;
  }

  dfs(rootIdx);
  cout << leafCnt;

  return;
}

void dfs(int cur) {
  bool isChildrenExist = false;

  for (int i : parent[cur]) {
    if (i == m) {
      continue;
    }

    dfs(i);
    isChildrenExist = true;
  }

  if (!isChildrenExist) {
    leafCnt += 1;
  }
}
