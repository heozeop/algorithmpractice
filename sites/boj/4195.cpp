#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 200001;

void input();
void init();
void solve();

int n, f;

int connected[LIMIT_NODE_COUNT];
int nodes[LIMIT_NODE_COUNT];

int main(void) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void init() {
  for (int i = 0; i < LIMIT_NODE_COUNT; ++i) {
    nodes[i] = i;
    connected[i] = 1;
  }
}

int find(int a) {
  if (a == nodes[a]) {
    return a;
  }

  return nodes[a] = find(nodes[a]);
}

int merge(int a, int b) {
  int aP = find(a);
  int bP = find(b);

  int big, small;
  if (connected[aP] < connected[bP]) {
    big = bP;
    small = aP;
  } else {
    big = aP;
    small = bP;
  }

  if (aP == bP) {
    return connected[big];
  }

  connected[big] += connected[small];
  nodes[small] = big;

  return connected[big];
}

void solve() {
  string a, b;
  while (n--) {
    cin >> f;

    map<string, int> nameIdMap;
    int friendId = 1;

    init();

    while (f--) {
      cin >> a >> b;

      if (nameIdMap.count(a) == 0) {
        nameIdMap[a] = friendId++;
      }

      if (nameIdMap.count(b) == 0) {
        nameIdMap[b] = friendId++;
      }

      cout << merge(nameIdMap[a], nameIdMap[b]) << '\n';
    }
  }
  return;
}
