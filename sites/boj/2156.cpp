#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  int n;
  int amount[10001];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d ", amount + i);
  }

  int dp[10001] = {0, amount[1], amount[1] + amount[2]};
  int lagest = 0;
  for (int i = 3; i <= n; i++) {
    int firstCase = dp[i - 3] + amount[i - 1] + amount[i];
    int secondCase = dp[i - 2] + amount[i];
    int thirdCase = dp[i - 1];

    dp[i] = max(firstCase, max(secondCase, thirdCase));
  }

  cout << dp[n];
}