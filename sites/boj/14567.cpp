#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_M = 500001;
const int MAX_N = 1001;
int n, m;
vector<int> edges[MAX_M];
int inDegree[MAX_N];
int dp[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    edges[a].push_back(b);
    ++inDegree[b];
  }
  return; 
}

void solve() { 
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(inDegree[i] != 0) {
      continue;
    }

    q.push(i);
    dp[i] = 1;
  }

  while(!q.empty()){
    int temp = q.front();
    q.pop();

    for(int i : edges[temp]) {
      if(--inDegree[i] == 0) {
        q.push(i);
        dp[i] = dp[temp] + 1;
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    cout << dp[i] << " ";
  }
  
  return; 
}
