#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1001;

int n, m;
vector<pair<int, pair<int, int>>> q;
int parent[MAX_N];

void input();
void solve();
void join(int a, int b);
int findParent(int a);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;

    q.push_back({c, {a, b}});
  }
  return;
}

void solve() {
  int a, b, c, pa, pb;
  int minWeight = 0;

  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  sort(q.begin(), q.end());

  for (int i = 0; i < m; ++i) {
    a = q[i].second.first;
    b = q[i].second.second;
    c = q[i].first;

    pa = findParent(a);
    pb = findParent(b);

    if (pa == pb) {
      continue;
    }

    join(a, b);
    minWeight += c;
  }

  cout << minWeight;

  return;
}

int findParent(int a) {
  if (a == parent[a]) {
    return a;
  }

  return parent[a] = findParent(parent[a]);
}

void join(int a, int b) {
  int pa, pb;
  pa = findParent(a);
  pb = findParent(b);

  parent[pa] = pb;
}
