#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, pair<int,int>> piii;
const int MAX_N = 100001;

int n, m;
priority_queue<piii, vector<piii>, greater<piii>> q;
int parent[MAX_N];

void input();
void solve();
int findParent(int);
void join(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;
  int x,y,c;
  for(int i = 0; i < m; ++i) {
    cin >> x >> y >> c;
    q.push({c, {x, y}});
  }

  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

    return; 
}

void solve() { 
  int longest = 0, sum = 0;
  int x, y, c;
  while(!q.empty()) {
    piii temp = q.top();
    q.pop();
    c = temp.first;
    x = temp.second.first;
    y = temp.second.second;

    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp) {
      continue;
    }

    join(x, y);
    sum += c;
    longest = max(longest, c);
  }

  cout << sum - longest;

  return; 
}

int findParent(int x) {
  if(parent[x] == x) {
    return x;
  }

  return parent[x] = findParent(parent[x]);
}

void join(int a, int b) {
  int ap = findParent(a);
  int bp = findParent(b);

  parent[ap] = bp;
}
