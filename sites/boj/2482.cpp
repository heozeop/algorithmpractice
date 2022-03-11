#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1000000003;

void input();
void solve();

int n, k;
int dp[1001][1001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  return;
}

int dfs(int now, int left) {
  if(now <= 0 || now < left * 2) return 0;
  if(left == 1) return now;
  if(dp[now][left]) return dp[now][left];
  return dp[now][left] = (dfs(now - 1,left) + dfs(now - 2,left - 1)) % INF;
}

void solve() {
  cout << dfs(n, k);
  return;
}
