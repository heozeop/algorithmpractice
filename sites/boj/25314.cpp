#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void solve() {
  int s = n / 4;
  if (n % 4 > 0) {
    s += 1;
  }

  for (int i = 0; i < s; ++i) {
    cout << "long ";
  }
  cout << "int";
  return;
}
