#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int INF = 123456789;

int n, startColor;
int house[1000][3];
int dp[3][1000][3];

void input();
void solve();

int main(void) {
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> house[i][j];
    }
  }

  return;
}

int dfs(int now, int color) {
  if(now >= n) return 0;
  if(now == n - 1 && color == startColor) return INF;
  if(dp[startColor][now][color]) return dp[startColor][now][color];

  int val = INF;
  for(int i = 0; i < 3; i++) {
    if(color == i) continue;

    val = min(val, dfs(now + 1, i) + house[now][color]);
  }

  if(!dp[startColor][now][color] || dp[startColor][now][color] > val) {
    dp[startColor][now][color] = val;
  }

  return dp[startColor][now][color];
}

void solve() {
  int val = INF;
  for(startColor = 0; startColor < 3; startColor++) {
    val = min(val, dfs(0, startColor));
  }

  cout << val;
  return;
}
