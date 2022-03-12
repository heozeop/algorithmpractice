#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int n;
int dp[31];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void solve() {
  dp[0] = 1;
  dp[2] = 3;
  for(int i = 4; i <= n; i+=2) {
    dp[i] = 3 * dp[i - 2];

    for(int j = i - 4; j >= 0; j -= 2){
      dp[i] += 2 * dp[j];
    }
  }
  cout << dp[n]<< endl;
  return;
}
