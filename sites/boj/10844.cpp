#include <iostream>
using namespace std;

const long long DELEMETER = 1000000000;

long long dp[101][11];

void setDP() {
  for (int i = 2; i <= 10; i++) {
    dp[1][i] = 1;
  }
}

int getN(int n) {
  if (n == 1)
    return 9;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 10; j++) {
      dp[i][j] =
          ((dp[i - 1][j + 1] % DELEMETER) + (dp[i - 1][j - 1] % DELEMETER)) %
          DELEMETER;
    }
  }

  long long answer = 0;
  for (int i = 1; i <= 10; i++) {
    answer += dp[n][i];
    answer %= DELEMETER;
  }

  return answer;
}

int main(void) {
  setDP();
  int n;
  cin >> n;
  cout << getN(n);
}