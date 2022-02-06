#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int LIMIT_NODE = 100001;
const int END = -1;

void init();
void input();
void solve();

ll v, sum;
int endNode;
bool visited[LIMIT_NODE];
vector<pair<int, int> > tree[LIMIT_NODE];


int main(void) {
  input();
  solve();
  return 0;
}

void init() {
  sum = 0;
  fill(&visited[0], &visited[LIMIT_NODE] + 1, false);
  for(auto node : tree) {
    node.clear();
  }
  return;
}

void input() {
  cin >> v;
  int from, to, val;
  while(v--) {
    cin >> from;

    do {
      cin >> to;
      if(to == END) {
        break;
      }

      cin >> val;
      tree[from].push_back(make_pair(to, val));
    } while(1);
  }
  return;
}

void dfs(int curNode, int curVal) {
  if(visited[curNode]) return;
  visited[curNode] = true;

  if(sum < curVal) {
    sum = curVal;
    endNode = curNode;
  }

  for(auto nextNode : tree[curNode]) {
    dfs(nextNode.first, curVal + nextNode.second);
  }

  return;
}

void solve() {
  dfs(1, 0);
  init();
  dfs(endNode, 0);
  cout << sum << endl;
  return;
}
