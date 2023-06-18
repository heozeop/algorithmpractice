#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;
const int MAX_N = 1001;

int n, m;
set<int> arr[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;

  int temp, prevOne, nextOne;
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    cin >> prevOne;

    for (int j = 0; j < temp - 1; ++j) {
      cin >> nextOne;
      arr[nextOne].insert(prevOne);
      prevOne = nextOne;
    }
  }

  return;
}

void solve() {
  queue<int> emptyList;
  vector<bool> visited(n, false);
  vector<int> ansList;

  for (int i = 1; i <= n; ++i) {
    if (!arr[i].empty()) {
      continue;
    }

    emptyList.push(i);
    visited[i] = true;
  }

  while (!emptyList.empty()) {
    int popTarget = emptyList.front();
    emptyList.pop();

    for (int i = 1; i <= n; ++i) {
      if (visited[i]) {
        continue;
      }

      arr[i].erase(popTarget);
      if (arr[i].empty()) {
        visited[i] = true;
        emptyList.push(i);
      }
    }

    ansList.push_back(popTarget);
  }

  for (int i = 1; i <= n; ++i) {
    if (!arr[i].empty()) {
      cout << 0;
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ansList[i] << '\n';
  }

  return;
}
