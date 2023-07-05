#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int a, b, c;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> a >> b >> c;
  return;
}

void solve() {
  cout << a + b + c;
  return;
}
