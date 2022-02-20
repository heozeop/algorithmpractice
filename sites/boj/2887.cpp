#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct Links {
  int cost, from, to;
  Links(int cost, int from, int to):cost(cost), from(from), to(to) {}
  bool operator <  (const Links& A) const { return cost < A.cost; }
};

const int LIMIT_NODE_COUNT = 100003;

void input();
void solve();

int n;
pii x[LIMIT_NODE_COUNT], y[LIMIT_NODE_COUNT], z[LIMIT_NODE_COUNT];
int ternal[LIMIT_NODE_COUNT];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
	ios_base::sync_with_stdio(false);
  cin >> n;
  int a,b,c;
  for(int i = 1; i <= n; ++i) {
    cin >> a >> b >> c;
    x[i] = {a, i};
    y[i] = {b, i};
    z[i] = {c, i};
    ternal[i] = i;
  }
  return;
}

int find(int a) {
  if(ternal[a] == a) {
    return a;
  }

  return ternal[a] = find(ternal[a]);
}

bool merge(int a, int b) {
  int ap = find(a);
  int bp = find(b);
  if(ap != bp) {
    ternal[ap] = bp;
    return true;
  }

  return false;
}

void solve() {
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + n);
  sort(z + 1, z + 1 + n);

  vector<Links> q;
  for(int i = 1; i < n; i++) {
    q.push_back(Links(x[i+1].first - x[i].first, x[i].second, x[i+1].second));
    q.push_back(Links(y[i+1].first - y[i].first, y[i].second, y[i+1].second));
    q.push_back(Links(z[i+1].first - z[i].first, z[i].second, z[i+1].second));
  }
  sort(q.begin(), q.end());
  
  int count = 0;
  long long sum = 0;
  for(int i = 0; i < q.size(); i++) {
    if(count == n - 1) break;

    if(merge(q[i].from, q[i].to)) {
      sum += q[i].cost;
      count += 1;
    }
  }

  cout << sum;
  return;
}
