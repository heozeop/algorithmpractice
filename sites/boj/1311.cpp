#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 123456789;

void input();
void solve();

int n;
int D[21][21];
int dp[20][1 << 21];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> D[i][j];
    }
  }
  return;
}

int find(int pn, unsigned int workLeft) {
  if (pn >= n || workLeft == ((1 << n) - 1))
    return 0;
  if (dp[pn][workLeft])
    return dp[pn][workLeft];

  int val = INF;
  unsigned int nextLeft;

  for (int i = 0; i < n; i++) {
    if (workLeft & (1 << i))
      continue;

    nextLeft = workLeft + (1 << i);

    val = min(val, find(pn + 1, nextLeft) + D[pn][i]);
  }

  if (!dp[pn][workLeft] || dp[pn][workLeft] > val) {
    dp[pn][workLeft] = val;
  }

  return dp[pn][workLeft];
}

void solve() {
  cout << find(0, 0);
  return;
}
