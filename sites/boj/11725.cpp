#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> tree[100001];
int parents[100001];
int n;

void bfs() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int currNode = q.front();
    q.pop();

    for (int i = 0; i < tree[currNode].size(); ++i) {
      int nextNode = tree[currNode][i];
      if (parents[nextNode])
        continue;
      parents[nextNode] = currNode;
      q.push(nextNode);
    }
  }
  return;
}

int main(void) {
  cin >> n;
  int a, b;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &a, &b);
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  bfs();
  for (int i = 2; i <= n; ++i) {
    printf("%d\n", parents[i]);
  }
  return 0;
}
