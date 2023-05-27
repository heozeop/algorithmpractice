#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_NODE = 500 + 2;

int n, m;
bool isNegativeCycle = false;
vector<pair<int, int>> cities[MAX_NODE];

void init() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    cities[a].push_back(make_pair(b, c));
  }
}

vector<long long> setMinByBellmanFord() {
  vector<long long> upper(n + 2, INF);
  upper[1] = 0;
  bool updated;

  for (int i = 0; i < n; ++i) {
    updated = false;
    for (int j = 1; j <= n; ++j) {
      if (upper[j] == INF) {
        continue;
      }
      for (int k = 0; k < cities[j].size(); ++k) {
        int next = cities[j][k].first;
        int cost = cities[j][k].second;

        if (upper[next] > upper[j] + cost) {
          upper[next] = upper[j] + cost;
          updated = true;
        }
      }
    }

    if (!updated) {
      break;
    }
  }

  if (updated) {
    isNegativeCycle = true;
    upper.clear();
  }

  return upper;
}

int main(void) {
  init();
  vector<long long> minCost = setMinByBellmanFord();
  if (isNegativeCycle) {
    cout << "-1\n";
  } else {
    for (int i = 2; i <= n; ++i) {
      if (minCost[i] >= 900000000) {
        cout << "-1\n";
      } else {
        cout << minCost[i] << "\n";
      }
    }
  }
  return 0;
}