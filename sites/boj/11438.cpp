#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<assert.h>
using namespace std;

void input();
void solve();

int n, m;
vector<int> tree[100001];
int ptree[100001][19];
int depth[100001];
bool visited[100001];


int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  int a,b;
  for(int i = 0; i< n - 1; i++) {
    cin >> a >> b;

    tree[b].push_back(a);
    tree[a].push_back(b);
  }
  return;
}

void initPtree(int cur){
  visited[cur] = true;
  if(tree[cur].empty()) return;
  for(int i : tree[cur]) {
    if(visited[i] == false) {
      depth[i] = depth[cur] + 1;
      ptree[i][0] = cur;
      initPtree(i);
    }
  }
}

void setPTree() {
  initPtree(1);
  for(int i = 1; i <= 18; i++) {
    for(int j = 1; j <= n; j++) {
      ptree[j][i] = ptree[ptree[j][i-1]][i-1];
    }
  }
}

pair<int,int> levelingTwo(int a,int b) {
  int small = a, big = b;
  if(depth[small] > depth[big]) {
    swap(small, big);
  }

  int diff = depth[big] - depth[small];
  for(int i = 0; diff; i++) {
    if(diff & 1) {
      big = ptree[big][i];
    }
    diff >>= 1;
  }

  return {small, big};
}

int findP(int ta, int tb) {
  if(ta == tb) return tb;

  for(int i = 18; i >= 0; i--) {
    if(ptree[ta][i] && ptree[ta][i] != ptree[tb][i]) {
      ta = ptree[ta][i];
      tb = ptree[tb][i];
    }
  }

  return ptree[ta][0];
}

void solve() {
  setPTree();

  cin >> m;
  int a, b;
  while(m--) {
    cin >> a >> b;
    auto level = levelingTwo(a,b);
    int foundP = findP(level.first, level.second);
    cout << foundP << '\n';
  }

  return;
}
