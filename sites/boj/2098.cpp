#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int INF = 123456789;

void input();
void solve();

int n;
int city[20][20];
long long dp[20][1 << 16];

int main(void) {
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> city[i][j];
    }
  }
  return;
}

long long dfs(int now, unsigned int visited) {
  if(now >= n) return 0;
  if(visited == ((1 << n) - 1)) return city[now][0] != 0 ? city[now][0] : INF;
  if(dp[now][visited]) return dp[now][visited];

  long long val = INF;
  for(int i = 0; i < n; ++i) {
    if(!city[now][i] || visited & (1 << i)) continue;

    val = min(val, city[now][i] + dfs(i, visited + (1 << i)));
  }

  if(!dp[now][visited] || dp[now][visited] > val) {
    dp[now][visited] = val;
  }

  return dp[now][visited];
}

void solve() {
  cout << dfs(0, 1);
  return;
}
