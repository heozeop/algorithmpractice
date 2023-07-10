#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int h, m, t;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> h >> m >> t;
  return;
}

void solve() {
  m += t;

  h += m / 60;
  m = m % 60;
  h %= 24;

  cout << h << " " << m;
  return;
}
