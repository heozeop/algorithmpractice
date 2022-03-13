#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int t, n, k, w;
int cost[1001];
vector<long long> order[1001];
int inComming[1001];
int dp[1001];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void init() {
  for(int i = 1; i <= n; i++) {
    cost[i] = dp[i] = inComming[i] = 0;
    order[i].clear();
  }
}

long long bfs() {
  long long val = 0;
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(inComming[i] == 0) {
      q.push(i);
      dp[i] = cost[i];
    }
  }

  while(!q.empty()) {
    int now = q.front();
    q.pop();

    if(now == w) break;

    for(int next : order[now]) {
      if(--inComming[next] == 0) {
        q.push(next);
      }
      if(dp[next] < cost[next] + dp[now]) {
        dp[next] = cost[next] + dp[now];
      }
    }
  }

  return dp[w];
}

void solve() {
  while(t--) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
      cin >> cost[i];
    }
    int a,b;
    for(int i = 0; i < k; i++) {
      cin >> a >> b;
      order[a].push_back(b);
      inComming[b]++;
    }
    cin >> w;
    cout << bfs() << "\n";

    init();
  }
  return;
}
