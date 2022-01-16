#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 987654321;
const int CITY_NUM_LIMIT = 1000 + 1;

int n,m, s, e;
vector<pair<int, int> > info[CITY_NUM_LIMIT];
int dp[CITY_NUM_LIMIT];
int dpPath[CITY_NUM_LIMIT];

void init();
void input();
void solve();

int main(void) {
  init();
  input();  
  solve();
}

void init() {
  fill(&dp[0], &dp[CITY_NUM_LIMIT - 1] + 1, INF);
}

void input() {
  cin >> n >> m;
  int from, to, cost;
  for(int i = 0 ;i < m;++i) {
    cin >> from >> to >> cost;
    info[from].push_back(make_pair(to, cost));
  }
  cin >> s >> e;
}

void print(int val, vector<int> path) {
  cout << val << endl << path.size() << endl;
  for(int i = path.size() - 1; i >= 0 ; --i) {
    printf("%d ", path[i]);
  }
}

void solve() {
  dp[s] = 0;
  dpPath[s] = 0;
  priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int> >>q;
  q.push(make_pair(0, s));

  while(!q.empty()) {
    int currentCost = q.top().first;
    int currentPosition = q.top().second;
    q.pop();

    if(dp[currentPosition] < currentCost) {
      continue;
    }

    for(int i = 0; i < info[currentPosition].size(); ++i) {
      int nextPosition = info[currentPosition][i].first;
      int visitCost = currentCost + info[currentPosition][i].second;

      if(dp[nextPosition] > visitCost) {
        dp[nextPosition] = visitCost;
        dpPath[nextPosition] = currentPosition;
        q.push(make_pair(visitCost, nextPosition));
      }
    }
  }
  vector<int> targetPath;
  int node = e;
  while(node) {
    targetPath.push_back(node);
    node = dpPath[node];
  }

  print(dp[e], targetPath);
  return;
}