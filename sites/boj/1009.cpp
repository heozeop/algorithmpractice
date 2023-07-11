#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int t;

void input();
void solve();

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
  while (t--) {
    long long a, b;
    cin >> a >> b;

    long long c = 1;
    while (b--) {
      c *= a;
      c %= 10;
    }

    if (c == 0) {
      cout << 10;
    } else {
      cout << c;
    }
    cout << '\n';
  }

  return;
}
