#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,ll> ii_pair;

const int MAX_NODE_NUM = 100000;
const int DEPTH_LIMIT = 18;

int n, m;
vector<ii_pair> nodes[MAX_NODE_NUM + 1]; 
int dp[MAX_NODE_NUM + 1][DEPTH_LIMIT];
ll values[MAX_NODE_NUM + 1];
bool visited[MAX_NODE_NUM + 1];
int depth[MAX_NODE_NUM + 1];

void input();
void solve();
void dfs(int);
void setDP();
int lca(int, int);
ll fOp(int, int, int);
ll sOp(int, int, int, int);

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
  ll a,b,c;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    nodes[a].push_back({b,c});
    nodes[b].push_back({a,c});
  }
  cin >> m;
  return;
}

void dfs(int curNode) {
  visited[curNode] = true;
  for(auto nNode : nodes[curNode]) {
    if(!visited[nNode.first]) {
      dp[nNode.first][0] = curNode;
      values[nNode.first] = values[curNode] + nNode.second;
      depth[nNode.first] = depth[curNode] + 1;
      dfs(nNode.first);
    }
  }
}

void setDP() {
  depth[1] = 0;
  values[1] = 0;
  dfs(1);
  for(int i = 1; i < DEPTH_LIMIT; ++i) {
    for(int j = 1; j <= n; ++j) {
      dp[j][i] = dp[dp[j][i-1]][i - 1];
    }
  }
}

int lca(int a, int b) {
  int start = a, end = b;
  if (depth[start] > depth[end]) {
    swap(start, end);
  }
  int diff = depth[end] - depth[start];
  for(int i = 0; diff; ++i, diff >>= 1) {
    if(diff & 1) {
      end = dp[end][i];
    }
  }

  if(start == end) {
    return start;
  }

  for(int i = DEPTH_LIMIT - 1; i >= 0; --i) {
    if(dp[start][i] != dp[end][i]) {
      start = dp[start][i];
      end = dp[end][i];
    }
  }

  return dp[start][0];
}

ll fOp(int a, int b, int c) {
  return values[a] + values[b] - 2 * values[c];
}

ll sOp(int a, int b, int c, int k) {
  int start = a;
  int middle = depth[a] - depth[c] + 1;

  if(middle == k) {
    return c;
  }

  if(middle < k) {
    start = b;
    k = depth[b] - depth[c] - (k - middle);
  } else {
    k--;
  }
  
  for(int i = 0; k; ++i, k >>= 1) {
    if(k & 1) {
      start = dp[start][i];
    }
  }

  return start;
}

void solve() {
  setDP();
  while(m--) {
    int op, u, v, l, k;
    cin >> op;
    if(op == 1) {
      cin >> u >> v;
      l = lca(u, v);
      cout << fOp(u,v,l) << '\n';
    } else {
      cin >> u >> v >> k;
      l = lca(u,v);
      cout << sOp(u,v,l,k) << '\n';
    }
  }
  return;
}
