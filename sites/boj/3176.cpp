#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int INF = 1000001;
const int LIMIT_NODE_COUNT = 100001;
const int TREE_HEIGHT = 18;

void input();
void solve();

int n, k;
vector<pair<int,int> > roads[LIMIT_NODE_COUNT];
int depth[LIMIT_NODE_COUNT];
int dp[LIMIT_NODE_COUNT][TREE_HEIGHT];
int dp_max[LIMIT_NODE_COUNT][TREE_HEIGHT];
int dp_min[LIMIT_NODE_COUNT][TREE_HEIGHT];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  int a,b, c;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    roads[a].push_back({b,c});
    roads[b].push_back({a,c});
  }
  return;
}

void dfs(int cur, int p) {
  for(auto i : roads[cur]) {
    if(i.first != p) {
      dp[i.first][0] = cur;
      dp_max[i.first][0] = dp_min[i.first][0] = i.second;
      depth[i.first] = depth[cur] + 1;
      dfs(i.first, cur);
    }
  }
}

void setDP() {
  memset(dp_min, INF, sizeof(dp_min));
  dfs(1,0);

  for(int i = 1; i < TREE_HEIGHT; i++) {
    for(int j = 1; j <= n; j++) {
      if(dp[j][i-1]) {
        dp[j][i] = dp[dp[j][i-1]][i-1];
        dp_max[j][i] = max(dp_max[dp[j][i-1]][i-1], dp_max[j][i-1]);
        dp_min[j][i] = min(dp_min[dp[j][i-1]][i-1], dp_min[j][i-1]);
      }
    }
  }
}

pair<int,int> findMinMax(int a, int b) {
  int maxVal = 0;
  int minVal = INF;

  // leveling
  if(depth[a] > depth[b]) {
    swap(a,b);
  }
  int diff = depth[b] - depth[a];

  for(int i = 0; diff; i++) {
    if(diff & 1) {
      minVal= min(minVal, dp_min[b][i]);
      maxVal = max(maxVal, dp_max[b][i]);

      b = dp[b][i];
    }

    diff >>= 1;
  }

  // finding
  if(a != b) {
    for(int i = TREE_HEIGHT - 1; i >= 0; i--) {
      if(dp[a][i] && dp[a][i] != dp[b][i]) {
        minVal= min(minVal, dp_min[a][i]);
        minVal= min(minVal, dp_min[b][i]);
        maxVal = max(maxVal, dp_max[a][i]);
        maxVal = max(maxVal, dp_max[b][i]);
        a = dp[a][i];
        b = dp[b][i];
      }
    }
    minVal= min(minVal, dp_min[a][0]);
    minVal= min(minVal, dp_min[b][0]);
    maxVal = max(maxVal, dp_max[a][0]);
    maxVal = max(maxVal, dp_max[b][0]);
  }


  return {minVal, maxVal};
}

void printMinMax(int a, int b) {
  auto minMax = findMinMax(a,b);
  cout << minMax.first << " " << minMax.second << '\n';
}

void solve() {
  setDP();

  cin >> k;
  int a, b;
  while(k--) {
    cin >> a >> b;
    printMinMax(a,b);
  }
  return;
}
