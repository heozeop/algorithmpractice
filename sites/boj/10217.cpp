#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int COST_LIMIT =  10001;
const int NODE_LIMIT = 101;

int testcases;
int n, m, k;
vector<pair<int,int> > flyTime[NODE_LIMIT];
vector<pair<int,int> > flyCost[NODE_LIMIT];
int minTimes[NODE_LIMIT][COST_LIMIT];

void init(int n, int m) {
  fill(&minTimes[1][0], &minTimes[n][m] + 1, INF);
  for(int i = 1; i <= n; ++i) {
    flyTime[i].clear();
    flyCost[i].clear();
  }
}

void input() {
  cin >> n >> m >> k;

  init(n, m);

  int u,v,c,d;
  for(int i = 0; i < k; ++i) {
    cin >> u >> v >> c >> d;
    flyTime[u].push_back(make_pair(v,d));
    flyCost[u].push_back(make_pair(v,c));
  }
}

int bellmanFord() {
  bool updated;
  vector<int> cost(n + 1, INF);

  cost[1] = 0;
  minTimes[1][cost[1]] = 0;

  for(int i = 0; i < n - 1; ++i) {
    updated = false;

    for(int cur = 1; cur <= n; ++cur) {
      int currentMinTimeCost = cost[cur];

      if(currentMinTimeCost > m) continue;
      if(minTimes[cur][currentMinTimeCost] == INF) continue;

      for(int j = 0; j < flyTime[cur].size(); ++j) {
        int nextNode = flyTime[cur][j].first;
        int nextTime =  minTimes[cur][currentMinTimeCost] + flyTime[cur][j].second;
        int nextCost =  currentMinTimeCost + flyCost[cur][j].second;

        if(nextCost > m) continue;
        if(minTimes[nextNode][nextCost] >= nextTime) {
          minTimes[nextNode][nextCost] = nextTime;
          if(cost[nextNode] > nextCost) {
            cost[nextNode] = nextCost;
          }
          updated = true;
        }
      }
    }

    if(!updated) break;
  }

  if(cost[n] > m) {
    return INF;
  }

  return minTimes[n][cost[n]];
}

void print(int timeVal) {
  if(timeVal < 0 || timeVal >= INF) {
    cout << "Poor KCM\n";
    return;
  }

  cout << timeVal << "\n";
}

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cin >> testcases;

  while(testcases--) {
    input();
    print(bellmanFord());
  }

  return 0;
}
