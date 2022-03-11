#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
const int INF = 1000000003;

void input();
void solve();

int n, k;
int dp[2][1001][1001];
bool isLastSelected = true;

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
  if(now <= 0) return 0;
  if(left == 1) return now == 1 ? !isLastSelected : 1;
  if(dp[isLastSelected][now][left]) return dp[isLastSelected][now][left];

  int val = 0;
  for(int i = now - 2; i > 0; --i) {
    val += dfs(i, left - 1);
  }
  dp[isLastSelected][now][left] = val % INF;

  return dp[isLastSelected][now][left];
}

void solve() {
  ll val = 0;
  for(int i = n; i > 0; --i) {
    val += dfs(i, k);
    isLastSelected = false;
  }
  cout << val % INF;

  return;
}
