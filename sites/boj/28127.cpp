#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int a, d, x, q;

void input();
void solve();

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> q;
  return;
}

void calc() {
  int cur = a;
  int row = 1;

  while (cur < x) {
    cur += a + row * d;
    row += 1;
  }

  int col = cur - a - (row - 1) * d;
  cout << row << " " << x - col << "\n";
}

void solve() {
  while (q--) {
    cin >> a >> d >> x;
    calc();
  }

  return;
}
