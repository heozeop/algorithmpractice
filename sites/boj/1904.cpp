#include <iostream>
using namespace std;

int dp[1000001] = {0, 1, 2, 3};

int main(void) {
  int n;
  cin >> n;

  if (n < 4) {
    cout << dp[n];
    return 0;
  }

  for (int i = 4; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }
  cout << dp[n];
  return 0;
}