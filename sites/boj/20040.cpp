#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 500001;

void input();
void solve();
int find(int a);
void merge(int a, int b);

int n, m, cPoint;
int nodes[LIMIT_NODE_COUNT];

int main(void) {
  input();
  solve();
  return 0;
}

int find(int a) {
  if (nodes[a] == a) {
    return a;
  }

  return nodes[a] = find(nodes[a]);
}

void merge(int a, int b) {
  int aP = find(a);
  int bP = find(b);
  nodes[aP] = nodes[bP];
}

void input() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    nodes[i] = i;
  }

  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);

    if (find(a) == find(b)) {
      cPoint = i + 1;
      break;
    }
    merge(a, b);
  }
  return;
}

void solve() {
  cout << cPoint << endl;
  return;
}
