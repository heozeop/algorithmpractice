#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MAX_NODE_NUM = 200001;

void input();
void solve();

int m;
int dp[MAX_NODE_NUM][22];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> dp[i][0];
  }
  return;
}

void setDP() {
  for(int i = 1; i < 22; ++i) {
    for(int j = 1; j <= m; ++j) {
      dp[j][i] = dp[dp[j][i - 1]][i - 1];
    }
  }
}

void solve() {
  setDP();

  int q, n, x;
  cin >> q;
  while(q--) {
    cin >> n >> x;

    for(int i=0; n; i++){
      if(n & 1) {
        x = dp[x][i];
      }
      n >>= 1;
    }

    cout << x << '\n';
  }

  return;
}
