#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

const int MAX_N = 100001;
int sticker[2][MAX_N];
int dp[2][MAX_N];
int n, t;

void input();
void solve();
void getMap(int);
int getMaxScore();
void cleanResource();

int main(void) {
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

void solve() {
  for(int i = 0; i < t; ++i) {
    cin >> n;
    getMap(n);
    cout << getMaxScore() << '\n';
  }

  return;
}

void getMap(int n) {
  for(int i = 0; i < 2; ++i) {
    for(int j = 1; j <= n; ++j) {
      cin >> sticker[i][j];
    }
  }
}

int getMaxScore() {
  dp[0][0] = dp[1][0] = 0;
  dp[0][1] = sticker[0][1];
  dp[1][1] = sticker[1][1];

  for(int i = 2; i <= n; ++i) {
    dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
    dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
  }

  return max(dp[0][n], dp[1][n]);
}
