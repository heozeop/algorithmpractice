#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int LIMIT_NODE_COUT = 501;

int n, m, numOfTrees, c;
vector<int> tree[LIMIT_NODE_COUT];
bool visited[LIMIT_NODE_COUT];

void input();
void init();
void solve();
bool dfs();
void printPrompt();

int main(void) {
  while(1){
    c++;
    cin >> n >> m;
    if(n == 0 && m == 0) {
      break;
    }

    init();
    input();
    solve();
  }
  return 0;
}

void init() {
  numOfTrees = 0;
  for(int i = 1; i <= n; ++i) {
    tree[i].clear();
  }
  fill(&visited[0], &visited[n] + 1, false);
}

void input() {
  int a,b;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  return;
}

bool dfs(int curNode, int prevNode) {
  visited[curNode] = true;

  int nextNode;
  for(int i = 0; i < tree[curNode].size(); ++i) {
    nextNode = tree[curNode][i];
    if(nextNode == prevNode) continue;
    if(visited[nextNode]) return false;
    if(!dfs(nextNode, curNode)) return false;
  }

  return true;
}

void printPrompt() {
  string text;
  if(numOfTrees == 0) {
    text = "No trees.";
  } else if(numOfTrees == 1) {
    text = "There is one tree.";
  } else {
    text = "A forest of " + to_string(numOfTrees) + " trees.";
  }
  cout << "Case " << c << ": " << text << endl;
}

void solve() {
  for(int i = 1; i <= n; ++i) {
    if(visited[i]) continue;
    if(dfs(i, 0)) {
      numOfTrees++;
    }
  }

  printPrompt();

  return;
}
