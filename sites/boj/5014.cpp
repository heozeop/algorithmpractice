#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000001;

int f, s, g, u, d;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> f >> s >> g >> u >> d;
  return;
}

void solve() {
  vector<bool> visited(f + 1, false);
  queue<pair<int, int>> q;
  q.push({s, 0});
  visited[s] = true;

  while (!q.empty()) {
    auto temp = q.front();
    q.pop();

    if (temp.first == g) {
      cout << temp.second;
      return;
    }

    int next = temp.first - d;
    if (next > 0 && !visited[next]) {
      visited[next] = true;
      q.push({next, temp.second + 1});
    }

    next = temp.first + u;
    if (next <= f && !visited[next]) {
      visited[next] = true;
      q.push({next, temp.second + 1});
    }
  }

  cout << "use the stairs";
  return;
}
