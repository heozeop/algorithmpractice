#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 1000001;
const int UNION = 0;
const int FIND = 1;

void input();
void solve();

int n, m;
int arr[LIMIT_NODE_COUNT];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    arr[i] = i;
  }
  return;
}

int findParent(int a) {
  if (arr[a] == a) {
    return a;
  }

  return arr[a] = findParent(arr[a]);
}

void unionNode(int a, int b) {
  int aParent = findParent(a);
  int bParent = findParent(b);
  arr[aParent] = arr[bParent];
}

void printResult(bool result) {
  if (result) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

void solve() {
  int val, a, b;
  while (m--) {
    scanf("%d %d %d", &val, &a, &b);

    if (val == UNION) {
      unionNode(a, b);
    } else {
      printResult(findParent(a) == findParent(b));
    }
  }
  return;
}
