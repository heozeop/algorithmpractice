#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <string>
#include <set>

using namespace std;

set<string> a;
int n, m;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;

  string temp;
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    
    a.insert(temp);
  }
  return;
}

void solve() {

  string temp;
  vector<string> tt;
  for(int i = 0; i < m; ++i) {
    cin >> temp;
    if (a.find(temp) != a.end()) {
      tt.push_back(temp);
    }
  }

  sort(tt.begin(), tt.end());

  cout << tt.size() << '\n';
  for(int i = 0; i < tt.size(); ++i) {
    cout << tt[i] << '\n';
  }

  return;
}
