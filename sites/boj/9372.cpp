#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int n, m, t;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void solve() {
  int a, b;
  while (t--) {
    cin >> n >> m;
    while (m--) {
      cin >> a >> b;
    }

    cout << n - 1 << '\n';
  }
  return;
}
