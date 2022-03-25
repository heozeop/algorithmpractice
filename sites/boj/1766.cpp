#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int LIMIT_NODE_COUNT = 32001;

void input();
void solve();

int n, m;
vector<int> nodes[LIMIT_NODE_COUNT];
int priority[LIMIT_NODE_COUNT];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  int a,b;
  while(m--) {
    cin >> a >> b;
    nodes[a].push_back(b);
    priority[b]++;
  }
  return;
}

void solve() {
  priority_queue<int, vector<int>, greater<int> > q;
  for(int i=1; i<=n; i++) {
    if(priority[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    int t = q.top();
    q.pop();

    cout << t << " ";
    for(int i : nodes[t]) {
      if(--priority[i] == 0) {
        q.push(i);
      }
    }
  }

  return;
}
