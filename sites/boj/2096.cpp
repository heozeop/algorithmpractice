#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 100000;

int arr[MAX_N][3];
int dp[6];

int n;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;

  for(int i = 0; i < n; ++i) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  return; 
}

void solve() { 
  // max
  for(int i = 0; i < 6; ++i) {
    dp[i] = arr[0][i];
    dp[i] = arr[0][i%3];
  }

  int a,b,c;
  for(int i = 1; i < n; ++i) {
    a = dp[0], b = dp[1], c = dp[2];
    dp[0] = max(a, b) + arr[i][0]; 
    dp[1] = max(max(a,b), c) + arr[i][1]; 
    dp[2] = max(b,c) + arr[i][2]; 

    a = dp[3], b = dp[4], c = dp[5];
    dp[3] = min(a,b) + arr[i][0]; 
    dp[4] = min(min(a,b), c) + arr[i][1]; 
    dp[5] = min(b,c) + arr[i][2]; 
  }

  cout << max(max(dp[0], dp[1]), dp[2]) << " ";
  cout << min(min(dp[3], dp[4]), dp[5]);

  return; 
}
