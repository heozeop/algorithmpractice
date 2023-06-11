#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

bool visited[200001];
int parent[200001];
int n, k;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  return;
}

void solve() {
  queue<pair<int, int>> q;
  vector<int> path;
  q.push({0, n});

  int currentN, second;
  while (!q.empty()) {
    auto temp = q.front();
    q.pop();

    second = temp.first;
    currentN = temp.second;

    if (currentN == k) {
      break;
    }

    visited[currentN] = true;

    int nextN = currentN * 2;
    if (nextN <= 2 * k && !visited[nextN]) {
      q.push({second + 1, nextN});
      visited[nextN] = true;
      parent[nextN] = currentN;
    }

    nextN = currentN - 1;
    if (nextN >= 0 && !visited[nextN]) {
      q.push({second + 1, nextN});
      visited[nextN] = true;
      parent[nextN] = currentN;
    }

    nextN = currentN + 1;
    if (nextN <= 2 * k && !visited[nextN]) {
      q.push({second + 1, nextN});
      visited[nextN] = true;
      parent[nextN] = currentN;
    }
  }

  cout << second << '\n';

  int prev = k;
  while (prev != n) {
    path.push_back(prev);
    prev = parent[prev];
  }
  cout << n;
  for (int i = path.size() - 1; i >= 0; --i) {
    cout << " " << path[i];
  }

  return;
}
