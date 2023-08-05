#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int x, n, sum;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> x >> n;

  int a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    sum += a * b;
  }
  return;
}

void solve() {
  if (sum == x) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return;
}
