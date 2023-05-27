#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
int t, n;
int tree[10001];
int A, B;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void init(int n) {
  fill(&tree[0], &tree[n + 1], 0);
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tree[b] = a;
  }
  cin >> A >> B;
}

vector<int> getToRootPath(int a) {
  vector<int> toRoot;
  while (a != 0) {
    toRoot.push_back(a);
    a = tree[a];
  }
  reverse(toRoot.begin(), toRoot.end());
  return toRoot;
}

void printNCA(vector<int> a, vector<int> b) {
  int localMax = max(a.size(), b.size());
  for (int i = 0; i < localMax; i++) {
    if (a[i] != b[i]) {
      cout << a[max(i - 1, 0)] << '\n';
      break;
    }
  }
}

void solve() {
  while (t--) {
    cin >> n;
    init(n);
    auto fromA = getToRootPath(A);
    auto fromB = getToRootPath(B);
    printNCA(fromA, fromB);
  }
  return;
}
