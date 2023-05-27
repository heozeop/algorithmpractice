#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 201;

void input();
void solve();
int find();
void merging(int, int);

int n, m;
int arr[LIMIT_NODE_COUNT];
vector<int> target;

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

  int connection = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> connection;
      if (connection) {
        merging(i, j);
      }
    }
  }

  int temp = 0;
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    target.push_back(temp);
  }
  return;
}

int find(int a) {
  if (a == arr[a]) {
    return a;
  }

  return arr[a] = find(arr[a]);
}

void merging(int a, int b) {
  int aP = find(a);
  int bP = find(b);

  arr[aP] = arr[bP];
}

void solve() {
  int a, b;

  for (int i = 1; i < target.size(); ++i) {
    a = target[i - 1];
    b = target[i];

    if (find(a) != find(b)) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
  return;
}
