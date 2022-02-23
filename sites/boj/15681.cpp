#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 100001;

void input();
void solve();

int n, r, q;
vector<int> graph[LIMIT_NODE_COUNT];
int numOfChildren[LIMIT_NODE_COUNT];
bool visited[LIMIT_NODE_COUNT];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> r >> q;

  int a, b;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return;
}

int dfs(int nextNode) {
  visited[nextNode] = true;
  if(graph[nextNode].size() == 0) {
    return 1;
  }

  int localNum = 0;
  for(int i = 0; i < graph[nextNode].size(); ++i) {
    int child = graph[nextNode][i];
    if(!visited[child]) {
      int numOfGrandChildren = dfs(graph[nextNode][i]);

      localNum += numOfGrandChildren;
    }
  }

  numOfChildren[nextNode] = localNum + 1;
  if(localNum == 0) {
    return 1;
  }

  return localNum + 1;
}

void solve() {
  dfs(r);
  int nQ;
  while(q--) {
    cin >> nQ;
    cout << numOfChildren[nQ] << '\n';
  }

  return;
}
