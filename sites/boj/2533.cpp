#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 1000001;

void input();
void solve();

int n;
vector<int> tree[LIMIT_NODE_COUNT];
int dp[LIMIT_NODE_COUNT][2];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  return;
}

int findDp(int curNode, bool selected, int prevNode) {
  int sum = selected;
  if (dp[curNode][selected] > 0) {
    return dp[curNode][selected];
  }

  for (int i = 0; i < tree[curNode].size(); i++) {
    if (tree[curNode][i] == prevNode)
      continue;
    if (selected) {
      sum += min(findDp(tree[curNode][i], !selected, curNode),
                 findDp(tree[curNode][i], selected, curNode));
    } else {
      sum += findDp(tree[curNode][i], !selected, curNode);
    }
  }

  if (dp[curNode][selected] > 0) {
    dp[curNode][selected] = min(sum, dp[curNode][selected]);
  } else {
    dp[curNode][selected] = sum;
  }

  return sum;
}

void printMax() { cout << min(dp[1][0], dp[1][1]) << '\n'; }

void solve() {
  findDp(1, true, 0);
  findDp(1, false, 0);
  printMax();
  return;
}
