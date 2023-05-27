#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int LIMIT_NODE = 10002;
const int VISITED = 1;
const int NOT_VISITED = 0;

int n, sum, fatNode;
int visited[LIMIT_NODE];
vector<pair<int, int>> tree[LIMIT_NODE];

void initConditions() {
  sum = 0;
  fill(&visited[0], &visited[LIMIT_NODE], NOT_VISITED);
  return;
}

void dfs(int curNode, int len) {
  if (visited[curNode] == VISITED)
    return;
  visited[curNode] = VISITED;

  if (sum < len) {
    sum = len;
    fatNode = curNode;
  }

  int nextNode, nextWeight;
  for (int i = 0; i < tree[curNode].size(); ++i) {
    nextNode = tree[curNode][i].first;
    nextWeight = tree[curNode][i].second + len;
    dfs(nextNode, nextWeight);
  }
  return;
}

int main(void) {
  cin >> n;
  int pN, cN, val;
  n--;
  while (n--) {
    cin >> pN >> cN >> val;
    tree[pN].push_back(make_pair(cN, val));
    tree[cN].push_back(make_pair(pN, val));
  }

  dfs(1, 0);

  initConditions();

  dfs(fatNode, 0);
  cout << sum;

  return 0;
}
