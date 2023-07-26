#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 10001;

int n;
int inDegree[MAX_N];
vector<int> edges[MAX_N];
int arr[MAX_N];
int dp[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;
  int a,b,c;
  for(int i = 1; i <= n; ++i) {
    cin >> arr[i] >> b;

    while(b--) {
      cin >> c; 
      
      edges[c].push_back(i);
      ++inDegree[i];
    }
  }
  return; 
}

void solve() { 
  queue<int> q;
  for(int i = 1; i <= n; ++i){
    if(inDegree[i] > 0){
      continue;
    }

    q.push(i);
    dp[i] = arr[i];
  }

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int i : edges[cur]) {
      if (--inDegree[i] == 0) {
        q.push(i);
      }

      dp[i] = max(dp[i], dp[cur] + arr[i]);
    }
  }

  int maxVal = 0;
  for(int i = 1; i <= n; ++i) {
    maxVal = max(maxVal, dp[i]);
  }
  cout << maxVal;

  return; 
}
