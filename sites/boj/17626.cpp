#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;
int n;
int dp[50001];

void input();
void solve();

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
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 1;

  float temp, flooredTemp;
  for(int i = 5; i <= n; ++i) {
    temp = sqrt(i);
    flooredTemp = floor(temp);
    if(flooredTemp == temp) {
      dp[i] = 1;
      continue;
    } 

    
    dp[i] = 5;
    for(int j = (int)(ceil(sqrt(flooredTemp))); j <= flooredTemp && dp[i] > 2; ++j) {
      dp[i] = min(1 + dp[i - (int)pow(j, 2)], dp[i]);
    }
  }
  cout << dp[n];

  return;
}
