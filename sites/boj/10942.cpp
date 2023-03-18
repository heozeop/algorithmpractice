#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
const int MAX_N = 2001;

void input();
void solve();

int n, m;
int arr[MAX_N];
int dp[MAX_N][MAX_N];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &m);

  return;
}

void solve() {
  dp[1][1] = 1;
  for(int e = 2; e <= n; ++e) {
    dp[e][e] = 1;
    for(int s = e - 1; s > 0; --s) {
      if(arr[s] == arr[e]) {
        if(s+1 == e) {
          dp[s][e] = 1;
        } else {
          dp[s][e] = dp[s+1][e-1];
        }
      } else {
        dp[s][e] = 0;
      }
    }
  }

  int s,e;
  for(int i = 0; i < m; ++i) {
    scanf("%d %d", &s, &e);
    printf("%d\n", dp[s][e]);
  }
  return;
}
