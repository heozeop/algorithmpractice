#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

int n;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void solve() {
  bitset<21> bs;
  string op;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == "all") {
      bs.set();
    } else if (op == "empty") {
      bs.reset();
    } else {
      cin >> val;
      if (op == "add") {
        bs.set(val);
      }
      if (op == "remove") {
        bs.reset(val);
      }
      if (op == "check") {
        cout << bs.test(val) << '\n';
      }
      if (op == "toggle") {
        bs.flip(val);
      }
    }
  }
  return;
}
