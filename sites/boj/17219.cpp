#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, string> idPasswordMap;
int n, m;
string siteList[100000];

void input();
void solve();

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;

  string id, password;
  for(int i = 0; i < n; ++i) {
    cin >> id >> password;

    idPasswordMap.insert({id, password});
  }

  for(int i = 0; i < m; ++i) {
    cin >> siteList[i];
  }

  return; 
}

void solve() { 
  for(int i = 0; i < m; ++i) {
    auto iter = idPasswordMap.find(siteList[i]);

    if(iter != idPasswordMap.end()) {
      cout << iter->second << '\n';
    }
  }

  return; 
}
