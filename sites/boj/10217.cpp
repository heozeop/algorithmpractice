#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int COST_LIMIT = 10001;
const int NODE_LIMIT = 101;

int testcases;
int n, m, k;
vector<pair<int, int>> flyTime[NODE_LIMIT];
vector<pair<int, int>> flyCost[NODE_LIMIT];
int minTimes[NODE_LIMIT][COST_LIMIT];

typedef struct _port {
  int to;
  int cost;
  int time;
  bool operator()(struct _port a, struct _port b) {
    return a.time > b.time || (a.time == b.time && a.cost > b.cost);
  }
} port;

void init(int n, int m) {
  fill(&minTimes[1][0], &minTimes[n][m] + 1, INF);
  for (int i = 1; i <= n; ++i) {
    flyTime[i].clear();
    flyCost[i].clear();
  }
}

void input() {
  cin >> n >> m >> k;

  init(n, m);

  int u, v, c, d;
  for (int i = 0; i < k; ++i) {
    cin >> u >> v >> c >> d;
    flyTime[u].push_back(make_pair(v, d));
    flyCost[u].push_back(make_pair(v, c));
  }
}

int dijkstra() {
  priority_queue<port, vector<port>, port> minHeap;
  port p = {
    to : 1,
    cost : 0,
    time : 0,
  };
  minHeap.push(p);
  minTimes[1][0] = 0;

  while (!minHeap.empty()) {
    p = minHeap.top();
    minHeap.pop();

    int times = p.time;
    int node = p.to;
    int cost = p.cost;

    for (int i = 0; i < flyTime[node].size(); ++i) {
      int nextNode = flyTime[node][i].first;
      int nextTime = times + flyTime[node][i].second;
      int nextCost = cost + flyCost[node][i].second;

      port tmp = {to : nextNode, cost : nextCost, time : nextTime};

      if (nextCost <= m && minTimes[nextNode][nextCost] > nextTime) {
        minTimes[nextNode][nextCost] = nextTime;
        for (int j = nextCost + 1; j <= m; ++j) {
          if (minTimes[nextNode][j] <= nextTime)
            break;
          minTimes[nextNode][j] = nextTime;
        }
        minHeap.push(tmp);
      }
    }
  }

  int smallest = INF;
  for (int i = 0; i <= m; ++i) {
    if (smallest > minTimes[n][i]) {
      smallest = minTimes[n][i];
    }
  }

  return smallest;
}

void print(int timeVal) {
  if (timeVal < 0 || timeVal >= INF) {
    cout << "Poor KCM\n";
    return;
  }

  cout << timeVal << "\n";
}

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cin >> testcases;

  while (testcases--) {
    input();
    print(dijkstra());
  }

  return 0;
}
