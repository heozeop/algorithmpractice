#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
const int MAX_N = 102;

int dp[MAX_N][MAX_N][MAX_N];
int a,b,c;


int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  return;
}

void solve() {
  for(int i = 0; i <= 50; ++i) {
    for(int j = 0; j < MAX_N; ++j) {
      for(int k = 0; k < MAX_N; ++k) {
        dp[i][j][k] = 1;
        dp[j][i][k] = 1;
        dp[j][k][i] = 1;
      }
    }
  }

  for(int i = 51; i <= 70; ++i) {
    for(int j = 51; j <= 70; ++j) {
      for(int k = 51; k <= 70; ++k) {
        if (i < j && j < k) {
          dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
        } else {
          dp[i][j][k] = dp[i - 1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
        }
      }
    }
  }

  for(int i = 71; i < MAX_N; ++i) {
    for(int j = 51; j < MAX_N; ++j) {
      for(int k = 51; k < MAX_N; ++k) {
        dp[i][j][k] = dp[70][70][70];
        dp[j][i][k] = dp[70][70][70];
        dp[j][k][i] = dp[70][70][70];
      }
    }
  }

  while(1) {
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1) {
      break;
    }

    cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a + 50][b + 50][c + 50] << '\n';
  }

  return;
}
