#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int dp[5003];
int visited[5003];
const int NO_CHECK = -1;
const int UN_CHECK = 0;
const int CHECKED = 1;
int n, k, q, m, s, e;

int main(void) {
  cin.tie(nullptr);

  input();
  solve();
  return 0;
}

void setMultiplicity(int start, int limit) {
  if (visited[start] != NO_CHECK) {
    for (int i = start; i <= limit + 2; i += start) {
      if (visited[i] != NO_CHECK) {
        visited[i] = CHECKED;
      }
    }
  }
}

void input() {
  cin >> n >> k >> q >> m;
  int temp;
  for (int i = 0; i < k; ++i) {
    cin >> temp;
    visited[temp] = NO_CHECK;
  }

  for (int i = 0; i < q; ++i) {
    cin >> temp;
    setMultiplicity(temp, n);
  }

  return;
}

void setDP() {
  for (int i = 3; i <= n + 2; ++i) {
    dp[i] = dp[i - 1] + (visited[i] != CHECKED);
  }
}

void solve() {
  setDP();

  for (int i = 0; i < m; ++i) {
    cin >> s >> e;
    cout << dp[e] - dp[s - 1] << '\n';
  }
  return;
}
