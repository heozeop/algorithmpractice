#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int t, n;
int pairs[501][501];
int edges[501];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void topological() {
  queue<int> q;
  vector<int> order;
  for (int i = 1; i <= n; i++) {
    if (edges[i] == 0) {
      q.push(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (q.empty()) {
      cout << "IMPOSSIBLE";
      return;
    }

    if (q.size() > 1) {
      cout << "?";
      return;
    }

    int cur = q.front();
    q.pop();
    order.push_back(cur);

    for (int j = 1; j <= n; j++) {
      if (pairs[cur][j] == 0)
        continue;
      if (--edges[j] == 0) {
        q.push(j);
      }
    }
  }

  for (int i : order) {
    cout << i << " ";
  }
}

void solve() {
  while (t--) {
    int m;
    cin >> n;
    memset(edges, 0, sizeof(edges));
    memset(pairs, 0, sizeof(pairs));
    vector<int> orders(n + 1);
    int prev = 0;
    for (int i = 1; i <= n; i++) {
      cin >> orders[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        pairs[orders[i]][orders[j]] = 1;
        edges[orders[j]]++;
      }
    }
    cin >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      if (pairs[a][b] == 1) {
        pairs[a][b] = 0;
        pairs[b][a] = 1;
        edges[a]++;
        edges[b]--;
      } else {
        pairs[a][b] = 1;
        pairs[b][a] = 0;
        edges[a]--;
        edges[b]++;
      }
    }

    topological();
    cout << '\n';
  }
  return;
}
