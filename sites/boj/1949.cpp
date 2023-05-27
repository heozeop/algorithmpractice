#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 10001;

void input();
void solve();

int n;
int population[LIMIT_NODE_COUNT];
vector<int> tree[LIMIT_NODE_COUNT];
int dp[LIMIT_NODE_COUNT][2];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> population[i];
  }
  int a, b;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  return;
}

int findDp(int prevNode, int curNode, bool selected) {
  if (dp[curNode][selected] > 0) {
    return dp[curNode][selected];
  }

  int sum = selected ? population[curNode] : 0;
  for (int i = 0; i < tree[curNode].size(); i++) {
    if (tree[curNode][i] == prevNode)
      continue;
    if (selected) {
      sum += findDp(curNode, tree[curNode][i], !selected);
    } else {
      sum += max(findDp(curNode, tree[curNode][i], selected),
                 findDp(curNode, tree[curNode][i], !selected));
    }
  }

  dp[curNode][selected] = sum;
  return sum;
}

void solve() {
  int a = findDp(0, 1, true);
  int b = findDp(0, 1, false);
  cout << max(a, b);
  return;
}
