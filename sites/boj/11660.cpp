#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int table[1024][1024];
int operationList[100000][4];
long long dp[1024][1024];
int n, m;

void input();
void solve();
void setDP();
long long getSum(int);

int main(void) {
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> table[i][j];
    }
  }

  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < 4; ++j) {
      cin >> operationList[i][j];
    }
  }

  return;
}

void solve() {
  setDP();
  long long foundSum ;
  for(int i = 0; i < m; ++i) {
    foundSum = getSum(i);
    cout << foundSum << '\n';
  }

  return;
}

void setDP() {
  dp[0][0] = table[0][0];
  for(int i = 1; i < n; ++i) {
    dp[i][0] = table[i][0] + dp[i-1][0];
    dp[0][i] = table[0][i] + dp[0][i-1];
  }

  for(int i = 1; i < n; ++i) {
    for(int j = 1; j < n; ++j) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + table[i][j];
    }
  }
}

long long getSum(int operationIndex) {
  int x1,x2,y1,y2;
  x1 = operationList[operationIndex][0] - 1;
  y1 = operationList[operationIndex][1] - 1;
  x2 = operationList[operationIndex][2] - 1;
  y2 = operationList[operationIndex][3] - 1;

  long long sum = dp[x2][y2];
  if (y1 - 1 >= 0) {
    sum -= dp[x2][max(0, y1-1)];
  }
  if (x1 -1 >= 0) {
    sum-= dp[max(0, x1-1)][y2];
  }

  if (y1 - 1 >= 0 && x1 -1 >= 0) {
    sum += dp[max(0, x1 - 1)][max(0, y1-1)];
  }

  return sum;
}
