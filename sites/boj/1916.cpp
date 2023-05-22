#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 100000;

int dp[MAX_N];
vector<pair<int,int>> buses[MAX_N];

int n, m;
int startP, endP;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;


  int from, to, cost;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &from, &to, &cost);
    buses[from - 1].push_back({to - 1, cost});
  }

  scanf("%d %d", &startP, &endP);
  startP -= 1;
  endP -= 1;

  for(int i = 0; i < n; ++i) {
    dp[i] = INT_MAX;
  }

  return;
}

void dijkstra() {
  priority_queue<pair<int, int>> q;
  q.push({0, startP});
  dp[startP] = 0;

  int current, distance;
  while(!q.empty()) {
    distance = -q.top().first;
    current = q.top().second;
    q.pop();

    if(dp[current] < distance) {
      continue;
    }

    int nd, np;
    for(int i = 0; i < buses[current].size(); ++i) {
      np = buses[current][i].first;
      nd = distance + buses[current][i].second;

      if (dp[np] <= nd) {
        continue;
      }

      dp[np] = nd;
      q.push({nd * -1, np});
    }
  }
  
}


void solve() {
  dijkstra();  
  cout << dp[endP];

  return;
}
