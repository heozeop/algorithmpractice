#include <algorithm>
#include <climits>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int tc;

void input();
void solve();
void testCase();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> tc;
  return;
}

void solve() { 
  for(int i = 0; i < tc; ++i) {
    testCase();
  }
  return; 
}

void testCase() {
  int n,m,w,s,e,t;

  cin >> n >> m >> w;

  vector<vector<int>> v(n + 1, vector<int>(n + 1, INT_MAX));

  for(int i = 0; i < m; ++i) {
    cin >> s >> e >> t;

    v[s][e] = min(t, v[s][e]);
    v[e][s] = v[s][e];
  }

  for(int i = 0; i < w; ++i) {
    cin >> s >> e >> t;

    v[s][e] = -t;
  }

  for(int k = 1; k <= n; ++k) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        if(v[i][k] == INT_MAX) {
          continue;
        }
        
        if (v[k][j] == INT_MAX) {
          continue;
        }

        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
      if (v[i][i] < 0) {
        cout << "YES\n";
        return;
      }
  }

  cout << "NO\n";
  return;
}

