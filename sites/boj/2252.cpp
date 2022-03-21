#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int n,m;
vector<int> line[32001];
int degree[32001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  int a,b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    line[a].push_back(b);
    degree[b]++;
  }
  return;
}

void solve() {
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(degree[i] == 0) q.push(i);
  }

  while(!q.empty()) {
    int val = q.front();
    q.pop();

    cout << val << " ";
    for (int i : line[val]) {
      if (--degree[i] == 0) q.push(i);
    }
  }
  
  return;
}
