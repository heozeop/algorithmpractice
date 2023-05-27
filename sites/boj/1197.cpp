#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> pfii;
const int LIMIT_NODE_COUNT = 10001;

void input();
void solve();

int v, e;
priority_queue<pfii, vector<pfii>, greater<pfii>> graph;
int minSpanningTree;
int list[LIMIT_NODE_COUNT];
int length[LIMIT_NODE_COUNT];
int cost[LIMIT_NODE_COUNT];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> v >> e;
  int a, b, c;
  while (e--) {
    cin >> a >> b >> c;
    graph.push(make_pair(c, make_pair(a, b)));
  }

  for (int i = 1; i <= v; ++i) {
    list[i] = i;
  }
  return;
}

int findParent(int a) {
  if (list[a] == a) {
    return a;
  }

  return list[a] = findParent(list[a]);
}

int merge(int a, int b) {
  int aP = findParent(a);
  int bP = findParent(b);
  if (aP != bP) {
    list[aP] = bP;
    length[aP] += length[bP];
    return length[aP];
  }
  return -1;
}

void solve() {
  pfii temp;
  int result;

  while (!graph.empty() || result >= v) {
    temp = graph.top();
    graph.pop();
    result = merge(temp.second.first, temp.second.second);
    if (result != -1) {
      minSpanningTree += temp.first;
    }
  }

  cout << minSpanningTree << endl;

  return;
}
