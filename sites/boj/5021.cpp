#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 50;

map<string, vector<string>> edges;
map<string, int> inDegree;
float blood[MAX_N];
map<string, double> dp;
int n, m;
string king;
string candidates[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  cin >> king;
  string c, f, mo;
  for (int i = 0; i < n; ++i) {
    cin >> c >> f >> mo;
    edges[f].push_back(c);
    edges[mo].push_back(c);

    inDegree[c] += 2;
  }

  for (int i = 0; i < m; ++i) {
    cin >> candidates[i];
  }

  return;
}

void solve() {
  queue<string> q;
  for (auto a : edges) {
    if (inDegree.find(a.first) == inDegree.end() || inDegree[a.first] == 0) {
      q.push(a.first);
    }
  }
  dp[king] = 1;

  while (!q.empty()) {
    string temp = q.front();
    q.pop();

    for (string a : edges[temp]) {
      if (--inDegree[a] == 0) {
        q.push(a);
      }
      dp[a] += dp[temp] / 2;
    }
  }

  int maxIdx = 0;
  double maxVal = 0;
  for (int i = 0; i < m; ++i) {
    if (dp[candidates[i]] > maxVal) {
      maxVal = dp[candidates[i]];
      maxIdx = i;
    }
  }

  cout << candidates[maxIdx];

  return;
}
